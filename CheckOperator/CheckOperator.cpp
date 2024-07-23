#include "./CheckOperator.h"

void CheckOperator::check_operator(std::vector<std::string>& str, const Table& tbl)
{
    int cnt{};

    // Simple initialization or assignment
    if ( str.size() == 3 && str[1] == "=" ) return;

    // Invalid size of operation check
    if ( str.size() < 3 )
    {
        std::cerr << "Invalid operation" << std::endl;
        throw std::exception();
    }

    // if, while, for checker
    if ( (++cnt, str[0] == "if") || (++cnt, str[0] == "while") || (++cnt, str[0] == "for") )
    {
        switch ( cnt )
        {
            // if statement
            case 1:
                // call class thats responsible for if statement
                std::cout << "call class thats responsible for if statement" << std::endl;
                break;
            case 2:
                // call class thats responsible for while statement
                std::cout << "call class thats responsible for while statement" << std::endl;
                break;
            case 3:
                // call class thats responsible for for statement
                std::cout << "call class thats responsible for for statement" << std::endl;
                break;
        }
        return;
    }

    // Expression resolver
    if ( str[1] == "=" )
    {
        str[2] = res_exp.resolve(str, tbl);
    }

    // Invalid operation check
    if ( str.size() == 3 && str[1] != "=" )
    {
        std::cerr << "Invalid operation" << std::endl;
    }
}