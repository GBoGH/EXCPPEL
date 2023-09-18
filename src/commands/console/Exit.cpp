/**
 * @author Jakub Feik <feikjaku@fit.cvut.cz>
 * @date 02.06.2023
 */

#include<iostream>
#include<string>

#include "Exit.hpp"

using namespace std;

Exit::Exit(const std::string & command_) :
    Command(command_) {}

Exit::~Exit() = default;

void Exit::execute(Table & table)  {
    throw logic_error("Exiting");
}

unique_ptr<Command> Exit::create_command(const string & command_) {
    return make_unique<Exit>(command_);
}