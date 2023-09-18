/**
 * @author Jakub Feik <feikjaku@fit.cvut.cz>
 * @date 01.06.2023
 */

#pragma once

#include <memory>
#include <stack>

#include "../Operation.hpp"

/**
 *@class Negate
 *@brief Class for negating a number
 */
class Negate : public Operation {
public:
    Negate();
    ~Negate();

    /**
     *@brief Negates a number
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