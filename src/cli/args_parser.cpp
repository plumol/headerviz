#include <iostream>
#include <string>
#include <../libs/CLI11.hpp>

#include <cli/args_parser.h>

ArgParserResults ArgParser::parse(int argc, char **argv) {
    ArgParserResults result;

    CLI::App app{"Header file visualizers"};

    std::string root_path = "";
    std::string output_path = "";
    app.add_option("-r, --root", root_path, "Root path")
        ->required()
        ->check(CLI::ExistingFile);
    app.add_option("-o, --out", output_path, "Output path");

    try { 
        (app).parse(argc, argv);
    }
    catch(const CLI::ParseError &e) { 
        std::cout << "An error has occured: " << e.what() << std::endl;
        return result; 
    }

    result.root_path = root_path;
    result.output_path = output_path;

    // std::cout << "Root path: " << root_path << std::endl;
    // std::cout << "Output path: " << output_path << std::endl;

    return result;

}
