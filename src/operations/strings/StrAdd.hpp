/**
 * @author Jakub Feik <feikjaku@fit.cvut.cz>
 * @date 31.05.2023
 */

#pragma once

#include <memory>
#include <string>
#include <stack>

#include "../Operation.hpp"

/**
 * @class StrAdd
 * @brief Class for concatenating two strings
 */
class StrAdd : public Operation {
public:
    StrAdd();
    ~StrAdd();

    /**
     *@brief Evaluates concatenation of two strings
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