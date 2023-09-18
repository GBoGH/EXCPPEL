/**
 * @author Jakub Feik <feikjaku@fit.cvut.cz>
 * @date 31.05.2023
 */

#include <cmath>
#include <memory>
#include <stack>
#include <string>


#include "Root.hpp"
#include "../../utility/Utility.hpp"

using namespace std;

Root::Root() = default;
Root::~Root() = default;

void Root::eval(stack<unique_ptr<Value>> & values) {
    stack_extract(values);
    try {
        double root = lhs->get_num();
        double base = rhs->get_num();
        if (base < 0 && !Utility::is_integer(root)) {
            throw invalid_argument("Cannot take even root of negative number");
        }

        double result;
        if (base < 0) {
            if (!Utility::is_integer(root) || static_cast<int>(root) % 2 == 0) {
                throw invalid_argument("Cannot take even root of negative number");
            }

            // Even root of negative number is okay
            result = -1 * pow(abs(base), 1 / root);
        } else {
            result = pow(base, 1 / root);
        }

        values.push(make_unique<Value>(to_string(result)));
    } catch (const invalid_argument & e) {
        throw invalid_argument("Invalid operands for root");
    }
}


unique_ptr<Operation> Root::create_operation() {
    return make_unique<Root>();
}