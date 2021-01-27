#include <iostream>
#include <array>

template <typename T, int w=10, int h=10>
class TwoDArray
{
    std::array<std::array<T,w>,h> matrix;

public:
    TwoDArray() {}
    void transform(std::function<T(T)>& lambda)
    {
        for (size_t i = 0; i < matrix.size(); ++i)
        {
            std::for_each(matrix[i].start(), matrix[i].end(), lambda);
        }
        
    }
};

int main()
{
    std::cout << "Hello World!\n";
}
