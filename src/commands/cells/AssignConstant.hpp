/**
 * @author Jakub Feik <feikjaku@fit.cvut.cz>
 * @date 02.06.2023
 */

#pragma once

#include <memory>
#include <string>

#include "../Command.hpp"

 /**
  *@class AssignConstant
  *@brief Command to assign constant to a cell
 */
class AssignConstant : public Command {
public:
    /**
     *@brief Construct a new Assign Constant object
     *
     * @param command_ constant to be assigned
     */
    AssignConstant(const std::string & command_);
    AssignConstant(AssignConstant & other) = delete;
    AssignConstant & operator=(AssignConstant & other) = delete;
    ~AssignConstant();

    /**
     *@brief Create a command object
     *
     * @param command_ constant to be assigned
     * @return std::unique_ptr<Command> pointer to the new command
     */
    static std::unique_ptr<Command> create_command(const std::string & command_);

    /**
     *@brief Executes the command
     *
     * @param table Table to execute the command on
     */
    void execute(Table & table) override;
};
