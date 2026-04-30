#include <iostream>
#include "flowy_engine/flowy_engine.hpp"
#include "list_workflows/list_workflows.hpp"

int main(int argc, char* argv[]) {

    for (int i = 1; i < argc; i++) {
    
        if (std::string(argv[i]) == "list") {

            ListWorkflows::list_all();

        } else if (std::string(argv[i]) == "run") {

            if (i + 1 < argc) {

                FlowyEngine::runWorkflowByName(argv[i + 1]);
                i++; // Skip the next argument since it's the workflow name

            } else {

                std::cerr << "[ERROR] No workflow name provided after 'run'\n";

            }

        } else {

            std::cerr << "[ERROR] Unknown command: " << argv[i] << "\n";

        }
    }
}