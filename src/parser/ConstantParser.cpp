/**
 * @author Jakub Feik <feikjaku@fit.cvut.cz>
 * @date 02.06.2023
 */

#include <string>

#include "../cell/NumConstant.hpp"
#include "../cell/StrConstant.hpp"

#include "ConstantParser.hpp"

using namespace std;

ConstantParser::ConstantParser(const string & expr_) :
    Parser(expr_) {}

ConstantParser::~ConstantParser() = default;


bool ConstantParser::is_string() const {
    return expression.front() == '"' && expression.back() == '"';
}

void ConstantParser::parse() {
    if (is_string()) {
        numeric = false;
    } else {
        try {
            double result = stod(expression);
            numeric = true;
            numeric_value = result;
        } catch (const invalid_argument & e) {
            throw invalid_argument("Invalid constant");
        }
    }
}

void ConstantParser::assign_to_cell(const Address & address, Table & table) {
    if (numeric) {
        NumConstant cell = NumConstant(address, numeric_value);
        table.add_cell(address, cell);
    } else {
        StrConstant cell = StrConstant(address, expression);
        table.add_cell(address, cell);
    }
}
