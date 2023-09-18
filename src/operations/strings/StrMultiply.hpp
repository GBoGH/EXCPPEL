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
 * @class StrMultiply
 * @brief Class for multiplying string by a number
 */
class StrMultiply : public Operation {
public:
    StrMultiply();
    ~StrMultiply();

    /**
     *@brief Evaluates string repeated n times
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

    /**
     *@brief Checks if operands are valid - string and number
     *
     * @param str Return value to the string operand
     * @param num Return value to the number operand
     * @return true if operands are valid -
     * @return false otherwise
     */
    bool valid_operands(std::string & str, int & num) const;

};