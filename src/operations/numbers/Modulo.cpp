/**
 * @author Jakub Feik <feikjaku@fit.cvut.cz>
 * @date 31.05.2023
 */

#include <cmath>
#include <memory>
#include <stack>

#include "Modulo.hpp"

using namespace std;

Modulo::Modulo() = default;

Modulo::~Modulo() = default;

void Modulo::eval(stack<unique_ptr<Value>> & values) {
    stack_extract(values);
    try {
        double right = rhs->get_num();
        if (right == 0)
            throw invalid_argument("Modulo by zero");
        values.push(make_unique<Value>(to_string(fmod(lhs->get_num(), right))));
    } catch (const invalid_argument & e) {
        // One  or both of the operands is not a number
        throw invalid_argument("Invalid operands for modulo");
    }

}


unique_ptr<Operation> Modulo::create_operation() {
    return make_unique<Modulo>();
}
