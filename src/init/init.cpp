#include "init.hpp"


void Init::init() {

    std::filesystem::create_directory(".flowy");

    // create workflow dir in .flowy
    std::filesystem::create_directory(".flowy/workflows");

    // create a workflow.json file in .flowy/workflows
    std::filesystem::path workflow_path = FlowyEngine::getWorkflowRoot() / "example_workflow.json";

}
