/**
 * @author Jakub Feik <feikjaku@fit.cvut.cz>
 * @date 01.06.2023
 */

#include <map>
#include <memory>
#include <utility>

#include "Objects.hpp"

#include "../operations/functions/Abs.hpp"
#include "../operations/functions/Log.hpp"
#include "../operations/functions/Power.hpp"
#include "../operations/functions/Root.hpp"

#include "../operations/numbers/Add.hpp"
#include "../operations/numbers/Divide.hpp"
#include "../operations/numbers/Modulo.hpp"
#include "../operations/numbers/Multiply.hpp"
#include "../operations/numbers/Negate.hpp"
#include "../operations/numbers/Subtract.hpp"

#include "../operations/strings/StrAdd.hpp"
#include "../operations/strings/StrMultiply.hpp"

using namespace std;

Objects::Objects() {
    functions.insert({"ABS", Abs::create_operation});
    functions.insert({"LOG", Log::create_operation});
    functions.insert({"ROOT", Root::create_operation});
    functions.insert({"POW", Power::create_operation});

    operators.insert({"+", Add::create_operation});
    operators.insert({"-", Subtract::create_operation});
    operators.insert({"*", Multiply::create_operation});
    operators.insert({"/", Divide::create_operation});
    operators.insert({"%", Modulo::create_operation});

    operators.insert({"&", StrAdd::create_operation});
    operators.insert({"^", StrMultiply::create_operation});

    operators.insert({"#", Negate::create_operation});

    op_properties.insert({"+", {2, 0}});
    op_properties.insert({"-", {2, 0}});
    op_properties.insert({"*", {3, 0}});
    op_properties.insert({"/", {3, 0}});
    op_properties.insert({"%", {3, 0}});

    op_properties.insert({"^", {4, 1}});
    op_properties.insert({"&", {2, 0}});

    op_properties.insert({"ABS", {1, 0}});
    op_properties.insert({"LOG", {1, 0}});
    op_properties.insert({"ROOT", {1, 0}});
    op_properties.insert({"POW", {1, 0}});

    op_properties.insert({"#", {5, 1}});
}

Objects::~Objects() = default;

bool Objects::is_function(const string & token) const {
    return functions.find(token) != functions.end();
}

bool Objects::is_operator(const string & token) const {
    return operators.find(token) != operators.end();
}