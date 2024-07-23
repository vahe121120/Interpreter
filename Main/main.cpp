/*
    This is a new programming language, with dynamic typing.
    Documentation consists in README.txt file.
    Name: "FastScript"
    Author: "Vahe Harutyunyan"
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

#include "../Parser/Parser.h"


// This functions are in 'check_functions.cpp' file in the same
// directory 'Main', it must be compiled with our executable files

void error(const char* msg);
void arg_cnt(int cnt);
void file_opened(std::ifstream& file);
void ext(std::string fname);

// --------------------------------

int main(int argc, char* argv[])
{
    arg_cnt(argc);
    std::ifstream src(argv[1], std::ios::in);
    file_opened(src);
    ext(argv[1]);

    Parser pars;
    pars.slice_line(src);

    return 0;
}