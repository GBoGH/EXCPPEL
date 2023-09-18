/**
 * @author Jakub Feik <feikjaku@fit.cvut.cz>
 * @date 02.06.2023
 */

#include <string>

#include "Parser.hpp"

using namespace std;

Parser::Parser(const string & expr_) :
    expression(expr_) {}

Parser::~Parser() = default;