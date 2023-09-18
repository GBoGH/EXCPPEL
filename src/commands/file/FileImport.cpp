/**
 * @author Jakub Feik <feikjaku@fit.cvut.cz>
 * @date 02.06.2023
 */

#include<fstream>
#include<iostream>
#include<string>

#include "../../command_control/CommandHandler.hpp"

#include "FileImport.hpp"

using namespace std;

FileImport::FileImport(const std::string & command_) :
    Command(command_) {}

FileImport::~FileImport() = default;

void FileImport::execute(Table & table) {
    // Remove quotes from the path
    command = Utility::trim_char(command, " \"");

    ifstream file(command);
    if (!file.is_open()) {
        throw runtime_error("Invalid File");
    }
    CommandHandler handler = CommandHandler(table);
    while (file.peek() != EOF) {
        try {
            handler.read_command(file);
        } catch (runtime_error & e) {
                cout << e.what() << endl;
        } catch (logic_error & e) {
            file.close();
            throw e;
        }
    }
    file.close();
}

unique_ptr<Command> FileImport::create_command(const string & command_) {
    return make_unique<FileImport>(command_);
}