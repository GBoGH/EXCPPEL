/**
 * @author Jakub Feik <feikjaku@fit.cvut.cz>
 * @date 31.05.2023
 */

#include <string>
#include <utility>

#include "NumConstant.hpp"

using namespace std;

NumConstant::NumConstant(const Address & address_, const double & value_) :
    Cell(address_),
    value(value_) {}

NumConstant::NumConstant(const NumConstant & other) :
    Cell(other),
    value(other.value) {}

NumConstant & NumConstant::operator=(NumConstant other) {
    swap(address, other.address);
    swap(value, other.value);
    return *this;
}

NumConstant::~NumConstant() = default;

unique_ptr<Cell> NumConstant::clone() const {
    return make_unique<NumConstant>(*this);
}

std::ostream & NumConstant::print(std::ostream & os, bool raw /*= false*/, bool ex /*= false*/) const {
    if (ex) {
        // Export the cell
        return export_cell(os, raw);
    }
    // Return the value of the cell
    os << address << ": " << value;
    return os;
}


string NumConstant::get_str() const {
    return to_string(value);
}

string NumConstant::get_raw_str() const {
    return to_string(value);
}

std::ostream & NumConstant::export_cell(std::ostream & os, bool raw /*=false*/) const {
    // Export the cell in constant format
    os << address << "=" << value;
    return os;
}



