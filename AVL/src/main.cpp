#include<iostream>
#include<fstream>
#include<sstream>
#include<iomanip>
#include<string>
using namespace std;
#include "BagliListe.hpp"
#include "Dugum.hpp"
// dodo babaaaa


void boslukYaz(int boslukSayisi)
{
    for (int i = 0; i < boslukSayisi; i++)
    {
        cout<<" ";
    }
    
}
void satirYaz(int satirSayisi)
{
    for (int i = 0; i < satirSayisi; i++)
    {
        cout<<"........";
        boslukYaz(3);
    }
        
}
void degerYaz(int deger)
{
    cout<<"."<<setw(6)<<deger<<".";
    boslukYaz(3);
}

void okCiz(int index,int satirSayisi)
{    
    if(satirSayisi>0)
    {
    if(index!=0)
    {
        for (int i = 0; i < index; i++)
        {
        cout<<"        ";
        boslukYaz(3);
        }
    }
    cout<<"^^^^^^^^"<<endl;

    if(index!=0)
    {
        for (int i = 0; i < index; i++)
        {
        cout<<"        ";
        boslukYaz(3);
        }
    }
    cout<<"||||||||"<<endl;
    }
    else{
        return;
    }
}

void tabloCiz(int satirSayisi, int index, BagliListe* liste)
{
    if(satirSayisi==0)
    {
        system("cls");
        return;
    }
    
    system("cls");
    int bolum=index/10;

    if(satirSayisi%10==0)
    int bolum=(index/10)-1;

    int yeniSayi;
    int artan;
    if((bolum*10+10)>satirSayisi&&satirSayisi%10!=0)
    {
        yeniSayi=satirSayisi%10;
    }
    else
    { 
        yeniSayi=10;
    }
    satirYaz(yeniSayi);
    cout<<endl;
    for (int i = bolum*10; i < (yeniSayi+bolum*10); i++)
    {
        uintptr_t adres =reinterpret_cast<uintptr_t>(liste->dugumGetir(i));
        uintptr_t son6 = adres%1000000;
        cout<<"."<<setw(6)<<son6<<".";
        boslukYaz(3);

    }  
    cout<<endl;
    satirYaz(yeniSayi);
    cout<<endl;
    for (int i = bolum*10; i < (yeniSayi+bolum*10); i++)
    {
        Dugum* gec=liste->dugumGetir(i);
       
       degerYaz( liste->dugumGetir(i)->erisimkoku->dugumlerToplami(gec->erisimkoku->kokDondur()));

        ///agaclistesine bagli listeden ulasmalisin ki i arttikca bagli liste indexini arttırabil
       //liste->dugumGetir(i)->erisimkoku->kokDondur()->kokVeri;
      //degerYaz(liste->dugumGetir(i)->erisimkoku->dugumlerToplami(liste->dugumGetir(i)->erisimkoku->kokDondur()));
        
       //degerYaz(liste->dugumGetir(1)->erisimkoku->kokDondur()->sag->kokVeri);
        //degerYaz(liste->dugumGetir(i)->erisimkoku->dugumlerToplami(liste->agacDondur(liste->dugumGetir(i)->erisimkoku)));
    }  
    cout<<endl;
    satirYaz(yeniSayi);
    cout<<endl;
    for (int i = bolum*10; i < (yeniSayi+bolum*10); i++)
    {

        if(i==satirSayisi-1)
        cout<<"."<<setw(6)<<"0"<<".";
        else
        {
            uintptr_t adres =reinterpret_cast<uintptr_t>(liste->dugumGetir(i+1));
            uintptr_t son6 = adres%1000000;
            
        //string onceki =(to_string(reinterpret_cast<uintptr_t>(liste->dugumGetir(i+1))))%1000000;
        cout<<"."<<setw(6)<<son6<<".";
        }
        boslukYaz(3);

    }  
    cout<<endl;
    satirYaz(yeniSayi);
    cout<<endl;

    int okIndex=index%10;
    if(index!=0)
        int okIndex=index%10;
    okCiz(okIndex,satirSayisi);
    
    if(satirSayisi>0)
    liste->dugumGetir(index)->erisimkoku->levelOrder();


    }


int main()
{
ifstream dosya("agaclar.txt");
string satir;
BagliListe* liste=new BagliListe();

while(getline(dosya,satir))
{
    Agac* agacListe=new Agac();
    int toplam=0;
    for (int i=0; i <satir.length(); i++) 
    {
        if(satir[i]!=32)
        {
            agacListe->ekle(satir[i]);
        }
    }
    liste->sonaEkle(agacListe);
}

int index=0;
int satirSayisi=liste->dugumSayisiBul();
char girdi;
int sart=0;
tabloCiz(satirSayisi,index,liste);


cin>>girdi;
while(true)
{
    if(islower(girdi));
        girdi=toupper(girdi);
    
        if(girdi=='D')
        {
            if(index!=satirSayisi-1)
                index=index+1;

            tabloCiz(satirSayisi,index,liste);
            

            cin>>girdi;
            
        }
            
        else if(girdi=='A')
        {
            if(index!=satirSayisi && index!=0)
                index=index-1;
            tabloCiz(satirSayisi,index,liste);
            cin>>girdi;
        }
        else if(girdi=='S')
        {
            if(satirSayisi<2){
                system("cls");
                
            }
            else
            {

            liste->dugumCikar(index);
            satirSayisi--;

            if(index==satirSayisi)
            {
                index=index-1;
            }

            tabloCiz(satirSayisi,index,liste);
            cin>>girdi;
            }
        }
        else if(girdi=='W')
        {
            (liste->dugumGetir(index)->erisimkoku->sart)++;
            tabloCiz(satirSayisi,index,liste);
            cin>>girdi;
        }
        else if(girdi=='Q')
        {
            return 0;
        }
        else
        {
            cin>>girdi;

        }
        
    
}




}