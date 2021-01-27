#include <iostream>



/// <summary>
/// ABSOLUT KEINE AHNUNG WIE DAS BEISPIEL GEMACHT WERDEN SOLL (TEMPLATES MACHEN KEINEN SINN) - FH
/// SAME HERE -DM
/// </summary>
typedef int VOLT;
typedef float OHM;
typedef double AMPERE;

template<typename Volt>
struct U
{
    Volt spannung{ 0 };
};

template<typename Ohm>
struct R
{
    Ohm widerstand{ 0 };
};

template<typename Ampere>
struct I
{
    Ampere stromstaerke{ 0 };
};

class URI {
public:
    URI(){}
    
    U<VOLT> operator*(R<OHM> resistance, I<AMPERE> intensity)
    {
        U<VOLT> ret = resistance * intensity;
        return ret;
    }

};
template<typename Volt, typename Ohm, typename Ampere>
class U {
    Volt u;
    U(Volt x) :u{ x } {}

    Ohm operator*(I<Ampere>& i)
    {
        
    }
};


int main()
{

}