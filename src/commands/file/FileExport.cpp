/**
 * @author Jakub Feik <feikjaku@fit.cvut.cz>
 * @date 02.06.2023
 */

#include<fstream>
#include<iostream>
#include<string>

#include "../../output/OutputWrapper.hpp"

#include "FileExport.hpp"

using namespace std;

FileExport::FileExport(const std::string & command_) :
    Command(command_) {}

FileExport::~FileExport() = default;

void FileExport::execute(Table & table) {
    bool raw = false;

    if (command.substr(0, 3) == "RAW") {
        raw = true;
        command = command.substr(4);
    }

    // Trim " from the path
    command = Utility::trim_char(command, " \"");

    ofstream file(command);

    OutputWrapper out = OutputWrapper(table);

    if (!file.is_open()) {
        throw runtime_error("Invalid File");
    }
    try {
        out.export_table(file, raw);
    } catch (runtime_error & e) {
        file.close();
        throw runtime_error("Invalid File");
    }
    file.close();

}

unique_ptr<Command> FileExport::create_command(const string & command_) {
    return make_unique<FileExport>(command_);
}