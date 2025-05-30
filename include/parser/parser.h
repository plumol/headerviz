#ifndef PARSER_HPP
#define PARSER_HPP

#include <vector>
#include <filesystem>
#include <unordered_map>

#include <cli/args_parser.h>

struct ParserResults {
    std::vector<std::filesystem::path> files;
    std::unordered_map<std::filesystem::path, std::vector<std::string>> includes;
};


int recursive_search(ParserResults* results, ArgParserResults parsed);

#endif
