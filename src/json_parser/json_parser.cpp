#include "json_parser.hpp"

std::string JsonParser::read_file(const std::filesystem::path& path) {
    std::ifstream file(path);
    std::stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}

std::string JsonParser::extract_string(const std::string& src, const std::string& key) {
    std::string pattern = "\"" + key + "\"";

    size_t key_pos = src.find(pattern);
    if (key_pos == std::string::npos) return "";

    size_t colon = src.find(':', key_pos);
    size_t first_quote = src.find('"', colon + 1);
    size_t second_quote = src.find('"', first_quote + 1);

    return src.substr(first_quote + 1, second_quote - first_quote - 1);
}

std::string JsonParser::extract_array_block(const std::string& src, const std::string& key) {
    size_t key_pos = src.find("\"" + key + "\"");
    if (key_pos == std::string::npos) return "";

    size_t start = src.find('[', key_pos);
    size_t end   = src.find(']', start);

    return src.substr(start + 1, end - start - 1);
}

std::vector<FlowyAction> JsonParser::parse_actions(const std::string& block) {
    std::vector<FlowyAction> actions;

    size_t pos = 0;
    while (true) {
        size_t obj_start = block.find('{', pos);
        if (obj_start == std::string::npos) break;

        size_t obj_end = block.find('}', obj_start);
        std::string obj = block.substr(obj_start, obj_end - obj_start);

        actions.push_back(parse_action(obj));

        pos = obj_end + 1;
    }

    return actions;
}

FlowyAction JsonParser::parse_action(const std::string& obj) {
    FlowyAction action;
    action.type = extract_string(obj, "type");
    action.command = extract_string(obj, "command");
    return action;
}


FlowyWorkflow JsonParser::parse(const std::filesystem::path& workflow_file) {
    std::string content = read_file(workflow_file);

    FlowyWorkflow workflow;
    workflow.name = extract_string(content, "name");

    std::string actions_block = extract_array_block(content, "actions");
    workflow.actions = parse_actions(actions_block);

    return workflow;
}