/**
 * @author Jakub Feik <feikjaku@fit.cvut.cz>
 * @date 01.06.2023
 */

#include <cmath>
#include <string>
#include <regex>
#include <algorithm>
#include <cstdlib>
#include <cctype>
#include <iostream>

using namespace std;

#include "Utility.hpp"

bool Utility::is_integer(double num) {
    return num == static_cast<long long int>(num);
}

bool Utility::valid_address(const string & str) {
    // Max two columns and two rows
    std::regex pattern("^[A-Z]{1,2}[0-9]{1,2}$");
    return std::regex_match(str, pattern);
}

bool Utility::valid_range(const string & str) {
    // Two addresses separated by colon
    std::regex pattern("^[A-Z]{1,2}[0-9]{1,2}:[A-Z]{1,2}[0-9]{1,2}$");
    return std::regex_match(str, pattern);
}

bool Utility::valid_number(const string & str) {
    if (str.find_first_not_of("0123456789.-") != string::npos) {
        return false;
    }
    try {
        stod(str);
        return true;
    } catch (const invalid_argument & e) {
        return false;
    }
}

bool Utility::can_be_number(const string & str) {
    return str.empty() || valid_number(str);
}

bool Utility::valid_string(const string & str) {
    if (str.length() < 2) {
        return false;
    }
    return str[0] == '"' && str[str.length() - 1] == '"';
}


void Utility::capitalize(string & str) {
    transform(str.begin(), str.end(), str.begin(), ::toupper);
}


string Utility::remove_spaces(const string & expr) {
    // Remove duplicate spaces before =
    // Remove all spaces after =  except for those between numbers

    string result;
    bool in_string = false;
    bool in_space = false;
    bool in_formula = false;

    for (auto & c : expr) {
        if (c == '"') {
            in_string = !in_string;
        }
        if (!in_formula) {
            if(isspace(c) && !in_string && isspace(result.back())) {
                continue;
            }
            if (c == '=' && !in_string) {
                in_formula = true;
            }
            result += c;
            continue;
        }

        if (isspace(c) && !in_string) {
            in_space = true;
            continue;
        }

        if (isdigit(result.back()) &&
            isdigit(c) &&
            in_space) {
            result += " ";
        }
        in_space = false;
        result += c;
    }
    return result;
}

string Utility::remove_dup_spaces(const string & str) {
    string result;
    bool in_string = false;
    for (auto & c : str) {
        if (c == '"') {
            in_string = !in_string;
        }
        if (isspace(c) && !in_string) {
            if (result.length() > 0 && isspace(result.back())) {
                continue;
            }
        }
        result += c;
    }
    return result;
}

string Utility::trim_char(string str, string charset /*= " "*/) {
    if (isspace(str.front()) || charset.find(str.front()) != string::npos) {
        str = str.substr(1);
    }
    if (isspace(str.back()) || charset.find(str.back()) != string::npos ) {
        str.pop_back();
    }
    return str;
}

string Utility::normalize(const string & str) {
    return trim_char(remove_dup_spaces(str));
}
