/**
 * @author Jakub Feik <feikjaku@fit.cvut.cz>
 * @date 12.05.2023
 */

#include <stack>
#include <string>
#include <utility>

#include "Formula.hpp"

using namespace std;

Formula::Formula(const Address & address_, string & formula_, string & RPN_) :
    Cell(address_),
    formula(formula_),
    RPN(RPN_) {}

Formula::Formula(const Formula & other) :
    Cell(other),
    formula(other.formula),
    RPN(other.RPN),
    value(make_unique<Value>(*other.value)) {
}

Formula & Formula::operator=(Formula other) {
    Cell::operator=(other);
    swap(address, other.address);
    swap(formula, other.formula);
    swap(RPN, other.RPN);
    swap(value, other.value);
    return *this;
}

Formula::~Formula() = default;

unique_ptr<Cell> Formula::clone() const {
    return make_unique<Formula>(*this);
}

ostream & Formula::print(std::ostream & os, bool raw /*=false*/, bool ex /*= false*/) const {
    if (ex) {
        return export_cell(os, raw);
    }
    if (raw) {
        // Return the original expression
        os << address << ": " << formula;
        return os;
    } else {
        // Return the raw string representation of the value - with quotes
        os << address << ": " << value->get_raw_str();
    }
    return os;
}

string Formula::get_str() const {
    return value->get_str();
}

string Formula::get_raw_str() const {
    string result = "\"" + get_str() + "\"";
    return result;
}

ostream & Formula::export_cell(std::ostream & os, bool raw) const {
    if (!raw) {
        // Export the formula in constant format
        os << address << "=" << value->get_raw_str();
    } else {
        // Export the formula in assignable format
        os << address << ":=" << formula;
    }
    return os;
}

void Formula::assign_value(unique_ptr<Value> & value_) {
    value = value_->clone();
}

string Formula::get_RPN() const{
    return RPN;
}


