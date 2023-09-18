/**
 * @author Jakub Feik <feikjaku@fit.cvut.cz>
 * @date 02.06.2023
 */

#include<iostream>
#include<string>

#include "Clear.hpp"

using namespace std;

Clear::Clear(const std::string & command_) :
    Command(command_) {}

Clear::~Clear() = default;

void Clear::execute(Table & table) {
    if (Utility::valid_range(command)) {
        const auto & [a1, a2] = Address::split_range(command);
        table.clear(a1, a2);
    } else if (Utility::valid_address(command)) {
        Address a1 = Address(command);
        table.clear(a1);
    } else if (command == "ALL") {
        table.clear();
    } else {
        throw runtime_error("Invalid Parameters");
    }

}

unique_ptr<Command> Clear::create_command(const string & command_) {
    return make_unique<Clear>(command_);
}