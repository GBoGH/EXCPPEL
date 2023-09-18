/**
 * @author Jakub Feik <feikjaku@fit.cvut.cz>
 * @date 12.05.2023
 */

#include <string>

#include "StrConstant.hpp"

using namespace std;

StrConstant::StrConstant(const Address & address_, const string & value_) :
    Cell(address_),
    value(value_) {}

StrConstant::StrConstant(const StrConstant & other) :
    Cell(other),
    value(other.value) {}

StrConstant & StrConstant::operator=(StrConstant other) {
    swap(address, other.address);
    swap(value, other.value);
    return *this;
}

StrConstant::~StrConstant() = default;

unique_ptr<Cell> StrConstant::clone() const {
    return make_unique<StrConstant>(*this);
}

std::ostream & StrConstant::print(std::ostream & os, bool raw /*= false*/, bool ex /*= false*/) const {
    if (ex) {
        // Export the cell
        return export_cell(os, raw);
    }
    // Output the value of the cell
    os << address << ": " << value;
    return os;
}

string StrConstant::get_str() const {
    return value;
}

string StrConstant::get_raw_str() const {
    return value;
}

ostream & StrConstant::export_cell(std::ostream & os, bool raw /*=false*/) const {
    // Export the cell in constant format
    os << address << "=" << get_raw_str();
    return os;
}
