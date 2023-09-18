/**
 * @author Jakub Feik <feikjaku@fit.cvut.cz>
 * @date 02.06.2023
 */

#include <iostream>
#include <memory>
#include <string>

#include "CommandHandler.hpp"

using namespace std;

CommandHandler::CommandHandler(Table & table_) :
    table(table_) {}

CommandHandler::~CommandHandler() = default;

void CommandHandler::read_command(istream & is) {
    string command;
    if (!is.good() && !is.eof()) {
        // Error in the input stream
        throw runtime_error("Input error");
        return;
    }
    getline(is, command);
    if (is.eof() && &is == &cin) {
        // End of file
        throw logic_error("End of file");
        return;
    }

    // Remove duplicate spaces and any whitespace at the beginning or end of the command
    command = Utility::normalize(command);

    if (command.empty()) {
        // Empty line
        return;
    }
    if (&is != &cin) {
        // Print the command out if it is being read from a file
        cout << command << endl;
        in_file = true;
    } else {
        in_file = false;
    }
    CommandHandler::parse_command(command);
}

void CommandHandler::parse_command(const string & command) {
    if (command.find(":=") != string::npos) {
        // Formula assignment
        unique_ptr<Command> cmd = registry.commands[":="](command);
        cmd->execute(table);
    } else if (command.find("=") != string::npos) {
        // Value assignment
        unique_ptr<Command> cmd = registry.commands["="](command);
        cmd->execute(table);
    } else {
        size_t pos = command.find(" ");
        string command_name;
        string command_args;
        if (pos == string::npos) {
            command_name = command;
        } else {
            command_name = command.substr(0, pos);
            command_args = command.substr(pos + 1);
        }

        if (registry.commands.find(command_name) == registry.commands.end()) {
            throw runtime_error("Unknown command");
        } else {
            if (command_name == "IMPORT") {
                // Formbid nested imports
                if (in_file) {
                    throw runtime_error("Nested imports not allowed");
                } else {
                    in_file = true;
                }
            }
            unique_ptr<Command> cmd = registry.commands[command_name](command_args);
            cmd->execute(table);
        }
    }
}