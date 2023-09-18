/**
 * @author Jakub Feik <feikjaku@fit.cvut.cz>
 * @date 31.05.2023
 */

#pragma once

#include <memory>
#include <stack>

#include "../Operation.hpp"

/**
 *@class Divide
 *@brief Class for dividing two numbers
 */
class Divide : public Operation {
public:
    Divide();
    ~Divide();

    /**
     *@brief Evaluates the ratio of two numbers
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
