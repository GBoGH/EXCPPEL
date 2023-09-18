/**
 * @author Jakub Feik <feikjaku@fit.cvut.cz>
 * @date 02.06.2023
 */

#include <map>
#include <memory>
#include <utility>

#include "CommandRegistry.hpp"

#include "../commands/cells/AssignConstant.hpp"
#include "../commands/cells/AssignFormula.hpp"
#include "../commands/cells/Clear.hpp"

#include "../commands/console/Print.hpp"
#include "../commands/console/Dump.hpp"

#include "../commands/file/FileExport.hpp"
#include "../commands/file/FileImport.hpp"

#include "../commands/console/Exit.hpp"

CommandRegistry::CommandRegistry() {
    commands.insert({"=", AssignConstant::create_command});
    commands.insert({":=", AssignFormula::create_command});

    commands.insert({"CLEAR", Clear::create_command});
    commands.insert({"PRINT", Print::create_command});
    commands.insert({"DUMP", Dump::create_command});

    commands.insert({"EXPORT", FileExport::create_command});
    commands.insert({"IMPORT", FileImport::create_command});

    commands.insert({"EXIT", Exit::create_command});
}

CommandRegistry::~CommandRegistry() = default;