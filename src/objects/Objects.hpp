/**
 * @author Jakub Feik <feikjaku@fit.cvut.cz>
 * @date 01.06.2023
 */

#pragma once

#include <functional>
#include <map>
#include <memory>
#include <string>

#include "../operations/Operation.hpp"

 /**
  *@brief Struct to store operator properties (precedence, associativity)
  *
 */
typedef struct {
    int precedence;
    int associativity;
} op_property;

// Function pointer to create a new operation
typedef std::function<std::unique_ptr<Operation>()> function_target;

class Objects {
public:
    Objects();
    ~Objects();

    // All functions
    std::map<std::string, function_target> functions;

    // All operators
    std::map<std::string, function_target> operators;

    // Operator name, (precedence, associativity)
    std::map<std::string, op_property> op_properties;

    /**
     *@brief Checks if the token is a function
     *
     * @param token token to check
     * @return true if the token is a function -
     * @return false otherwise
     */
    bool is_function(const std::string & token) const;

    /**
     *@brief Checks if the token is an operator
     *
     * @param token token to check
     * @return true if the token is an operator -
     * @return false otherwise
     */
    bool is_operator(const std::string & token) const;
};