#ifndef __TOKENIZER_H__
#define __TOKENIZER_H__

#include <vector>
#include <string>
#include <sstream>

#include "../Table/Table.h"

class Tokenizer
{
    private:
        

    public:
        void add_space(std::string& line);
        std::vector<std::string> token_list(std::string line);

};

#endif  // __TOKENIZER_H__