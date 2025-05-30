#include <iostream>
#include <cli/args_parser.h>

int main(int argc, char* argv[]) {
    ArgParser parser;

    ArgParserResults parsed = parser.parse(argc, argv);

    std::cout << "Testing" << std::endl;
    std::cout << parsed.root_path << std::endl;
    return 0;
}
