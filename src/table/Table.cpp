/**
 * @author Jakub Feik <feikjaku@fit.cvut.cz>
 * @date 13.05.2023
 */

#include <map>
#include <memory>
#include <utility>

#include "Table.hpp"

using namespace std;

Table::Table() = default;
Table::~Table() = default;

Table::Table(const Table & other) {
    for (auto & cell : other.table) {
        table[cell.first] = cell.second->clone();
    }
}

Table & Table::operator=(Table other) {
    swap(table, other.table);
    return *this;
}

void Table::add_cell(const Address & address, const Cell & cell) {
    if (table.find(address) != table.end()) {
        table.erase(address);
    }
    table.insert(make_pair(address, cell.clone()));
}

void Table::add_cell(const Cell & cell) {
    Address target_address = cell.address;
    if (table.find(target_address) != table.end()) {
        table.erase(target_address);
    }
    table.insert(make_pair(target_address, cell.clone()));
}

unique_ptr<Cell> Table::get_cell(const Address & address) const {
    if (table.find(address) == table.end()) {
        return nullptr;
    }
    return (table.find(address))->second->clone();
}

unique_ptr<Cell> Table::get_cell(const Cell & cell) const {
    return get_cell(cell.address);
}

bool Table::contains(const Address & address) const {
    return table.find(address) != table.end();
}

void Table::clear() {
    table.clear();
}

void Table::clear(const Address & address1) {
    if (table.find(address1) != table.end()) {
        table.erase(address1);
    }
}

void Table::clear(const Address & address1, const Address & address2) {
    const auto & [start, end] = Address::get_range(address1, address2);
    for (auto it = table.lower_bound(start); it != table.upper_bound(end);) {
        if (it->first.row <= end.row) {
            it = table.erase(it);
        } else {
            ++it;
        }
    }
}

