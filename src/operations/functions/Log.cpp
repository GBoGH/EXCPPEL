/**
 * @author Jakub Feik <feikjaku@fit.cvut.cz>
 * @date 31.05.2023
 */

#include <cfenv>
#include <cmath>
#include <memory>
#include <stack>
#include <string>

#include "Log.hpp"

using namespace std;

Log::Log() = default;
Log::~Log() = default;


void Log::eval(stack<unique_ptr<Value>> & values) {
    stack_extract(values);
    try {
        double result = log(rhs->get_num()) / log(lhs->get_num());
        if (fetestexcept(FE_DIVBYZERO) || fetestexcept(FE_INVALID)) {
            feclearexcept(FE_ALL_EXCEPT);
            // Negative or zero argument etc.
            throw invalid_argument("Invalid argument for logarithm");
        }
        values.push(make_unique<Value>(to_string(result)));
    } catch (const invalid_argument & e) {
        throw invalid_argument("Invalid argument for logarithm");
    }
}


unique_ptr<Operation> Log::create_operation() {
    return make_unique<Log>();
}