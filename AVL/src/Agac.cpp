#include "Agac.hpp"
#include<iostream>
#include<fstream>
#include<sstream>
#include<iomanip>
#include<string>
#include <cmath>
using namespace std;

Agac::Agac(){
    kok=0;
}
Agac::~Agac(){
    agaciYokEt(kok);
   
}
void Agac::agaciYokEt(AgacDugum* dugum)
{
    if(dugum!=0)
    {
        agaciYokEt(dugum->sol);
        agaciYokEt(dugum->sag);

        delete dugum;
    }
}
void Agac::ekle(int eklenecekVeri)
{
    if(kok==0){
        kok=new AgacDugum(eklenecekVeri);}
    else {

        ekle(eklenecekVeri,kok);
        }

}
void Agac::ekle(int eklenecekVeri, AgacDugum* aktifDugum)
{

    if(aktifDugum->kokVeri>eklenecekVeri)
    {

        if(aktifDugum->sol)
        {
            ekle(eklenecekVeri,aktifDugum->sol);}
        else{

            aktifDugum->sol=new AgacDugum(eklenecekVeri);
            }
    }
    else if(aktifDugum->kokVeri<eklenecekVeri)
    {

        if(aktifDugum->sag)
        {

            ekle(eklenecekVeri,aktifDugum->sag);

        }
        else
        {
            aktifDugum->sag=new AgacDugum(eklenecekVeri);}
    }
    else return; //zaten var.
}
void Agac::tersEkle(int eklenecekVeri)
{
    if(kok==0){
        kok=new AgacDugum(eklenecekVeri);}
    else {

        ekle(eklenecekVeri,kok);
        }

}
void Agac::tersEkle(int eklenecekVeri, AgacDugum* aktifDugum)
{

    if(aktifDugum->kokVeri<eklenecekVeri)
    {

        if(aktifDugum->sol)
        {
            ekle(eklenecekVeri,aktifDugum->sol);}
        else{

            aktifDugum->sol=new AgacDugum(eklenecekVeri);
            }
    }
    else if(aktifDugum->kokVeri>eklenecekVeri)
    {

        if(aktifDugum->sag)
        {

            ekle(eklenecekVeri,aktifDugum->sag);

        }
        else
        {
            aktifDugum->sag=new AgacDugum(eklenecekVeri);}
    }
    else return; //zaten var.
}


int Agac::yukseklik(AgacDugum* aktifDugum)
{
    if(aktifDugum)
        return 1+max(yukseklik(aktifDugum->sol),yukseklik(aktifDugum->sag));
    return -1;
}
int Agac::dugumlerToplami(AgacDugum* kok)
{
    if(kok==0)
        return 0;
    
    int sag=dugumlerToplami(kok->sag);
    int sol=2*dugumlerToplami(kok->sol);
        return (kok->kokVeri +sol + sag);

}

AgacDugum* Agac::kokDondur()
{
    return kok;
}

void Agac::boslukBirak(int sayi)
{
    int boslukSayisi=pow(2,sayi)-2;
    for (int i = 0; i <boslukSayisi; i++)
    {
        cout<<" ";
    }
}
void Agac::boslukBirak2(int sayi)
{
    int boslukSayisi=pow(2,sayi)-1;
    for (int i = 0; i <boslukSayisi; i++)
    {
        cout<<" ";
    }
}
void Agac::boslukBirak3(int sayi)
{
    for (int i = 0; i <sayi; i++)
    {
        cout<<" ";
    }
}

int Agac::yukseklik()
{
    return yukseklik(kok);
}
void Agac::noktaYaz(int sayi)
{
    int noktaSayisi=(pow(2,sayi)+1);
    for (int i = 0; i < noktaSayisi; i++)
    {
       cout<<".";
    }
    
}
void Agac::noktaYaz2(int sayi)
{
    int noktaSayisi=(pow(2,sayi)-1);
    for (int i = 0; i < noktaSayisi; i++)
    {
       cout<<" ";
    }
    
}
void Agac::noktaYaz3(int sayi)
{
    int noktaSayisi=(pow(2,sayi));
    for (int i = 0; i < noktaSayisi; i++)
    {
       cout<<".";
    }
    
}
void Agac::levelOrder()
{
    if (kok == 0) return;

    const int maxBoyut = 1000; 
    AgacDugum* kuyruk[maxBoyut];
    int bas = 0, son = 0; 

    kuyruk[son++] = kok;

    int seviye = 0;
    int yuksek = yukseklik();
    int index=1;

    int kat = 0;
    int sabit2=1;
    int sabit0=1;

    cout << endl;
    while (bas < son && seviye <= yuksek) {
    AgacDugum* siradaki = kuyruk[bas++]; 
    
        if (kat == 0)
        {
            boslukBirak(yuksek-seviye+1);
        }
        if (siradaki)
        {
            
            cout <<setw(1)<< (char)siradaki->kokVeri;
            
            
        }else {
            cout << setw(1) << " ";
        }
       
        boslukBirak2(yuksek - seviye + 2);

        if (siradaki) {
            if(sart%2==0)
           { 
            kuyruk[son++] = siradaki->sol;
            index+=1;
            
            kuyruk[son++] = siradaki->sag;
            index+=1;
            }
            else{
            kuyruk[son++] = siradaki->sag;
            index+=1;
            
            kuyruk[son++] = siradaki->sol;
            index+=1;
            }

        } else {
            kuyruk[son++] = 0;
            index+=1;

            kuyruk[son++] = 0;
            index+=1;

        }
        kat++;
        
        if (pow(2,seviye) == kat)
        {
        int sabit=0;
        
        int sabit1=0;
            cout<<endl;

        
        
             
            for (int i = sabit2; i < index; i++)
            {
               
                if(sabit2%2==1&&kuyruk[sabit2]!=0)
                {
                    if(sabit<2)
                    boslukBirak(yuksek-seviye);
                    noktaYaz3(yuksek-seviye);
                   

                }
                else if(sabit2%2==1&&kuyruk[sabit2]==0)
                   { 
                    if(sabit<2)
                    {;
                    boslukBirak((yuksek-seviye));
                    }
                    int x=(yuksek-seviye);
                    boslukBirak3(pow(2,x));
                    }

                if((kuyruk[sabit2]!=0||kuyruk[sabit2+1]!=0)&&sabit2%2==1)
                   { cout<<".";
                   }else if((kuyruk[sabit2]==0&&kuyruk[sabit2+1]==0)&&sabit2%2==1)
                    cout<<" ";

                    
                if(sabit2%2==0&&kuyruk[sabit2]!=0)
                {
                    noktaYaz3(yuksek-seviye);
                    boslukBirak2(yuksek-seviye+1);
                    
                }
                else if(sabit2%2==0&&kuyruk[sabit2]==0)
                {
                    int x=(yuksek-seviye);
                    boslukBirak3(pow(2,x));
                    boslukBirak2(yuksek - seviye + 1);


                }
            sabit2=sabit2+1;
            sabit=sabit+1;

            }
            cout<<endl;

            for (int i = sabit0; i < index; i++)
            {
               
                if(sabit0%2==1&&kuyruk[sabit0]!=0)
                {
                    if(sabit1<2)
                    boslukBirak(yuksek-seviye);
                    cout<<".";
                   

                }
                else if(sabit0%2==1&&kuyruk[sabit0]==0)
                   { 
                    if(sabit1<2)
                    {;
                    boslukBirak((yuksek-seviye));
                    }
                    cout<<" ";
                    }

                
                    
                if(sabit0%2==0&&kuyruk[sabit0]!=0)
                {
                    boslukBirak2(yuksek - seviye + 1);
                    cout<<".";

                    boslukBirak2(yuksek-seviye+1);
                    
                }
                else if(sabit0%2==0&&kuyruk[sabit0]==0)
                {
                    int x=(yuksek-seviye);
                    boslukBirak2(yuksek - seviye + 1);
                    cout<<" ";
                    boslukBirak2(yuksek - seviye + 1);


                }
            sabit0=sabit0+1;
            sabit1=sabit1+1;

            }
            
            cout<<endl;
            seviye++;
            kat = 0;
        
    }
}
}
