#include <iostream>

#include <cli/args_parser.h>
#include <parser/parser.h>

int main(int argc, char* argv[]) {
    ArgParser parser;
    ParserResults results;

    ArgParserResults parsed = parser.parse(argc, argv);

    recursive_search(&results, parsed);
    // std::cout << "Testing" << std::endl;
    // std::cout << parsed.root_path << std::endl;
    return 0;
}
