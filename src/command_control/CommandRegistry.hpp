/**
 * @author Jakub Feik <feikjaku@fit.cvut.cz>
 * @date 01.06.2023
 */

#pragma once

#include <functional>
#include <map>
#include <memory>
#include <string>

#include "../commands/Command.hpp"
#include "../table/Table.hpp"

// Function pointer to a command constructor
typedef std::function<std::unique_ptr<Command>(const std::string &)> command_target;

/**
 * @class CommandRegistry
 * @brief Class storing all available commands
 */
class CommandRegistry {
public:
    CommandRegistry();
    ~CommandRegistry();

    // Map of all available commands
    std::map<std::string, command_target> commands;
};