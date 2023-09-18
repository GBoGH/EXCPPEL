/**
 * @author Jakub Feik <feikjaku@fit.cvut.cz>
 * @date 31.05.2023
 */

#include <memory>
#include <stack>

#include "Subtract.hpp"

using namespace std;

Subtract::Subtract() = default;
Subtract::~Subtract() = default;

void Subtract::eval(stack<unique_ptr<Value>> & values) {
    stack_extract(values);
    try {
        values.push(make_unique<Value>(to_string(lhs->get_num() - rhs->get_num())));
    } catch (const invalid_argument & e) {
        throw invalid_argument("Invalid operands for addition");
    }
}

unique_ptr<Operation> Subtract::create_operation() {
    return make_unique<Subtract>();
}