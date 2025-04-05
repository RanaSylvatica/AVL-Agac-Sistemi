#ifndef Dugum_hpp
#define Dugum_hpp
#include "Agac.hpp"

class Dugum
{
public:
    Dugum(Agac* veri);
    Agac* erisimkoku;
    Dugum* sonraki;
    
private:
    Dugum* ilk;
};

#endif