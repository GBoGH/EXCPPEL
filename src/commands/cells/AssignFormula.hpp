/**
 * @author Jakub Feik <feikjaku@fit.cvut.cz>
 * @date 02.06.2023
 */

#pragma once

#include <string>

#include "../Command.hpp"

/**
 * @class AssignFormula
 * @brief Command to assign a formula to a cell
 */
class AssignFormula : public Command {
public:
    /**
     *@brief Construct a new Assign Formula object
     *
     * @param command_ formula to be assigned
     */
    AssignFormula(const std::string & command_);
    AssignFormula(AssignFormula & other) = delete;
    AssignFormula & operator=(AssignFormula & other) = delete;
    ~AssignFormula();

    /**
     *@brief Create a command object
     *
     * @param command_ formula to be assigned
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
