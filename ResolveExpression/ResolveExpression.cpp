#include "./ResolveExpression.h"

void ResolveExpression::mul(std::vector<std::string>& vtmp)
{
    int lv{};
    int rv{};
    for ( int i = 0; i < vtmp.size(); ++i )
    {
        if ( vtmp[i] == "*" )
        {
            lv = std::stoi(vtmp[i - 1]);
            rv = std::stoi(vtmp[i + 1]);
            this->value = lv * rv;
            vtmp.erase(vtmp.begin() + i - 1, vtmp.begin() + i + 2);
            vtmp.insert(vtmp.begin() + i - 1, std::to_string(this->value));
            break;
        }
    }
}

void ResolveExpression::divide(std::vector<std::string>& vtmp)
{
    int lv{};
    int rv{};
    for ( int i = 0; i < vtmp.size(); ++i )
    {
        if ( vtmp[i] == "/" )
        {
            lv = std::stoi(vtmp[i - 1]);
            rv = std::stoi(vtmp[i + 1]);
            this->value = lv / rv;
            vtmp.erase(vtmp.begin() + i - 1, vtmp.begin() + i + 2);
            vtmp.insert(vtmp.begin() + i - 1, std::to_string(this->value));
            break;
        }
    }
}

void ResolveExpression::add(std::vector<std::string>& vtmp)
{
    int lv{};
    int rv{};
    for ( int i = 0; i < vtmp.size(); ++i )
    {
        if ( vtmp[i] == "+" )
        {
            lv = std::stoi(vtmp[i - 1]);
            rv = std::stoi(vtmp[i + 1]);
            this->value = lv + rv;
            vtmp.erase(vtmp.begin() + i - 1, vtmp.begin() + i + 2);
            vtmp.insert(vtmp.begin() + i - 1, std::to_string(this->value));
            break;
        }
    }
}

void ResolveExpression::sub(std::vector<std::string>& vtmp)
{
    int lv{};
    int rv{};
    for ( int i = 0; i < vtmp.size(); ++i )
    {
        if ( vtmp[i] == "-" )
        {
            lv = std::stoi(vtmp[i - 1]);
            rv = std::stoi(vtmp[i + 1]);
            this->value = lv - rv;
            vtmp.erase(vtmp.begin() + i - 1, vtmp.begin() + i + 2);
            vtmp.insert(vtmp.begin() + i - 1, std::to_string(this->value));
            break;
        }
    }
}

void ResolveExpression::mod(std::vector<std::string>& vtmp)
{
    int lv{};
    int rv{};
    for ( int i = 0; i < vtmp.size(); ++i )
    {
        if ( vtmp[i] == "%" )
        {
            lv = std::stoi(vtmp[i - 1]);
            rv = std::stoi(vtmp[i + 1]);
            this->value = lv % rv;
            vtmp.erase(vtmp.begin() + i - 1, vtmp.begin() + i + 2);
            vtmp.insert(vtmp.begin() + i - 1, std::to_string(this->value));
            break;
        }
    }
}

std::string ResolveExpression::resolve(const std::vector<std::string>& line, const Table& tbl)
{
    std::string result;
    std::vector<std::string> vtmp;
    std::string tmp;
    for ( const auto& val : line )
    {
        if ( val != " " )
            vtmp.push_back(val);
        //tmp += val;
    }
    vtmp.erase(vtmp.begin(), vtmp.begin() + 2);

    // Printing temporary vector
    for ( const auto val : vtmp )
    {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    int m{};    // mul
    int d{};    // div
    int a{};    // add
    int s{};    // sub
    while ( vtmp.size() != 1 )
    {
        for ( const auto val : vtmp )
        {
            tmp += val;
        }

        m = tmp.find('*');
        d = tmp.find('/');
        a = tmp.find('+');
        s = tmp.find('-');

        if ( m != -1 || d != -1 )
        {
            if ( m > d && d != -1 || m == -1 ) divide(vtmp);
            //std::cout << this->value << std::endl;
            
            // // For PRINTING
            // for ( const auto val : vtmp )
            // {
            //     std::cout << val << " ";
            // }
            // std::cout << std::endl;

            if ( m ) mul(vtmp);
            std::cout << this->value << std::endl;
        }
        if ( a != -1 || s != -1 )
        {
            if ( a > s && s != -1 || a == -1 ) sub(vtmp);

            std::cout << this->value << std::endl;
            
            // // For PRINTING
            // for ( const auto val : vtmp )
            // {
            //     std::cout << val << " ";
            // }
            // std::cout << std::endl;

            if( a ) add(vtmp);

            std::cout << this->value << std::endl;
        }
    }

    return std::to_string(this->value);
}