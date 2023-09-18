/**
 * @author Jakub Feik <feikjaku@fit.cvut.cz>
 * @date 31.05.2023
 */

#include <memory>
#include <string>
#include <stack>

#include "StrAdd.hpp"
#include "../../utility/Utility.hpp"

using namespace std;

StrAdd::StrAdd() = default;
StrAdd::~StrAdd() = default;

void StrAdd::eval(std::stack<unique_ptr<Value>> & values) {
    stack_extract(values);
    if (!Utility::valid_string(lhs->get_raw_str()) || !Utility::valid_string(rhs->get_raw_str())) {
        throw invalid_argument("Invalid string for addition");
    }
    // Add quotes to the result
    string result = "\"" + lhs->get_str() + rhs->get_str() + "\"";
    values.push(make_unique<Value>(result));
}

unique_ptr<Operation> StrAdd::create_operation() {
    return make_unique<StrAdd>();
}
