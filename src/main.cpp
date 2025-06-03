#include <iostream>

#include <cli/args_parser.h>
#include <parser/parser.h>
#include <graph/dependency_graph.h>

int main(int argc, char* argv[]) {
    ArgParser parser;
    ParserResults results;

    ArgParserResults parsed = parser.parse(argc, argv);

    recursive_search(&results, &parsed);
    map_includes(&results);

    std::cout << "Create graph process: " << std::endl;
    create_graph(&results, &parsed);
    // std::cout << "Testing" << std::endl;
    // std::cout << parsed.root_path << std::endl;
    return 0;
}
