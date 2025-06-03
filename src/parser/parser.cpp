#include <filesystem>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <regex>

#include <parser/parser.h>
#include <cli/args_parser.h> // using the ArgParser struct

std::string file_extensions[4] = {".cpp", ".h", ".hpp", ".c"};

int recursive_search(ParserResults* results, ArgParserResults* parsed) {
    std::filesystem::path root_path = parsed->root_path;

    std::deque<std::filesystem::path> dir_queue;
    dir_queue.push_back(root_path);


    std::cout << "File system parser entry: " << root_path << std::endl;

    // Currently operates on a DFS approach for searching through directories
    while (dir_queue.size() != 0){
        auto next_dir = dir_queue.front();
        dir_queue.pop_front();

        for (const auto& entry : std::filesystem::directory_iterator(next_dir)) {
            // std::cout << entry.path() << std::endl; // optional: prints current path

            if (entry.is_directory()) {
                dir_queue.push_back(entry);
                continue;
            }
            
            // optional: prints file extension
            // std::cout << entry.path().extension() << std::endl;

            std::string* valid = std::find(file_extensions, std::end(file_extensions), entry.path().extension());
            if (valid != std::end(file_extensions)) {
                // std::cout << entry.path().extension() << " is a valid extension!" << std::endl;
                results->files.push_back(entry.path());
            }

        }

        // optional: lists next directories
        // for (const auto& entry : dir_queue) {
        //     std::cout << "Next dir: " << entry << std::endl;
        // }
        // std::cout << "Next dir: " << dir_queue.front() << std::endl;

    }

    std::cout << "Found: " << std::endl;
    for (const auto& entry : results->files) {
        std::cout << entry << std::endl;
    }
    
    return 0;
}

int map_includes(ParserResults* results) {
    // std::filesystem::path test_path = "../src/cli/args_parser.cpp";
    
    std::regex r(R"(^#include(\s*)+[<"]([^">]+)[">])");

    for (const auto& fp : results->files) {
        std::string line;
        std::ifstream file_path(fp);

        while (std::getline(file_path, line)) {
            std::smatch match;
            if (std::regex_search(line, match, r)) {
                std::cout << line << std::endl;
                std::cout << match[2].str() << std::endl;
                results->includes[fp].push_back(match[2].str());
            }
        }

        file_path.close();
    }

    return 0;
}
