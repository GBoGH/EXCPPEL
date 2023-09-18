/**
 * @author Jakub Feik <feikjaku@fit.cvut.cz>
 * @date 13.05.2023
 */

#pragma once

#include <string>

/**
 * @class Address
 * @brief Class representing address of a cell in a table
 */
class Address {
public:
    std::string column;
    int row;

    Address();

    /**
     *@brief Construct a new Address object
     *
     * @param column
     * @param row
     */
    explicit Address(const std::string & column, int row);

    /**
     * @brief Construct a new Address object
     *
     * @param address string representation of address
     */
    explicit Address(const std::string & address);

    /**
     *@brief Construct a new Address object
     *
     * @param other Address to copy
     */
    Address(const Address & other);

    /**
     * @brief Assignment operator
     *
     * @param other Address to copy
     * @return Address& Reference to new Address
     */
    Address & operator=(Address other);

    /**
     * @brief Destroy the Address object
     *
     */
    ~Address();


    /**
     *@brief Comparison operator for sorting
     *
     * @param lhs Address to compare
     * @param rhs Address to compare
     * @return true if lhs < rhs -
     * @return false otherwise
     */
    friend bool operator<(const Address & lhs, const Address & rhs);

    /**
     *@brief Equality operator
     *
     * @param lhs
     * @param rhs
     * @return true if lhs == rhs -
     * @return false otherwise
     */
    friend bool operator==(const Address & lhs, const Address & rhs);


    /**
     *@brief Get first and last address of a range
     *
     * @param first Address 1
     * @param second Address 2
     * @return std::pair<Address, Address> Range in correct order
     */
    static std::pair<Address, Address> get_range(Address first, Address  second);

    /**
     *@brief Split a string representation of a range into two addresses
     *
     * @param range string representation of a range
     * @return std::pair<Address, Address>
     */
    static std::pair<Address, Address> split_range(const std::string & range);

    /**
     *@brief Print address to output stream
     *
     * @param os output stream
     * @param address Address to print
     * @return std::ostream&
     */
    friend std::ostream & operator<<(std::ostream & os, const Address & address);


};
