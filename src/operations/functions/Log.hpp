/**
 * @author Jakub Feik <feikjaku@fit.cvut.cz>
 * @date 31.05.2023
 */

#pragma once

#include <memory>
#include <stack>


#include "../Operation.hpp"

 /**
  *@class Log
  *@brief Class for taking logarithm of a number with a custom base
 */
class Log : public Operation {
public:
    Log();
    ~Log() override;

    /**
     *@brief Evaluates logarithm of a number with a custom base
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