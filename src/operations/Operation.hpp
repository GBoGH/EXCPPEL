/**
 * @author Jakub Feik <feikjaku@fit.cvut.cz>
 * @date 31.05.2023
 */

#pragma once

#include <iostream>
#include <memory>
#include <string>
#include <stack>

#include "../value/Value.hpp"

/**
 * @class Operation
 * @brief Virtual class for all operations. This class is used to create and execute operations. To create a new operation, inherit from this class and implement the eval method.
 *
 */
class Operation {
public:
    std::unique_ptr<Value> lhs; // Left operand
    std::unique_ptr<Value> rhs; // Right operand

    Operation();
    virtual ~Operation();

    Operation(Operation & other) = delete;
    Operation & operator=(Operation & other) = delete;

    /**
     *@brief Evaluates the operation
     *
     * @param values stack of values to use
     */
    virtual void eval(std::stack<std::unique_ptr<Value>> & values) = 0;

    /**
     *@brief Extracts the appropriate number of values from the stack
     *
     * @param values stack of values to use
     * @param count number of values to extract
     */
    void stack_extract(std::stack<std::unique_ptr<Value>> & values, size_t count = 2);
};

