#ifndef Agac_hpp
#define Agac_hpp
#include "AgacDugum.hpp"

class Agac
{
public:
    Agac();
    ~Agac();
    void agaciYokEt(AgacDugum*dugum);
    void ekle(int eklenecekVeri);
    void ekle(int eklenecekVeri, AgacDugum* aktifDugum);
    void tersEkle(int eklenecekVeri);
    void tersEkle(int eklenecekVeri, AgacDugum* aktifDugum);
    int yukseklik(AgacDugum* aktifDugum);
    AgacDugum* kokDondur();
    int dugumlerToplami(AgacDugum* kok);
    void boslukBirak2(int sayi);
    void boslukBirak(int sayi);
    void noktaYaz(int sayi);
    void noktaYaz2(int sayi);
    void noktaYaz3(int sayi);
    int sart;

    void boslukBirak3(int sayi);

    void levelOrder();
    int yukseklik();
   
private:
    AgacDugum* kok;

};
#endif
