/**
 * @author Jakub Feik <feikjaku@fit.cvut.cz>
 * @date 14.05.2023
 */

#include <iostream>

#include "Application.hpp"

using namespace std;

Application::Application() = default;
Application::~Application() = default;


void Application::run() {
    while (true) {
        try {
            handler.read_command(cin);
        } catch (const runtime_error & e) {
            // Any kind of input/calculation error
            cout << e.what() << endl;
        } catch (const logic_error & e) {
            // Exit command was called
            cout << e.what() << endl;
            return;
        }
    }
}