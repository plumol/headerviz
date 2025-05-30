#ifndef ARG_PARSER_HPP
#define ARG_PARSER_HPP

#include <string>

struct ArgParserResults {
    std::string root_path;
    std::string output_path = "deps.dot";
    bool exclude_system_includes = false;
    bool render = false;
    bool metrics = false;
};

class ArgParser {
    public:
        static ArgParserResults parse(int argc, char **argv);
};


#endif
