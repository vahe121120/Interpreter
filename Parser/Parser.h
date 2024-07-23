#ifndef __PARSER_H__
#define __PARSER_H__

#include <string>
#include <fstream>
#include <iostream>
#include <unordered_map>

#include "../Tokenizer/Tokenizer.h"

class Parser
{
    private:
        std::string line;
        Table tbl;

    public:
        void slice_line(std::ifstream& file);
};

#endif  // __PARSER_H__