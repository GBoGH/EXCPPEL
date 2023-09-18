/**
 * @author Jakub Feik <feikjaku@fit.cvut.cz>
 * @date 13.05.2023
 */

#pragma once

#include <iostream>
#include <memory>
#include <string>
#include <utility>

#include "../utility/Utility.hpp"

 /**
  *@class Value
  *@brief Class representing value of a cell
 */
class Value {
public:
    std::string value; // Value of a cell as a string

    Value();
    ~Value();

    /**
     *@brief Construct a new Value object
     *
     * @param value_ Value of a cell as a string
     */
    Value(const std::string & value_);

    /**
     *@brief Construct a new Value object
     *
     * @param other Value to copy
     */
    Value(const Value & other);

    /**
     *@brief Assignment operator
     *
     * @param other value to assign
     * @return Value
     */
    Value & operator=(Value other);

    /**
     *@brief Creates a copy of Value
     *
     * @return std::unique_ptr<Value> pointer to a copy of Value
     */
    std::unique_ptr<Value> clone() const;

    /**
     *@brief Prints Value to os
     *
     * @param os output stream
     * @return std::ostream& output stream
     */
    // std::ostream & print(std::ostream & os) const;

    /**
     *@brief Overloaded operator<<
     *
     * @param os output stream
     * @param value Value to print
     * @return std::ostream&
     */
    // friend std::ostream & operator<<(std::ostream & os, Value & value);

    /**
     *@brief Get numerical representation of Value
     *
     * @return double numerical representation of Value
     */
    double get_num() const;

    /**
     *@brief Check if Value represents a number
     *
     * @return std::string
     */
    std::string represents_number() const;

    /**
     *@brief Get the string representation of Value
     *
     * @return std::string
     */
    std::string get_str() const;

    /**
     *@brief Get the raw string representation of Value - with quotes
     *
     * @return std::string
     */
    std::string get_raw_str() const;

};

