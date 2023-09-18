/**
 * @author Jakub Feik <feikjaku@fit.cvut.cz>
 * @date 02.06.2023
 */

#include<iostream>
#include<string>

#include "../../output/OutputWrapper.hpp"

#include "Dump.hpp"

using namespace std;

Dump::Dump(const std::string & command_) :
    Command(command_) {}

Dump::~Dump() = default;

void Dump::execute(Table & table) {
    OutputWrapper out = OutputWrapper(table);
    if (command == "ALL") {
        out.print(cout);
    } else if (command == "RAW") {
        out.print(cout, true);
    } else {
        throw runtime_error("Invalid Parameters");
    }
}

unique_ptr<Command> Dump::create_command(const string & command_) {
    return make_unique<Dump>(command_);
}