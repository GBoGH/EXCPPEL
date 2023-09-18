/**
 * @author Jakub Feik <feikjaku@fit.cvut.cz>
 * @date 01.06.2023
 */

#pragma once

#include <string>

 /**
  *@brief Namespace for utility functions
  *
 */
namespace Utility {

/**
 *@brief Checks if a double is an integer
*
* @param num number to check
* @return true if num is an integer -
* @return false otherwise
*/
bool is_integer(double num);

/**
 *@brief Checks if a string is a valid address
 *
 * @param str string to check
 * @return true if str is a valid address -
 * @return false otherwise
 */
bool valid_address(const std::string & str);

/**
 *@brief Checks if a string is a valid range
 *
 * @param str string to check
 * @return true if str is a valid range -
 * @return false otherwise
 */
bool valid_range(const std::string & str);


/**
 *@brief Checks if a string represents a number
 *
 * @param str string to check
 * @return true if str represents a number -
 * @return false otherwise
 */
bool valid_number(const std::string & str);

/**
 *@brief Checks if a string represents a number or is empty
 *
 * @param str string to check
 * @return true if str represents a number or is empty -
 * @return false otherwise
 */
bool can_be_number(const std::string & str);

/**
 *@brief Checks if a string is a valid string - starts and ends with "
 *
 * @param str string to check
 * @return true if str is a valid string -
 * @return false otherwise
 */
bool valid_string(const std::string & str);

/**
 *@brief Removes spaces from a string according to the rules of the assignment
 *
 * @param str string to remove spaces from
 * @return std::string string without spaces
 */
std::string remove_spaces(const std::string & str);

/**
 *@brief Removes duplicate spaces from a string
 *
 * @param str string to remove spaces from
 * @return std::string string without duplicate spaces
 */
std::string remove_dup_spaces(const std::string & str);

/**
 *@brief Trims a string - removed " and whitespaces from the beginning and end
 *
 * @param str string to trim
 * @param charset characters to trim
 * @return std::string trimmed string
 */
std::string trim_char(std::string str, std::string charset = "");


/**
 *@brief Normalizes a string - removes duplicate spaces and trims it
 *
 * @param str string to normalize
 * @return std::string normalized string
 */
std::string normalize(const std::string & str);

/**
 *@brief Capitalizes a string
 *
 * @param str string to capitalize
 */
void capitalize(std::string & str);


}