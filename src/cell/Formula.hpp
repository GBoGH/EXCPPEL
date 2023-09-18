/**
 * @author Jakub Feik <feikjaku@fit.cvut.cz>
 * @date 12.05.2023
 *
 * @copyright Copyright (c) 2023
 *
 */

#pragma once

#include <memory>
#include <string>
#include <utility>

#include "Cell.hpp"
#include "../utility/Utility.hpp"
#include "../value/Value.hpp"

 /**
  *@class Formula
  *@brief Class representing a formula cell in a table
  *
 */
class Formula : public Cell {
    std::string formula; // String representation of the expression
    std::string RPN; // Reverse Polish Notation of the expression
    std::unique_ptr<Value> value = nullptr; // Value of the expression
public:

    /**
     *@brief Construct a new Formula object
     *
     * @param address_ address of the cell
     * @param expr_ string representation of the expression
     * @param RPN_ Reverse Polish Notation of the expression
     */
    Formula(const Address & address_, std::string & expr_, std::string & RPN_);

    /**
     * @brief Construct a new Formula object from another formula
     *
     * @param other formula to be copied
     */
    Formula(const Formula & other);

    /**
     * @brief Assignment operator
     *
     * @param other formula to be assigned
     * @return Formula&
     */
    Formula & operator=(Formula other);
    ~Formula() override;

    /**
     *@brief Creates a copy of the formula
     *
     * @return std::unique_ptr<Cell>
     */
    std::unique_ptr<Cell> clone() const override;

    /**
     *@brief Prints the formula
     *
     * @param os output stream
     * @param raw if true, prints the formula in raw format
     * @param ex if true, prints the formula in export format
     * @return std::ostream&
     */
    std::ostream & print(std::ostream & os, bool raw = false, bool ex = false) const override;

    /**
     *@brief Get the string representation of the formula
     *
     * @return std::string
     */
    std::string get_str() const override;

    /**
     *@brief Get the raw string representation of the formula
     *
     * @return std::string
     */
    std::string get_raw_str() const override;

    /**
     *@brief Outputs the formula in export format
     *
     * @param os output stream
     * @param raw if true, prints the formula in raw format
     * @return std::ostream&
     */
    std::ostream & export_cell(std::ostream & os, bool raw = false) const override;

    /**
     *@brief Assigns a value to the formula
     *
     * @param value_  value to be assigned
     */
    void assign_value(std::unique_ptr<Value> & value_);

    /**
     *@brief Get the RPN of the formula
     *
     * @return std::string
     */
    std::string get_RPN() const override;
};
