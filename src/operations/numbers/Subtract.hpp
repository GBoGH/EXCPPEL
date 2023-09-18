/**
 * @author Jakub Feik <feikjaku@fit.cvut.cz>
 * @date 31.05.2023
 */

#pragma once

#include <memory>
#include <stack>

#include "../Operation.hpp"

/**
 * @class Subtract
 * @brief Class for subtracting two numbers
 */
class Subtract : public Operation {
public:
    Subtract();
    ~Subtract();

    /**
     *@brief Evaluates difference of two numbers
     *
     * @param values stack of values to use
     */
    void eval(std::stack<std::unique_ptr<Value>> & values) override;

    /**
     *@brief Create a operation object
     *
     * @return std::unique_ptr<Operation> pointer to the operation object
     */
    static std::unique_ptr<Operation> create_operation();
};