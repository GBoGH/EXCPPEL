/**
 * @author Jakub Feik <feikjaku@fit.cvut.cz>
 * @date 13.05.2023
 */

#include <iostream>
#include <memory>
#include <utility>
#include <string>

#include "Value.hpp"

using namespace std;

Value::Value() = default;

Value::~Value() = default;

Value::Value(const string & value_) :
    value(value_) {}

Value::Value(const Value & other) :
    value(other.value) {}

Value & Value::operator=(Value other) {
    swap(value, other.value);
    return *this;
}

std::unique_ptr<Value> Value::clone() const {
    return make_unique<Value>(*this);
}

// std::ostream & Value::print(std::ostream & os) const {
//     try {
//         os << get_num();
//     } catch (const invalid_argument & e) {
//         os << get_str();
//     }
//     return os;
// }

// ostream & operator<<(ostream & os, const Value & value) {
//     return value.print(os);
// }

double Value::get_num() const {
    if (value.empty()) {
        // Empty cell is treated as 0
        return 0;
    }
    try {
        return stod(value);
    } catch (const invalid_argument & e) {
        throw invalid_argument("Value is not a number");
    }
}

string Value::get_str() const {
    if (!represents_number().empty()) {
        return represents_number();
    }
    return Utility::trim_char(value, "\"");
}

string Value::get_raw_str() const {
    if (!represents_number().empty()) {
        return represents_number();
    }
    if (value.empty()) {
        return "\"\"";
    }
    return value;
}

string Value::represents_number() const {
    // Checks if value represents an integer
    if (Utility::valid_number(value) && !value.empty()) {
        double num = stod(value);
        if (Utility::is_integer(num)) {
            return to_string(static_cast<long long int>(num));
        }
    }
    return "";
}
