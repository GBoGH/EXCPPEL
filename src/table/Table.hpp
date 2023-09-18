/**
 * @author Jakub Feik <feikjaku@fit.cvut.cz>
 * @date 13.05.2023
 */

#pragma once

#include <map>
#include <memory>

#include "Address.hpp"
#include "../cell/Cell.hpp"
#include "../value/Value.hpp"



class Table {
public:
    std::map<Address, std::unique_ptr<Cell>> table; // Map of all cells

    Table();
    ~Table();

    /**
     *@brief Construct a new Table object
     *
     * @param other Table to copy
     */
    Table(const Table & other);
    /**
     *@brief Assignment operator
     *
     * @param other Table to copy
     * @return Table&
     */
    Table & operator=(Table other);

    /**
     *@brief Add cell to table based on address
     *
     * @param address Address of the added cell
     * @param cell Cell to add
     */
    void add_cell(const Address & address, const Cell & cell);

    /**
     *@brief Add cell to table based cell object
     *
     * @param cell Cell to add
     */
    void add_cell(const Cell & cell);

    /**
     *@brief Get the cell object based on address
     *
     * @param address Address of the cell
     * @return std::unique_ptr<Cell> Pointer to the cell
     */
    std::unique_ptr<Cell> get_cell(const Address & address) const;

    /**
     *@brief Get the cell object based on cell object
     *
     * @param cell Cell to get
     * @return std::unique_ptr<Cell> Pointer to the cell
     */
    std::unique_ptr<Cell> get_cell(const Cell & cell) const;

    /**
     *@brief Check if table contains cell with given address
     *
     * @param address Address to check
     * @return true if table contains cell with given address -
     * @return false otherwise
     */
    bool contains(const Address & address) const;

    /**
     *@brief Clears the whole table
     *
     */
    void clear();


    /**
     *@brief Clears a given address
     *
     * @param address1 Address to clear
     */
    void clear(const Address & address1);

    /**
     *@brief Clear a range of addresses
     *
     * @param address1 First address of the range
     * @param address2 Second address of the range
     */
    void clear(const Address & address1, const Address & address2);

};


// A4*5

