/**
 * @author Jakub Feik <feikjaku@fit.cvut.cz>
 * @date 02.06.2023
 */

#include<string>
#include<iostream>

#include "../../table/Address.hpp"
#include "../../parser/ConstantParser.hpp"

#include "AssignConstant.hpp"

using namespace std;

AssignConstant::AssignConstant(const std::string & command_) :
    Command(command_) {}

AssignConstant::~AssignConstant() = default;

void AssignConstant::execute(Table & table) {
    command = Utility::remove_spaces(command);
    size_t pos = command.find("=");

    // Normalize the cell address
    string cell_address = Utility::trim_char(command.substr(0, pos));
    Utility::capitalize(cell_address);

    // The constant value is from the first = to the end of the command
    string value = command.substr(pos + 1);

    if (!Utility::valid_address(cell_address)) {
        throw runtime_error("Invalid cell address");
    }

    // Construct the address and the parser
    Address address(cell_address);
    ConstantParser parser = ConstantParser(value);

    try {
        parser.parse();
        parser.assign_to_cell(address, table);
    } catch (const invalid_argument & e) {
        throw runtime_error("Invalid constant value");
    }
}

unique_ptr<Command> AssignConstant::create_command(const string & command_) {
    return make_unique<AssignConstant>(command_);
}