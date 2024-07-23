#include "./Table.h"

void Table::set(std::string key, std::string value)
{
    // Checking variable name correctness
    if ( letters.find(key[0]) == std::string::npos )
    {
        std::cerr << "Invalid identifer." << std::endl
        << "Identifier name must be [a-z], [A-Z], [_]"
        << std::endl;
        throw;
    }

    // Checking if value is variable, and if it is, then
    // does it valid or not
    if ( letters.find(value[0]) != std::string::npos )
    {
        if ( value != "True" && value != "False" )
        {
            // If undefined throw error
            if ( tbl.find(value) == tbl.end() )
            {
                std::cerr << "Undefined variable: " << value << std::endl;
                throw;
            }
        }

        // if consists, then "value = var.value"
        for ( const auto& kv : tbl )
        {
            if ( kv.first == value )
            {
                value = kv.second;
            }
        }
    }
    
    // Setting String
    if ( value[0] == quote && value[value.size() - 1] == quote )
    {
        // std::cout << "MTAV String" << std::endl;
        String* str = new String(value);
        tbl[key] = {str->get()};
    }

    // Setting Int
    if ( digits.find(value) != std::string::npos )
    {
        // std::cout << "MTAV INT" << std::endl;
        Int* str = new Int(value);
        tbl[key] = {str->get()};
    }

    // Setting Double
    if ( ( digits.find(value) && digits.find('.') ) != std::string::npos )
    {
        // std::cout << "MTAV Double" << std::endl;
        Double* str = new Double(value);
        tbl[key] = {str->get()};
    }

    // Setting Bool
    if ( value == "True" || value == "False" )
    {
        // std::cout << "MTAV Bool" << std::endl;
        Bool* str = new Bool(value);
        tbl[key] = {str->get()};
    }
}

std::unordered_map<std::string, std::string> Table::get()
{
    
    // if ( tbl.find(name) == tbl.end() )
    // {
    //     std::cerr << "Undefined variable" << std::endl;
    //     throw;
    // }
    return tbl;
}

std::size_t Table::size() const
{
    return tbl.size();
}