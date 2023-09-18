/**
 * @author Jakub Feik <feikjaku@fit.cvut.cz>
 * @date 02.06.2023
 */

#pragma once

#include <string>

#include "../table/Table.hpp"
#include "../utility/Utility.hpp"

 /**
  * @class Command
  * @brief Virtual class for all commands. This class is used to create and execute commands. To create a new command, inherit from this class and implement the execute method.
  *
 */
class Command {
public:
    std::string command;

    /**
     *@brief Construct a new Command object
     *
     * @param name name of the command
     */
    Command(const std::string & name);
    Command(Command & other) = delete;
    Command & operator=(Command & other) = delete;
    virtual ~Command();

    /**
     *@brief Executes the command
     *
     * @param table  Table to execute the command on
     */
    virtual void execute(Table & table) = 0;
};
