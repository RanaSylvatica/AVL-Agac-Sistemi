#include<iostream>
using namespace std;
#include<iomanip>
#include <fstream>
#include <string>
#include "BagliListe.hpp"

BagliListe::BagliListe()
{
    ilk=0;
}

BagliListe::~BagliListe()
{
    Dugum* gec=ilk;
    while(gec!=0)
    {
        Dugum* sil=gec;//gecici
        //delete gec; bir sonraki dugumu gostermeliyiz
        gec=gec->sonraki;
        delete sil->erisimkoku;
        delete sil;//once sile geci verdik. sili sildik. gecle ilerleyip silmeye devam edecegiz
    }
   
}
void BagliListe::ekle(Dugum* ilk, Agac* veri,int sira)
{
    Dugum* yeniDugum=new Dugum(veri);
    yeniDugum->sonraki=0;

   if(sira==0)
   {
    yeniDugum->sonraki=ilk;
    ilk=yeniDugum;
    return;
   }

   Dugum* gec=ilk;
   for (int i = 0; i < sira-1; i++)
   {
    if(gec!=0)
    {
        gec=gec->sonraki;
    }
    else{
        return;
    }
    yeniDugum->sonraki=gec->sonraki;
    gec->sonraki=yeniDugum;
   }
   
   
    
}
Dugum* BagliListe::ilkDondur()
{
    return ilk;
}
void BagliListe::sonaEkle(Agac* veri)
{
    Dugum* yeni=new Dugum(veri);
    if(ilk==0)
    {
        ilk=yeni;
        return;
    }
    Dugum* gec=ilk;
    while(gec->sonraki!=0)
        gec=gec->sonraki;
    
    gec->sonraki=yeni;
}

int BagliListe::dugumSayisiBul()
{
    Dugum*gec=ilk;
    int sayac=0;

    while(gec!=0)
    {
        gec=gec->sonraki;
        sayac++;
    }
    return sayac;
    
}

 
Dugum* BagliListe::dugumGetir(int sira)
{
    Dugum* gec=ilk;
    int satirSayac=0;

    while(gec!=0)
    {
        if(satirSayac==sira)
        {
            return gec;
        }
        gec=gec->sonraki;
        satirSayac++;

    }
}

Dugum* BagliListe::sonDugumuGetir()
{
    Dugum* sonDugum;
    if(ilk==0)
    {
        return ilk;
    }
    Dugum* gec=ilk;
    while(gec->sonraki!=0)
        gec=gec->sonraki;
    
    return gec;
}


void BagliListe::dugumCikar(int sira)
{
   if(ilk==0)
    return;
   if(sira==(0))
    {
        Dugum* sil=ilk;
        ilk=ilk->sonraki;
        delete sil;
        return;

    }


    Dugum*gec=dugumGetir(sira-1);
    Dugum* sonraki=gec->sonraki->sonraki;
    delete gec->sonraki;
    gec->sonraki=sonraki;

}


