/**
 * @author Jakub Feik <feikjaku@fit.cvut.cz>
 * @date 01.06.2023
 */

#include <memory>
#include <stack>

#include "Negate.hpp"

using namespace std;

Negate::Negate() = default;
Negate::~Negate() = default;

void Negate::eval(stack<unique_ptr<Value>> & values) {
    stack_extract(values, 1);
    try {
        values.push(make_unique<Value>(to_string(-1*lhs->get_num())));
    } catch (const invalid_argument & e) {
        throw invalid_argument("Invalid operands for Negateition");
    }

}

unique_ptr<Operation> Negate::create_operation() {
    return make_unique<Negate>();
}