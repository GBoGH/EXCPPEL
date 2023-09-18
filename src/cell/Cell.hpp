/**
 * @author Jakub Feik <feikjaku@fit.cvut.cz>
 * @date 12.05.2023
 *
 * @copyright Copyright (c) 2023
 *
 */

#pragma once

#include <iostream>
#include <memory>
#include <set>
#include <string>
#include <utility>

#include "../table/Address.hpp"
#include "../value/Value.hpp"

 /**
  *@class Cell
  *@brief Abstract class representing a cell in a table
 */
class Cell {
public:
    // Address of the cell
    Address address;

    // Cells that current cells depends on
    std::set<Address> dependencies;

    /**
     *@brief Construct a new Cell object from an address
     *
     * @param address_ address of the cell
     */
    Cell(const Address & address_);

    /**
     * @brief Construct a new Cell object from another cell
     *
     * @param other cell to be copied
     */
    Cell(const Cell & other);

    /**
     * @brief Assignment operator
     *
     * @param other cell to be assigned
     * @return Cell&
     */
    Cell & operator=(Cell & other);

    virtual ~Cell();

    /**
     *@brief Get the row of the cell
     *
     * @return int
     */
    int get_row() const;

    /**
     *@brief Get the col object
     *
     * @return std::string
     */
    std::string get_col() const;

    /**
     *@brief Clones the cell
     *
     * @return std::unique_ptr<Cell>
     */
    virtual std::unique_ptr<Cell> clone() const = 0;

    /**
     *@brief Prints the cell
     *
     * @param os output stream
     * @param raw if true, prints the raw value of the cell
     * @param ex if true, prints the cell in export format
     * @return std::ostream&
     */
    virtual std::ostream & print(std::ostream & os, bool raw = false, bool ex = false) const = 0;

    /**
     *@brief Get the str value from the cell
     *
     * @return std::string
     */
    virtual std::string get_str() const = 0;

    /**
     *@brief Get the raw str object
     *
     * @return std::string
     */
    virtual std::string get_raw_str() const = 0;

    /**
     *@brief Outputs the cell in export format
     *
     * @param os output stream
     * @param raw if true, prints the raw value of the cell
     * @return std::ostream&
     */
    virtual std::ostream & export_cell(std::ostream & os, bool raw = false) const = 0;

    /**
     *@brief Assigns a value to the cell
     *
     * @param value_ value to be assigned
     */
    virtual void assign_value(std::unique_ptr<Value> & value_);

    /**
     *@brief Get the RPN representation of the cell
     *
     * @return std::string RPN representation of the cell
     */
    virtual std::string get_RPN() const;
};

