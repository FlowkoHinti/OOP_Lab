#include <iostream>

int main()
{
    auto func = [](double val1, double val2, char op) -> double
    {
        switch (op)
        {

        case '+':
            return val1 + val2;
            break;

        case '-':
        return val1 - val2;
            break;

        case '*':
            return val1 * val2;
            break;

        case '/':
            return val1 / val2;
            break;

        default:
            throw std::invalid_argument("Operator ist nicht vorhanden");
            break;
        }
    };

    try
    {

        std::cout << func(1, 2, 'k') << std::endl;

    }
    catch(std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}
