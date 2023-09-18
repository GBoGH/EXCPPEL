/**
 * @author Jakub Feik <feikjaku@fit.cvut.cz>
 * @date 02.06.2023
 */

#pragma once

#include <string>


#include "../table/Table.hpp"

#include "Parser.hpp"

 /**
  *@class ConstantParser
  *@brief Class for parsing constants
 */
class ConstantParser : public Parser {
    bool numeric; // true if constant is numeric
    double numeric_value; // numeric value of constant
public:

    /**
     *@brief Construct a new Constant Parser object
     *
     * @param expr_ expression to parse
     */
    explicit ConstantParser(const std::string & expr_);
    ConstantParser(const ConstantParser & other) = delete;
    ConstantParser & operator=(ConstantParser other) = delete;
    ~ConstantParser();

    /**
     *@brief Checks if constant is a string
     *
     * @return true if constant is a string -
     * @return false otherwise
     */
    bool is_string() const;

    /**
     *@brief Determines if constant is numeric or a string
     *
     */
    void parse() override;

    /**
     *@brief Assigns the constant to a cell
     *
     * @param address address of the cell
     * @param table table to assign to
     */
    void assign_to_cell(const Address & address, Table & table) override;
};