#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>

void error(const char* msg)
{
    fputs(msg, stderr);
    fputc('\n', stderr);
    exit(EXIT_FAILURE);
}

void arg_cnt(int cnt)
{
    if ( cnt < 2 )
    {
        error("Wrong arguments count!");
    }
}

void file_opened(std::ifstream& file)
{
    if ( !file.is_open() )
    {
        error("Failed to open the file!");
    }
}

void ext(std::string fname)
{
    // std::string ex = fname.substr(fname.size() - 3);
    if ( fname.substr(fname.size() - 3) != ".fs" )
    {
        error("fs can work only with file which extension is '.fs'!");
    }
}