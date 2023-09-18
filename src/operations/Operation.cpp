/**
 * @author Jakub Feik <feikjaku@fit.cvut.cz>
 * @date 31.05.2023
 */

#include <iostream>
#include <memory>
#include <stack>
#include <string>


#include "Operation.hpp"

using namespace std;

Operation::Operation() = default;

Operation::~Operation() = default;

void Operation::stack_extract(std::stack<std::unique_ptr<Value>> & values, size_t count /*=2*/) {
    if (values.size() < count) {
        throw std::runtime_error("Not enough values on stack");
    }
    if (count == 1) {
        // Unary operation
        lhs = move(values.top());
        values.pop();
    } else {
        // Binary operation
        rhs = move(values.top());
        values.pop();
        lhs = move(values.top());
        values.pop();
    }
}



