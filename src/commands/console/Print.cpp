/**
 * @author Jakub Feik <feikjaku@fit.cvut.cz>
 * @date 02.06.2023
 */

#include<iostream>
#include<string>

#include "../../output/OutputWrapper.hpp"
#include "../../table/Table.hpp"

#include "Print.hpp"

using namespace std;

Print::Print(const std::string & command_) :
    Command(command_) {}

Print::~Print() = default;

void Print::execute(Table & table) {
    // Flag to determine whether to print raw or not
    bool raw = false;

    OutputWrapper out = OutputWrapper(table);

    if (command.substr(0, 3) == "RAW") {
        raw = true;
        command = command.substr(4);
    }
    if (Utility::valid_range(command)) {
        const auto & [a1, a2] = Address::split_range(command);
        out.print(cout, a1, a2, raw);
    } else if (Utility::valid_address(command)) {
        out.print(cout, Address(command), raw, true);
    } else {
        throw runtime_error("Invalid Parameters");
    }
}

unique_ptr<Command> Print::create_command(const string & command_) {
    return make_unique<Print>(command_);
}