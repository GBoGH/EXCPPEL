/**
 * @author Jakub Feik <feikjaku@fit.cvut.cz>
 * @date 02.06.2023
 */

#include<exception>
#include<iostream>
#include<string>

#include "../../table/Address.hpp"
#include "../../parser/FormulaParser.hpp"
#include "../../objects/Objects.hpp"

#include "AssignFormula.hpp"

using namespace std;

AssignFormula::AssignFormula(const std::string & command_) :
    Command(command_) {}

AssignFormula::~AssignFormula() = default;

void AssignFormula::execute(Table & table) {
    command = Utility::remove_spaces(command);
    size_t pos = command.find(":=");

    // Normalize the cell address
    string cell_address = Utility::trim_char(command.substr(0, pos));
    Utility::capitalize(cell_address);

    // The formula is from the first := to the end of the command
    string value = command.substr(pos + 2);

    if (!Utility::valid_address(cell_address)) {
        throw runtime_error("Invalid cell address");
    }

    // Construct the objects and the parser
    Address address(cell_address);
    Objects objects;
    FormulaParser parser = FormulaParser(value, objects);

    try {
        parser.parse();
        parser.assign_to_cell(address, table);
    } catch (invalid_argument & e) {
        throw runtime_error("Invalid Formula");
    }
}

unique_ptr<Command> AssignFormula::create_command(const string & command_) {
    return make_unique<AssignFormula>(command_);
}