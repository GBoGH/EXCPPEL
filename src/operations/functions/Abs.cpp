/**
 * @author Jakub Feik <feikjaku@fit.cvut.cz>
 * @date 31.05.2023
 */

#include <cmath>
#include <memory>
#include <stack>
#include <string>

#include "Abs.hpp"

using namespace std;

Abs::Abs() = default;
Abs::~Abs() = default;

void Abs::eval(stack<unique_ptr<Value>> & values) {
    stack_extract(values, 1);
    try {
        values.push(make_unique<Value>(to_string(abs(lhs->get_num()))));
    } catch (const invalid_argument & e) {
        throw invalid_argument("Cannot take absolute value of string");
    }
}

unique_ptr<Operation> Abs::create_operation() {
    return make_unique<Abs>();
}