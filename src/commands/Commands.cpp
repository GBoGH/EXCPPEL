/**
 * @author Jakub Feik <feikjaku@fit.cvut.cz>
 * @date 02.06.2023
 */

#include <string>

#include "Command.hpp"

using namespace std;

Command::Command(const string & command_) :
    command(command_) {}

Command::~Command() = default;