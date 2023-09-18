/**
 * @author Jakub Feik <feikjaku@fit.cvut.cz>
 * @date 02.06.2023
 */

#pragma once

#include <string>

#include "../Command.hpp"

 /**
  *@class FileExport
  *@brief Command to export the table to a file
  *
 */
class FileExport : public Command {
public:
    /**
     *@brief Construct a new File Export object
     *
     * @param command_ export parameters
     */
    FileExport(const std::string & command_);
    FileExport(FileExport & other) = delete;
    FileExport & operator=(FileExport & other) = delete;
    ~FileExport();

    /**
     *@brief Executes the command
     *
     * @param table Table to execute the command on
     */
    void execute(Table & table) override;

    /**
     *@brief Create a command object
     *
     * @param command_ export parameters
     * @return std::unique_ptr<Command> pointer to the new command
     */
    static std::unique_ptr<Command> create_command(const std::string & command_);
};
