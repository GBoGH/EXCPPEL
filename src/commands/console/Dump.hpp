/**
 * @author Jakub Feik <feikjaku@fit.cvut.cz>
 * @date 02.06.2023
 */

#pragma once

#include <string>

#include "../Command.hpp"

 /**
  *@class Dump
  *@brief Command to dump the table
 */
class Dump : public Command {
public:
    /**
     *@brief Construct a new Dump object
     *
     * @param command_ dump parameters
     */
    Dump(const std::string & command_);
    Dump(Dump & other) = delete;
    Dump & operator=(Dump & other) = delete;
    ~Dump();

    /**
     *@brief Executes the command
     * @param table Table to execute the command on
     */
    void execute(Table & table) override;

    /**
     *@brief Create a command object
     *
     * @param command_ dump parameters
     * @return std::unique_ptr<Command>
     */
    static std::unique_ptr<Command> create_command(const std::string & command_);
};
