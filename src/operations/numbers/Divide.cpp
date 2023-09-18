/**
 * @author Jakub Feik <feikjaku@fit.cvut.cz>
 * @date 31.05.2023
 */

#include <exception>
#include <memory>
#include <stack>


#include "Divide.hpp"

using namespace std;

Divide::Divide() = default;

Divide::~Divide() = default;

void Divide::eval(stack<unique_ptr<Value>> & values) {
    stack_extract(values);
    try {
        double right = rhs->get_num();
        if (right == 0)
            throw logic_error("Division by zero");
        values.push(make_unique<Value>(to_string(lhs->get_num() / right)));
    } catch (const invalid_argument & e) {
        throw invalid_argument("Invalid operands for division");
    } catch (const logic_error & e) {
        throw invalid_argument("Division by zero");
    }
}

unique_ptr<Operation> Divide::create_operation() {
    return make_unique<Divide>();
}