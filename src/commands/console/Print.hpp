/**
 * @author Jakub Feik <feikjaku@fit.cvut.cz>
 * @date 02.06.2023
 */

#pragma once

#include <string>

#include "../Command.hpp"

 /**
  *@class Print
  *@brief Command to print a cell or a range of cells
 */
class Print : public Command {
public:
    /**
     *@brief Construct a new Print object
     *
     * @param command_ print parameters
     */
    Print(const std::string & command_);
    Print(Print & other) = delete;
    Print & operator=(Print & other) = delete;
    ~Print();

    /**
     *@brief Executes the command
     *
     * @param table Table to execute the command on
     */
    void execute(Table & table) override;

    /**
     *@brief Create a command object
     *
     * @param command_ print parameters
     * @return std::unique_ptr<Command> pointer to the new command
     */
    static std::unique_ptr<Command> create_command(const std::string & command_);
};
