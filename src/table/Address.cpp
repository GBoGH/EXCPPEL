/**
 * @author Jakub Feik <feikjaku@fit.cvut.cz>
 * @date 13.05.2023
 */

#include <iostream>
#include <string>

#include "Address.hpp"

using namespace std;

Address::Address() = default;

Address::Address(const string & column_, int row_) :
    column(column_), row(row_) {}

Address::Address(const string & address) {
    column = address.substr(0, address.find_first_of("0123456789"));
    row = stoi(address.substr(address.find_first_of("0123456789")));
}

Address::~Address() = default;

Address::Address(const Address & other) :
    column(other.column), row(other.row) {}

Address & Address::operator=(Address other) {
    swap(column, other.column);
    swap(row, other.row);
    return *this;
}

bool operator<(const Address & lhs, const Address & rhs) {
    if (lhs.column != rhs.column) {
        return lhs.column < rhs.column;
    }
    return lhs.row < rhs.row;
}

bool operator==(const Address & lhs, const Address & rhs) {
    return lhs.column == rhs.column && lhs.row == rhs.row;
}

pair<Address, Address> Address::get_range(Address start, Address end) {
    // Swaps addresses in such a way that start is always top left and end is always bottom right
    if (start.column > end.column) {
        swap(start.column, end.column);
    }
    if (start.row > end.row) {
        swap(start.row, end.row);
    }
    return make_pair(start, end);
}

pair<Address, Address> Address::split_range(const string & range) {
    size_t pos = range.find(":");
    string start = range.substr(0, pos);
    string end = range.substr(pos + 1);
    return get_range(Address(start), Address(end));
}

ostream & operator<<(ostream & os, const Address & address) {
    os << address.column << address.row;
    return os;
}

