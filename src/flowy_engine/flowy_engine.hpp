#pragma once

#include <iostream>
#include <filesystem>
#include <fstream>
#include "../json_parser/json_parser.hpp"
#include "../cmd_execution/command_exec.h"

class FlowyEngine {
public:

    static std::filesystem::path getCWD();

    static std::filesystem::path getFlowyRoot();

    static std::filesystem::path getWorkflowRoot();

    static std::filesystem::path getWorkflow(const str32_t &name);

    static void runWorkflowByName(const str32_t &name); 

    static void runWorkflow(const FlowyWorkflow& wf);

    static void execAction(const FlowyAction &action);
       
};