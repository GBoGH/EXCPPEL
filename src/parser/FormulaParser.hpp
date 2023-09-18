/**
 * @author Jakub Feik <feikjaku@fit.cvut.cz>
 * @date 13.05.2023
 */

#pragma once

#include <stack>
#include <string>

#include "../objects/Objects.hpp"
#include "../table/Table.hpp"

#include "Parser.hpp"

 /**
  *@class FormulaParser
  *@brief Class for creating a RPN from a string expression using a shunting-yard algorithm -> "https://en.wikipedia.org/wiki/Shunting_yard_algorithm"
 */
class FormulaParser : public Parser {
    Objects obj; // All operators and functions
    std::stack<std::string> op_stack; // Stack for operators
    std::string RPN; // RPN expression

    std::string token_sep = "(),"; // Separators for tokens
public:

    /**
     *@brief Construct a new Formula Parser object
     *
     * @param expr_ expression to parse
     * @param obj_ all operators and functions
     */
    FormulaParser(const std::string & expr_, Objects & obj_);
    FormulaParser(const FormulaParser & other) = delete;
    FormulaParser & operator=(FormulaParser other) = delete;
    ~FormulaParser();

    /**
     *@brief Loads all operators and functions from Objects obj
     */
    void load_operators();

    /**
     *@brief Loads next token from an expression
     *
     * @param formula expression to load from
     * @param pos position in the expression
     * @param token token to load
     * @param op operator to load
     */
    void next_token(std::string & formula, size_t & pos,
        std::string & token, std::string & op);

    /**
     *@brief Handles a function token
     *
     * @param token token to handle
     * @param op operator to handle
     */
    void function_handler(std::string & token, std::string & op);

    /**
     *@brief Handles an operator token
     *
     * @param token token to handle
     * @param op operator to handle
     * @param prev previous operator
     */
    void operator_handler(std::string & token, std::string & op, std::string & prev);

    /**
     *@brief Handles a comma token
     *
     * @param op operator to handle
     */
    void comma_handler(std::string & op);

    /**
     *@brief Handles a parenthesis token
     *
     * @param op  operator to handle
     */
    void parenthesis_handler(std::string & op);

    /**
     *@brief Exctracts operators from the stack
     *
     */
    void extract_from_stack();


    // std::string generate_RPN(const std::string & formula);

    // std::string get_RPN() const;

    /**
     *@brief Parses the expression and creates a RPN
     */
    void parse() override;

    /**
     *@brief Assigns the formula to a cell
     *
     * @param address address of the cell
     * @param table table to assign to
     */
    void assign_to_cell(const Address & address, Table & table) override;
};
