#ifndef __CHECK_OPERATOR__
#define __CHECK_OPERATOR__

#include <string>
#include <vector>
#include <iostream>
#include <exception>

#include "../Table/Table.h"
#include "../ResolveExpression/ResolveExpression.h"

class CheckOperator
{
    public:
        void check_operator(std::vector<std::string>& str, const Table& tbl);
    private:
        ResolveExpression res_exp;
};

#endif  // __CHECK_OPERATOR__