/**
 * @author Jakub Feik <feikjaku@fit.cvut.cz>
 * @date 13.05.2023
 */

#pragma once

#include <string>

#include "../table/Table.hpp"

 /**
  *@class Parser
  *@brief Abstract class for parsing an expression. Either a formula or a value
  *
 */
class Parser {
protected:
    std::string expression; // Expression to parse
public:
    /**
     *@brief Construct a new Parser object
     *
     * @param expr_ expression to parse
     */
    Parser(const std::string & expr_);
    Parser(const Parser & other) = delete;
    Parser & operator=(Parser & other) = delete;
    virtual ~Parser();

    /**
     *@brief Assigns the result of the expression to a cell
     *
     * @param address address of the cell
     * @param table table to assign to
     */
    virtual void assign_to_cell(const Address & address, Table & table) = 0;

    virtual void parse() = 0;

    // virtual std::ostream & print(std::ostream & os) const = 0;

};