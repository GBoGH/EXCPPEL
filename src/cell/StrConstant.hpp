/**
 *  @author Jakub Feik <feikjaku@fit.cvut.cz>
 * @date 12.05.2023
 *
 * @copyright Copyright (c) 2023
 *
 */

#pragma once

#include <string>
#include <memory>

#include "Cell.hpp"

 /**
  *@class StrConstant
  *@brief Class representing a string constant
 */
class StrConstant : public Cell {
public:
    std::string value; // Value of the constant

    /**
     *@brief Construct a new Str Constant object
     *
     * @param address_ address of the cell
     * @param value_ value of the constant
     */
    StrConstant(const Address & address_, const std::string & value_);

    /**
     *@brief Construct a new Str Constant object
     *
     * @param other constant to be copied
     */
    StrConstant(const StrConstant & other);

    /**
     *@brief Assignment operator
     *
     * @param other constant to be assigned
     * @return StrConstant&
     */
    StrConstant & operator=(StrConstant other);

    ~StrConstant();

    /**
     *@brief Clones the cell
     *
     * @return std::unique_ptr<Cell> pointer to the new cell
     */
    std::unique_ptr<Cell> clone() const override;

    /**
     *@brief Prints the cell
     *
     * @param os output stream
     * @param raw if true, prints raw value
     * @param ex if true, prints in export format
     * @return std::ostream&
     */
    std::ostream & print(std::ostream & os, bool raw = false, bool ex = false) const override;

    /**
     *@brief Get the str value of the cell
     *
     * @return std::string
     */
    std::string get_str() const override;

    /**
     *@brief Get the raw str value of the cell
     *
     * @return std::string
     */
    std::string get_raw_str() const override;

    /**
     *@brief Outputs the cell in export format
     *
     * @param os output stream
     * @param raw if true, prints raw value
     * @return std::ostream&
     */
    std::ostream & export_cell(std::ostream & os, bool raw = false) const override;

};