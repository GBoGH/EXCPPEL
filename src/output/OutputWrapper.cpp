/**
 * @author Jakub Feik <feikjaku@fit.cvut.cz>
 * @date 04.06.2023
 */

#include <iostream>
#include <memory>
#include <string>


#include "OutputWrapper.hpp"

using namespace std;

OutputWrapper::OutputWrapper(Table & table_) :
    T(table_) {}

OutputWrapper::~OutputWrapper() = default;

void OutputWrapper::print_cell(ostream & os, Cell & cell, bool raw /*=false*/, bool ex /*= false*/) const {
    if (raw) {
        // Print cell in raw form
        cell.print(os, raw, ex);
        os << endl;
        return;
    }
    try {
        // Evaluate cell if it is formula
        evaluate_cell(cell);
        cell.print(os, raw, ex);
        os << endl;
    } catch (const runtime_error & e) {
        // Print error message if the evaluation fails
        os << cell.address << ": " << "Invalid formula " << endl;
    }
}

void OutputWrapper::print(ostream & os, bool raw /*=false*/, bool single /*=false*/) const {
    if (T.table.empty()) {
        os << "Table is empty" << endl;
        return;
    }
    // Kepping track of the column to print column header
    string prev_column = "";

    for (auto & cell : T.table) {
        if (cell.first.column != prev_column) {
            // Print column header if the column changes
            os << "Column " << cell.first.column << ":" << endl;
            prev_column = cell.first.column;
        }

        // Printing only one cell
        if (!single) {
            os << "|  ";
        }

        print_cell(os, *cell.second, raw);
    }
}

void OutputWrapper::print(std::ostream & os, Address address1, Address address2, bool raw /*= false*/, bool single /*= false*/) const {
    string prev_column = "";

    // Iterate over the range of cells
    for (auto it = T.table.lower_bound(address1); it != T.table.upper_bound(address2); ++it) {
        if (it->first.row < address1.row || it->first.row > address2.row) {
            // Skip cells that are not in the range
            continue;
        }
        if (it->first.column != prev_column) {
            // Print column header if the column changes
            os << "Column " << it->first.column << ": " << endl;
            prev_column = it->first.column;
        }

        if (!single) {
            os << "|  ";
        }

        print_cell(os, *it->second, raw);
    }
}

void OutputWrapper::print(ostream & os, Address address1, bool raw /*=false*/, bool single /*=false*/) const {
    auto it = T.table.find(address1);
    if (it == T.table.end()) {
        return;
    }

    print_cell(os, *it->second, raw);
}


void OutputWrapper::export_table(ostream & os, bool raw /*=false*/) const {
    for (auto & cell : T.table) {
        print_cell(os, *cell.second, raw, true);
    }
}

void OutputWrapper::evaluate_cell(Cell & cell) const {
    if (cell.get_RPN().empty()) {
        // Cell is not formula
        return;
    }
    try {
        string RPN = cell.get_RPN();
        unique_ptr<Value> new_value = Evaluate::eval(cell, T, RPN, obj);
        cell.assign_value(new_value);
    } catch (const std::exception & e) {
        throw runtime_error(e.what());
    }
}

