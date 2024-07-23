#ifndef __RESOLVE_EXPRESSION__
#define __RESOLVE_EXPRESSION__

#include <vector>
#include <string>
#include <iostream>

#include "../Table/Table.h"

class ResolveExpression
{
    public:
        void mul(std::vector<std::string>& vtmp);
        void divide(std::vector<std::string>& vtmp);
        void add(std::vector<std::string>& vtmp);
        void sub(std::vector<std::string>& vtmp);
        void mod(std::vector<std::string>& vtmp);
        std::string resolve(const std::vector<std::string>& line, const Table& tbl);
    private:
        int value;
};

#endif  // __RESOLVE_EXPRESSION__