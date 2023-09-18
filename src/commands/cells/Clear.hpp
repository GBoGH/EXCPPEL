/**
 * @author Jakub Feik <feikjaku@fit.cvut.cz>
 * @date 02.06.2023
 */

#pragma once

#include <string>

#include "../Command.hpp"

 /**
  *@class Clear
  *@brief Command to clear a cell or a range of cells
 */
class Clear : public Command {
public:
    /**
     *@brief Construct a new Clear object
     *
     * @param command_ cell or range of cells to be cleared
     */
    Clear(const std::string & command_);
    Clear(Clear & other) = delete;
    Clear & operator=(Clear & other) = delete;
    ~Clear();

    /**
     *@brief Executes the command
     *
     * @param table Table to execute the command on
     */
    void execute(Table & table) override;

    /**
     *@brief Create a command object
     *
     * @param command_ cell or range of cells to be cleared
     * @return std::unique_ptr<Command> pointer to the new command
     */
    static std::unique_ptr<Command> create_command(const std::string & command_);
};
