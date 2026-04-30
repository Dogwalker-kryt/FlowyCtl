#pragma once

#include <string>
#include <vector>
#include <filesystem>
#include <str.hpp>
#include <fstream>

struct FlowyAction {
    str32_t type;
    str128_t command;
};

struct FlowyWorkflow {
    str32_t name;
    std::vector<FlowyAction> actions;
};

class JsonParser {
private:

    static std::string read_file(const std::filesystem::path& path);

    static std::string extract_string(const std::string& src, const std::string& key);

    static std::string extract_array_block(const std::string& src, const std::string& key);

    static std::vector<FlowyAction> parse_actions(const std::string& block);

    static FlowyAction parse_action(const std::string& obj);

public:
    static FlowyWorkflow parse(const std::filesystem::path& workflow_file);
};
