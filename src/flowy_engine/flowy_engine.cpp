#include "flowy_engine.hpp"

std::filesystem::path FlowyEngine::getCWD() {
    return std::filesystem::current_path();
}

std::filesystem::path FlowyEngine::getFlowyRoot() {
    auto cwd = getCWD();
    return (cwd / ".flowy");
}

std::filesystem::path FlowyEngine::getWorkflowRoot() {
    auto flowy_root = getFlowyRoot();
    return (flowy_root / "workflows");
}

std::filesystem::path FlowyEngine::getWorkflow(const str32_t &name) {
    auto workflows = getWorkflowRoot();
    return (workflows / (std::string(name) + ".json"));
}

void FlowyEngine::execAction(const FlowyAction &action) {
    if (action.type == "shell") {
       auto res = run_cmd(action.command);

        if (res.exit_code == 0) {
            std::cout << res.stdout_str;
        } else {
            std::cerr << "[ERROR] Command exited with code " << res.exit_code << "\n";
            std::cerr << res.stdout_str;
        }
       std::cerr << res.stderr_str;
    }
}

void FlowyEngine::runWorkflow(const FlowyWorkflow &wf) {
    for (const auto& action : wf.actions) {
        execAction(action);
    }
}

void FlowyEngine::runWorkflowByName(const str32_t &name) {
    auto workflow_file = getWorkflow(name);

    std::ifstream file(workflow_file);
    if (!file.is_open()) {
        std::cerr << "[ERROR] Workflow file: " << workflow_file << " couldn't be opened\n";
        return;
    }

    FlowyWorkflow workflow = JsonParser::parse(workflow_file);
    runWorkflow(workflow);
}
