#include "list_workflows.hpp"
#include <iostream>
#include <filesystem>

void ListWorkflows::list_all() {
    auto workflow_dir = FlowyEngine::getWorkflowRoot();

    try {

        for (const auto& workflow : std::filesystem::directory_iterator(workflow_dir)) {
            std::cout << workflow.path().filename().string() << std::endl;
        }

    } catch (const std::exception& e) {
        
        std::cerr << "Error: " << e.what() << "\n";

    }
}