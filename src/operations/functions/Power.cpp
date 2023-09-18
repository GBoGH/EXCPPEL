/**
 * @author Jakub Feik <feikjaku@fit.cvut.cz>
 * @date 31.05.2023
 */

#include <cfenv>
#include <cmath>
#include <memory>
#include <stack>
#include <string>

#include "Power.hpp"

using namespace std;

Power::Power() = default;
Power::~Power() = default;

void Power::eval(stack<unique_ptr<Value>> & values) {
    stack_extract(values);
    try {
        double base = lhs->get_num();
        double exponent = rhs->get_num();
        if (base < 0 && !Utility::is_integer(exponent))
            // Negative base and non-integer exponent are not allowed
            throw invalid_argument("Invalid argument for power");
        double result = pow(base, exponent);
        if (fetestexcept(FE_DIVBYZERO) || fetestexcept(FE_INVALID)) {
            feclearexcept(FE_ALL_EXCEPT);
            // Another mathematical error
            throw invalid_argument("Invalid argument for power");
        }
        values.push(make_unique<Value>(to_string(result)));
    } catch (const invalid_argument & e) {
        throw invalid_argument("Invalid operands for power");
    }
}


unique_ptr<Operation> Power::create_operation() {
    return make_unique<Power>();
}
