#include "./Parser.h"
#include "../CheckOperator/CheckOperator.h"

void Parser::slice_line(std::ifstream& file)
{
    std::vector<std::string> line_t;    // one line's tokens 
    Tokenizer tokens;
    CheckOperator chop;
    while ( file.good() )
    {
        std::getline(file, line);
        tokens.add_space(line);
        line_t = tokens.token_list(line);

        // Add line for expression resolving
        chop.check_operator(line_t, tbl);

        tbl.set(line_t[0], line_t[2]);
    }
    
    // For printing...
    for ( const auto& kv : tbl.get() )
    {
        std::cout << "Variable name: " << kv.first << std::endl;
        std::cout << "Variable value: " << kv.second << std::endl;
    }
}