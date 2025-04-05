#ifndef BagliListe_hpp
#define BagliListe_hpp
#include "Dugum.hpp"
#include "Agac.hpp"


class BagliListe
{
public:
    BagliListe();
    ~BagliListe();
    void sonaEkle(Agac* veri);
    void ekle(Dugum* ilk,Agac* veri,int sira);
    Dugum* ilkDondur();
    int dugumSayisiBul();
    Dugum* dugumGetir(int sira);
    Dugum* sonDugumuGetir();
    void dugumCikar(int sira);
    

private:
    Dugum* ilk=0;


};

#endif