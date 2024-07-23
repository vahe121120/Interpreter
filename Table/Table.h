#ifndef __TABLE_H__
#define __TABLE_H__

#include <iostream>
#include <string>
#include <unordered_map>

#include "../Types/Types.h"

class Table
{
    private:
        std::unordered_map<std::string, std::string> tbl;
        std::string letters = "qwertyuiopasdfghjklzxcvbnm_QWERTYUIOPASDFGHJKLZXCVBNM";
        std::string digits = "0123456789";
        char quote = '\"';

    public:
        void set(std::string key, std::string value);
        std::unordered_map<std::string, std::string> get();
        std::size_t size() const;
        
};

// std::ostream& operator<<(std::ostream& out, Types* obj);

#endif  // __TABLE_H__