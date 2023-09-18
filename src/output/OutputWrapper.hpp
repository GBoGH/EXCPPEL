/**
 * @author Jakub Feik <feikjaku@fit.cvut.cz>
 * @date 04.06.2023
 */

#pragma once

#include <iostream>
#include <memory>

#include "../table/Table.hpp"
#include "../operations/Evaluate.hpp"
#include "../objects/Objects.hpp"

 /**
  *@class OutputWrapper
  *@brief Class connecting table, evaluation and output. This class is used for evaluating cells at the time of printing and subsequently printing them.
 */
class OutputWrapper {
    Table & T; // reference to table to execute operations on
    Objects obj = Objects(); // object for evaluating cells
public:
    /**
     *@brief Construct a new Output Wrapper object
     *
     * @param table_ reference to table to execute operations on
     */
    OutputWrapper(Table & table_);
    OutputWrapper(OutputWrapper & other) = delete;
    OutputWrapper & operator=(OutputWrapper & other) = delete;
    ~OutputWrapper();

    /**
     *@brief Print a single cell to the output stream
     *
     * @param os output stream to print to
     * @param cell cell to print
     * @param raw if true, print raw value
     * @param ex if true, print value in export format
     */
    void print_cell(std::ostream & os, Cell & cell, bool raw = false, bool ex = false) const;

    /**
     *@brief Print the whole table to the output stream
     *
     * @param os output stream to print to
     * @param raw if true, print raw value
     * @param single if true, prints only one value
     */
    void print(std::ostream & os, bool raw = false, bool single = false) const;

    /**
     *@brief Print a range of cells to the output stream
     *
     * @param os output stream to print to
     * @param address1 start address
     * @param address2 end address
     * @param raw if true, print raw value
     * @param single if true, prints only one value
     */
    void print(std::ostream & os, Address address1, Address address2, bool raw = false, bool single = false) const;

    /**
     *@brief Print individual cell to the output stream
     *
     * @param os output stream to print to
     * @param address1 address of the cell to print
     * @param raw if true, print raw value
     * @param single if true, prints only one value
     */
    void print(std::ostream & os, Address address1, bool raw = false, bool single = false) const;


    /**
     *@brief Export the whole table to the output stream
     *
     * @param os output stream to print to
     * @param raw if true, export raw values
     */
    void export_table(std::ostream & os, bool raw = false) const;

    /**
     *@brief Evaluate current cell
     *
     * @param cell cell to evaluate
     */
    void evaluate_cell(Cell & cell) const;
};