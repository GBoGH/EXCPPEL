/**
 * @author Jakub Feik <feikjaku@fit.cvut.cz>
 * @date 12.05.2023
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <string>

#include "Cell.hpp"

using namespace std;

Cell::Cell(const Address & address_) :
    address(address_) {}

Cell::Cell(const Cell & other) :
    address(other.address),
    dependencies(other.dependencies) {}

Cell & Cell::operator=(Cell & other) {
    address = other.address;
    for (auto & dep : other.dependencies) {
        dependencies.insert(dep);
    }
    return *this;
}

Cell::~Cell() = default;

int Cell::get_row() const {
    return address.row;
}

std::string Cell::get_col() const {
    return address.column;
}

void Cell::assign_value(std::unique_ptr<Value> & value_) {}

std::string Cell::get_RPN() const {
    return "";
}


