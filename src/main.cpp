#include <iostream>
#include "flowy_engine/flowy_engine.hpp"
#include "list_workflows/list_workflows.hpp"
#include "init/init.hpp"

int main(int argc, char* argv[]) {

    std::string cmds[] = {"list", "run", "init"};

    for (int i = 1; i < argc; i++) {
    
        std::string a(argv[i]);

        if (std::find(std::begin(cmds), std::end(cmds), a) == std::end(cmds)) {
            std::cerr << "[ERROR] Unknown command: " << a << "\n";
            continue;
        }

        if (a == "list") {

            ListWorkflows::list_all();

        } 
        
        if (a == "run") {

            if (i + 1 < argc) {

                FlowyEngine::runWorkflowByName(argv[i + 1]);
                i++; 

            } else {
                std::cerr << "[ERROR] No workflow name provided after 'run'\n";
            }

        } 

        if (a == "init") {
            
            Init::init();

        } 

    }

    if (argc == 1) {
        std::cout << "Usage:\n";
        std::cout << "  list           List all available workflows\n";
        std::cout << "  run <name>     Run a workflow by name\n";
        std::cout << "  init           Initialize the .flowy directory structure\n";
    }

    return 0;
}