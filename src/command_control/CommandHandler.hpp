/**
 * @author Jakub Feik <feikjaku@fit.cvut.cz>
 * @date 02.06.2023
 */

#pragma once

#include <iostream>
#include <string>

#include "CommandRegistry.hpp"
#include "../table/Table.hpp"


class CommandHandler {
    CommandRegistry registry; // Registry of commands
    Table & table; // Table for the commands to be executed on
    bool in_file = false; // Flag if the command is being read from a file
public:

    /**
     *@brief Construct a new Command Handler object
     *
     * @param table_ Table for the commands to be executed on
     */
    explicit CommandHandler(Table & table_);
    CommandHandler(CommandHandler & other) = delete;
    CommandHandler & operator=(CommandHandler & other) = delete;
    ~CommandHandler();

    /**
     *@brief Reads the command from the input stream
     *
     * @param is input stream
     */
    void read_command(std::istream & is);

    /**
     *@brief Parses the command and executes it
     *
     * @param command Command to be executed
     */
    void parse_command(const std::string & command);
};