/**
 * @author Jakub Feik <feikjaku@fit.cvut.cz>
 * @date 13.05.2023
 */

#pragma once

#include "../table/Table.hpp"
#include "../command_control/CommandHandler.hpp"

 /**
  *@class Application
  *@brief Wrapper class for the whole application. Runs the main loop
  *
 */
class Application {
    Table table; // Table to store data
    CommandHandler handler = CommandHandler(table); // Command handler to parse and execute commands
public:
    Application();
    ~Application();

    /**
     * @brief Main loop of the application
     *
     */
    void run();

};