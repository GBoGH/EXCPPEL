/**
 * @author Jakub Feik <feikjaku@fit.cvut.cz>
 * @date 03.06.2023
 */

#pragma once

#include <iostream>
#include <memory>
#include <stack>

#include "Operation.hpp"
#include "../cell/Cell.hpp"
#include "../objects/Objects.hpp"
#include "../table/Table.hpp"
#include "../utility/Utility.hpp"
#include "../value/Value.hpp"

 /**
  *@class Evaluate
  *@brief Class for evaluating a formula. This class is used to evaluate a formula in RPN. To evaluate a formula, use the eval method.
 */
class Evaluate {
public:
    Evaluate() = delete;
    ~Evaluate() = delete;

    /**
     *@brief Evaluates a formula
     *
     * @param cell cell to evaluate
     * @param table table to evaluate the formula on
     * @param RPN formula in RPN
     * @param obj objects to use
     * @return std::unique_ptr<Value> result of the evaluation
     */
    static std::unique_ptr<Value> eval(Cell & cell, Table & table, const std::string & RPN, const Objects & obj);

    /**
     *@brief Function to check formula dependencies
     *
     * @param address address of the cell to check
     * @param original_address address of the original cell
     * @param table table to check the dependencies in
     */
    static void check_dependencies(const Address & address, const Address & original_address, const Table & table);

    /**
     *@brief Function to evaluate dependencies
     *
     * @param cell cell to evaluate
     * @param target_address address of the cell to evaluate
     * @param table table to evaluate the formula on
     * @param obj objects to use
     * @param values stack of values to use
     */
    static void eval_dependencies(Cell & cell, const Address & target_address, Table & table, const Objects & obj, std::stack<std::unique_ptr<Value>> & values);

};



