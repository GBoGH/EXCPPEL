/**
 * @author Jakub Feik <feikjaku@fit.cvut.cz>
 * @date 01.06.2023
 */


#include <iostream>
#include <string>
#include <stack>

#include "FormulaParser.hpp"
#include "../operations/Evaluate.hpp"
#include "../cell/Formula.hpp"
#include "../utility/Utility.hpp"

using namespace std;

FormulaParser::FormulaParser(const string & expr_, Objects & obj_) :
    Parser(expr_),
    obj(obj_) {
    load_operators();
}

FormulaParser::~FormulaParser() = default;

void FormulaParser::load_operators() {
    for (auto & op : obj.operators) {
        token_sep += op.first;
    }
}


// string FormulaParser::get_RPN() const {
//     return RPN;
// }

void FormulaParser::next_token(string & expr, size_t & pos, string & token, string & op) {
    size_t next_separator = expr.find_first_of(token_sep, pos);

    // Token covers the rest of the expression
    if (next_separator == string::npos) {
        token = expr.substr(pos);
        op = "";
        pos = expr.size();
        return;
    }

    token = expr.substr(pos, next_separator - pos);


    if (token[0] == '"' && !Utility::valid_string(token)) {
        // If token if within a string, get the complete string
        size_t next_quote = expr.find_first_of('"', next_separator);
        token = expr.substr(pos, next_quote - pos + 1);

        // When the string is the last token, there is no operator
        if (next_quote == expr.size() - 1) {
            op = "";
        } else {
            op = expr[next_quote + 1];
        }
        pos = next_quote + 2;
    } else {
        pos = next_separator + 1;
        op = expr[next_separator];
    }
}

void FormulaParser::function_handler(string & token, string & op) {
    if (obj.is_function(token)) {
        if (op != "(") {
            // Eg sin-(1)
            throw invalid_argument("Invalid argument");
        }
        op_stack.push(token);
    } else {
        if (Utility::valid_address(token) ||
            Utility::valid_number(token) ||
            Utility::valid_string(token)) {
            RPN += token;
            RPN += " ";
        } else if (!token.empty()) {
            // Token is an invalid value
            throw invalid_argument("Invalid argument");
        }
    }
}


void FormulaParser::operator_handler(string & token, string & op, string & prev) {
    if ((obj.is_operator(prev) || prev == "(" || prev == "," || prev.empty()) && op == "-" && token.empty()) {
        // Determining if the minus is unary or binary
        op = "#";
    }

    if (obj.is_operator(op)) {
        auto o1 = obj.op_properties.find(op);
        while (!op_stack.empty()) {
            auto o2 = obj.op_properties.find(op_stack.top());
            if (o1 == obj.op_properties.end()
                || (o2 == obj.op_properties.end() && op_stack.top() != "(")) {
                throw invalid_argument("Invalid argument");
            }

            if (op_stack.top() == "(" ||
                !(o2->second.precedence > o1->second.precedence ||
                    (o2->second.precedence == o1->second.precedence &&
                        o1->second.associativity == 0))) {
                // Conditions according to the shunting-yard algorithm
                break;
            }

            RPN += op_stack.top();
            RPN += " ";
            op_stack.pop();

        }
        op_stack.push(op);
    }
}

void FormulaParser::comma_handler(string & op) {
    while (!op_stack.empty() && op_stack.top() != "(") {
        RPN += op_stack.top();
        RPN += " ";
        op_stack.pop();
    }
}

void FormulaParser::parenthesis_handler(string & op) {
    while (!op_stack.empty() && op_stack.top() != "(") {
        RPN += op_stack.top();
        RPN += " ";
        op_stack.pop();
    }

    if (!op_stack.empty() && op_stack.top() == "(") {
        op_stack.pop();
    } else {
        throw invalid_argument("Mismatched parentheses");
    }

    if (!op_stack.empty() && obj.is_function(op_stack.top())) {
        RPN += op_stack.top();
        RPN += " ";
        op_stack.pop();
    }

}

void FormulaParser::parse() {
    expression = Utility::remove_spaces(expression);

    size_t pos = 0;

    string token;
    string op;

    string prev_op = "";

    RPN = "";

    while (pos < expression.size()) {
        next_token(expression, pos, token, op);

        function_handler(token, op);
        operator_handler(token, op, prev_op);

        if (op == ",") {
            comma_handler(op);
        } else if (op == "(") {
            op_stack.push(op);
        } else if (op == ")") {
            parenthesis_handler(op);
        } else {
            if (!obj.is_operator(op) && !obj.is_function(token) && !op.empty()) {
                throw invalid_argument("Invalid operator");
            }
        }
        prev_op = op;

    }
    while (!op_stack.empty()) {
        // Pop the rest of the stack
        if (op_stack.top() == "(" || op_stack.top() == ")") {
            throw invalid_argument("Mismatched parentheses");
        }

        RPN += op_stack.top();
        RPN += " ";
        op_stack.pop();
    }

}

// string FormulaParser::generate_RPN(const string & expr) {
//     expression = expr;
//     parse();
//     return RPN;
// }


void FormulaParser::assign_to_cell(const Address & address, Table & table) {
    Formula f = Formula(address, expression, RPN);
    unique_ptr<Value> result = Evaluate::eval(f, table, RPN, obj);
    f.assign_value(result);

    //Print the expression result
    f.print(cout);
    cout << endl;
    table.add_cell(f);

}
