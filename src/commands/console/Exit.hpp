/**
 * @author Jakub Feik <feikjaku@fit.cvut.cz>
 * @date 02.06.2023
 */

#pragma once

#include <string>

#include "../Command.hpp"

 /**
  *@class Exit
  * @brief Command to exit the program
  *
 */
class Exit : public Command {
public:
    /**
     *@brief Construct a new Exit object
     *
     * @param command_ exit parameters
     */
    Exit(const std::string & command_);
    Exit(Exit & other) = delete;
    Exit & operator=(Exit & other) = delete;
    ~Exit();

    /**
     *@brief Executes the command
     *
     * @param table Table to execute the command on
     */
    void execute(Table & table) override;

    /**
     *@brief Create a command object
     *
     * @param command_ exit parameters
     * @return std::unique_ptr<Command> pointer to the new command
     */
    static std::unique_ptr<Command> create_command(const std::string & command_);
};
