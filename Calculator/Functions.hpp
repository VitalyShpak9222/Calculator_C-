#include <string>

class Calculator
{
public:
    std::string str;
    Calculator(const std::string& str) :
        str{ str }
    {}
public:
    static double Number(std::string str, unsigned int& idx);

    static double Expr(std::string str, unsigned int& idx);

    static double Term(std::string str, unsigned int& idx);

    static double Factor(std::string str, unsigned int& idx);
};

