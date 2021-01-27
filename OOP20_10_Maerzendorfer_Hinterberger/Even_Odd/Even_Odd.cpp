#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <algorithm>

int main()
{
    std::vector<int> VektorMitZahlen(1000);
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    std::for_each(VektorMitZahlen.begin(),VektorMitZahlen.end(),[](int &val)
        {
        val=std::rand() % 5000 + 1;
        }
    );
    int oddCount = 0;
    int evenCount = 0;
    int greaterCount = 0;
    int ProvVal = 2500;
    std::for_each(VektorMitZahlen.begin(), VektorMitZahlen.end(), [&oddCount, &evenCount, &greaterCount, &ProvVal](int& val)
        {
            std::cout << val << std::endl;
            val % 2 == 0 ? ++evenCount : ++oddCount;
            val > ProvVal ? greaterCount++ : 0 ;
        }
    );

    std::cout << "EvenCount: " << evenCount << std::endl;
    std::cout << "OddCount: " << oddCount << std::endl;
    std::cout << "GreaterCount: " << greaterCount << std::endl;

    


}
