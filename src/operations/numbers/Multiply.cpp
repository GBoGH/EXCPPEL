/**
 * @author Jakub Feik <feikjaku@fit.cvut.cz>
 * @date 31.05.2023
 */

#include <memory>
#include <stack>

#include "Multiply.hpp"

using namespace std;

Multiply::Multiply() = default;

Multiply::~Multiply() = default;

void Multiply::eval(stack<unique_ptr<Value>> & values) {
    stack_extract(values);
    try {
        values.push(make_unique<Value>(to_string(lhs->get_num() * rhs->get_num())));
    } catch (const invalid_argument & e) {
        throw invalid_argument("Invalid operands for multiplication");
    }
}

unique_ptr<Operation> Multiply::create_operation() {
    return make_unique<Multiply>();
}
