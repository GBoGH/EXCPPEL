/**
 * @author Jakub Feik <feikjaku@fit.cvut.cz>
 * @date 12.05.2023
 */

#pragma once

#include <string>
#include <utility>

#include "Cell.hpp"

 /**
  *@class NumConstant
  *@brief Class represents numeric constant
 */
class NumConstant : public Cell {
public:
    double value; // value of the constant

    /**
     *@brief Construct a new Num Constant object
     *
     * @param address_ address of the cell
     * @param value_ value of the constant
     */
    NumConstant(const Address & address_, const double & value_);

    /**
     *@brief Construct a new Num Constant object
     *
     * @param other constant to be copied
     */
    NumConstant(const NumConstant & other);

    /**
     *@brief Assignment operator
     *
     * @param other constant to be assigned
     * @return NumConstant&
     */
    NumConstant & operator=(NumConstant other);

    ~NumConstant();

    /**
     *@brief Copies the cell
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
     * @param raw if true, exports raw value
     * @return std::ostream&
     */
    std::ostream & export_cell(std::ostream & os, bool raw = false) const override;

};

