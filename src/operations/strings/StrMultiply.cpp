/**
 * @author Jakub Feik <feikjaku@fit.cvut.cz>
 * @date 31.05.2023
 */

#include <memory>
#include <string>
#include <stack>

#include "../../utility/Utility.hpp"

#include "StrMultiply.hpp"

using namespace std;

StrMultiply::StrMultiply() = default;
StrMultiply::~StrMultiply() = default;

void StrMultiply::eval(std::stack<std::unique_ptr<Value>> & values) {

    stack_extract(values);

    // Initialize result with quotes
    string result = "\"";

    // Operands
    int num;
    string str;

    if (valid_operands(str, num)) {
        for (int i = 0; i < num; i++) {
            result += str;
        }
    } else {
        throw invalid_argument("Invalid operands for string multiplication");
    }

    result.push_back('"');

    values.push(make_unique<Value>(result));
}

bool StrMultiply::valid_operands(string & str, int & num) const {
    // This is an XOR operation, one operand must be a number and the other a string

    if (Utility::can_be_number(lhs->get_str()) && Utility::valid_string(rhs->get_raw_str())) {
        // Number ^ String
        double number = lhs->get_num();
        if (Utility::is_integer(number)) {
            num = static_cast<int>(number);
            str = rhs->get_str();
            return true;
        }
        return false;
    } else if (Utility::can_be_number(rhs->get_str()) && Utility::valid_string(lhs->get_raw_str())) {
        // String ^ Number
        double number = rhs->get_num();
        if (Utility::is_integer(number)) {
            num = static_cast<int>(number);
            str = lhs->get_str();
            return true;
        }
        return false;
    }
    return false;
}

unique_ptr<Operation> StrMultiply::create_operation() {
    return make_unique<StrMultiply>();
}
