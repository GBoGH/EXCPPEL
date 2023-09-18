/**
 * @author Jakub Feik <feikjaku@fit.cvut.cz>
 * @date 03.06.2023
 */

#include <iostream>
#include <memory>
#include <stack>

#include "Evaluate.hpp"

using namespace std;

std::unique_ptr<Value> Evaluate::eval(
    Cell & cell,
    Table & table,
    const std::string & RPN,
    const Objects & obj) {

    stack <unique_ptr<Value>> values;

    size_t pos = 0;

    while (pos < RPN.size()) {
        // Get the next operator or operand
        size_t next = RPN.find(" ", pos);
        string token = RPN.substr(pos, next - pos);

        if (token[0] == '"' && !Utility::valid_string(token)) {
            // If the token is a string, find the complete string
            size_t next_quote = RPN.find_first_of('"', next);
            token = RPN.substr(pos, next_quote - pos + 1);
            pos = next_quote + 2;
        } else {
            pos = next + 1;
        }

        if (obj.is_operator(token)) {
            obj.operators.at(token)()->eval(values);
        } else if (obj.is_function(token)) {
            obj.functions.at(token)()->eval(values);
        } else if (Utility::valid_address(token)) {
            eval_dependencies(cell, Address(token), table, obj, values);
        } else {
            values.push(make_unique<Value>(token));
        }
    }

    // After evaluation either 0 or more than 1 values were left on the stack, ie the formula was invalid
    if (values.size() != 1) {
        throw runtime_error("Invalid formula");
    }

    return make_unique<Value>(*values.top());
}

void Evaluate::eval_dependencies(
    Cell & cell, const Address & target_address,
    Table & table, const Objects & obj,
    std::stack<std::unique_ptr<Value>> & values) {

    if (target_address == cell.address) {
        throw runtime_error("Invalid formula");
    }

    unique_ptr<Cell> target = table.get_cell(target_address);

    if (target == nullptr) {
        // Create placeholder cell if no such cell exists
        values.push(make_unique<Value>(""));
        cell.dependencies.insert(target_address);
        return;
    }

    try {
        // Add the dependency to the cell
        cell.dependencies.insert(target_address);

        if (target->get_RPN().empty()) {
            // If the cell is a value cell, push the value
            values.push(make_unique<Value>(target->get_raw_str()));
            return;
        }
        check_dependencies(target_address, cell.address, table);

        // Evaluate the cell
        unique_ptr<Value> target_result = Evaluate::eval(*target, table, target->get_RPN(), obj);

        values.push(target_result->clone());

    } catch (logic_error & e) {
        throw runtime_error("Invalid formula");
    } catch (runtime_error & e) {
        throw runtime_error("Invalid formula");
    }
}


void Evaluate::check_dependencies(const Address & address, const Address & og_address, const Table & table) {
    unique_ptr<Cell> target = table.get_cell(address);

    // If the cell is not in the table or has no dependencies, return
    if (target == nullptr || target->dependencies.empty()) {
        return;
    }


    set<Address> current_dep = target->dependencies;

    // Recursively check all dependencies
    for (const auto & dep : current_dep) {
        if (dep == og_address) {
            throw logic_error("Circular dependency");
        }

        check_dependencies(dep, og_address, table);
    }
}
