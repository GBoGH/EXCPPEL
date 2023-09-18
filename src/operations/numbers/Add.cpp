/**
 * @author Jakub Feik <feikjaku@fit.cvut.cz>
 * @date 31.05.2023
 */

#include <memory>
#include <stack>

#include "Add.hpp"

using namespace std;

Add::Add() = default;

Add::~Add() = default;

void Add::eval(stack<unique_ptr<Value>> & values) {
    stack_extract(values);
    try {
        values.push(make_unique<Value>(to_string(lhs->get_num() + rhs->get_num())));
    } catch (const invalid_argument & e) {
        // One  or both of the operands is not a number
        throw invalid_argument("Invalid operands for addition");
    }
}

unique_ptr<Operation> Add::create_operation() {
    return make_unique<Add>();
}