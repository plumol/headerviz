#include <vector>
#include <filesystem>
#include <string>
#include <iostream>
#include <fstream>

#include <graph/dependency_graph.h>
#include <cli/args_parser.h>
#include <parser/parser.h>

int create_graph(ParserResults* results, ArgParserResults* parsed) {
    // for (const auto& entry : results->includes) {
    //     for (const auto& include : entry.second) {
    //         std::cout << include << std::endl;
    //     }
    // }

    std::ofstream output(parsed->output_path);
    if (output.is_open()) {
        output << "digraph Dependencies {\n";

        // output << "size = \"100,100\"; \n";
        for (const auto& entry : results->files) {
            output << "\t" << entry << " [shape=box];\n"; // maybe we can control what shape users want
        }
        
        for (const auto& entry : results->includes) {
            output << "\t" << entry.first << " -> {";
            for (const auto& include : entry.second) {
                output << " \"" << include << "\"";
            }
            output << " };\n";
    }
        output << "}";
        output.close();
    }
    else {
        std::cerr << "Error opening the output path. \n";
    }

    return 0;
}
