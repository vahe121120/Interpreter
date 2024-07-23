#include "./Tokenizer.h"

void Tokenizer::add_space(std::string& line)
{
    if ( line.find("=") != std::string::npos )
    {
        int index = line.find("=");
        line.insert(index, " ");
        line.insert(index + 2, " ");
    }
    if ( line.find("+") != std::string::npos )
    {
        int index = line.find("+");
        line.insert(index, " ");
        line.insert(index + 2, " ");
    }
    if ( line.find("-") != std::string::npos )
    {
        int index = line.find("-");
        line.insert(index, " ");
        line.insert(index + 2, " ");
    }
    if ( line.find("*") != std::string::npos )
    {
        int index = line.find("*");
        line.insert(index, " ");
        line.insert(index + 2, " ");
    }
    if ( line.find("/") != std::string::npos )
    {
        int index = line.find("/");
        line.insert(index, " ");
        line.insert(index + 2, " ");
    }
    if ( line.find("{") != std::string::npos )
    {
        int index = line.find("{");
        line.insert(index, " ");
        //line.insert(index + 2, " ");
    }
    if ( line.find("}") != std::string::npos )
    {
        int index = line.find("}");
        line.insert(index, " ");
        //line.insert(index + 2, " ");
    }
}

std::vector<std::string> Tokenizer::token_list(std::string line)
{
    std::vector<std::string> vec;
    std::istringstream slice(line);
    std::string word;
    while ( slice >> word )
    {
        vec.push_back(word);
    }
    return vec;
}