/**
 * @author Jakub Feik <feikjaku@fit.cvut.cz>
 * @date 02.06.2023
 */

#pragma once

#include <string>

#include "../Command.hpp"

 /**
  *@class FileImport
  * @brief Command to import a file
  *
 */
class FileImport : public Command {
public:
    /**
     *@brief Construct a new File Import object
     *
     * @param command_ import parameters
     */
    FileImport(const std::string & command_);
    FileImport(FileImport & other) = delete;
    FileImport & operator=(FileImport & other) = delete;
    ~FileImport();

    /**
     *@brief Executes the command
     *
     * @param table Table to execute the command on
     */
    void execute(Table & table) override;

    /**
     *@brief Create a command object
     *
     * @param command_ import parameters
     * @return std::unique_ptr<Command> pointer to the new command
     */
    static std::unique_ptr<Command> create_command(const std::string & command_);
};
