#include <iostream>            
#include <string>
#include <cmath>

#include "Functions.hpp"

double Calculator::Number(std::string str, unsigned int& idx)
{
    double result = 0.0;
    double div = 10.0;
    int sign = 1;
    if (str[idx] == '-')
    {
        sign = -1;
        idx++;
    }
    while (str[idx] >= '0' && str[idx] <= '9')
    {
        result = result * 10.0 + (str[idx] - '0');
        idx++;
    }
    if (str[idx] == '.')
    {
        idx++;
        while (str[idx] >= '0' && str[idx] <= '9')
        {
            result = result + (str[idx] - '0') / div;
            div *= 10.0;
            idx++;
        }
    }
    return sign * result;
}

double Calculator::Expr(std::string str, unsigned int& idx)
{
    double result = Term(str, idx);
    while (str[idx] == '+' || str[idx] == '-')
    {
        switch (str[idx])
        {
        case '+':
            idx++;
            result += Term(str, idx);
            break;
        case '-':
            idx++;
            result -= Term(str, idx);
            break;
        }
    }
    return result;
}

double Calculator::Term(std::string str, unsigned int& idx)
{
    double result = Factor(str, idx);
    double div;
    while (str[idx] == '*' || str[idx] == '/')
    {
        switch (str[idx])
        {
        case '*':
            idx++;
            result *= Factor(str, idx);
            break;
        case '/':
            idx++;
            div = Factor(str, idx);
            if (div != 0.0) {
                result /= div;
            }
            else
                std::cout << "Division by zero!" << std::endl;
            break;
        }
    }
    return result;
}

double Calculator::Factor(std::string str, unsigned int& idx)
{
    double result;
    int sign = 1;
    if (str[idx] == '-')
    {
        sign = -1;
        idx++;
    }
    if (str[idx] == '(')
    {
        idx++;
        result = Expr(str, idx);
        if (str[idx] != ')')
        {
            std::cout << "Incorrectly placed brackets" << '\n';
        }
        idx++;
    }
    else
        result = Number(str, idx);
    if (str[idx] == '^')
    {
        idx++;
        result = pow(result, Factor(str, idx));
    }
    return sign * result;
}

