#include <iostream>

using namespace std;

const int N=1001;
int tab1[N];
int tab2[N];
int size1=1;
int size2=1;
int dodawajDoTysiaca();

int main()
{
    /*
    Program szukajacy indeksu ciagu fibbonaciego któ©ego liczba ma 1000 cyfr.
    */
    for(int i=0;i<N;i++)
    {
        tab1[i]=0;
        tab2[i]=0;
    }
    cout<<dodawajDoTysiaca();
    cout<<endl;
    for(int i=0;i<N;i++)
    {
        cout<<tab1[i];
    }
    return 0;
}

void dodajTablice()
{
    /*
    Dodawanie dwuch tablic w ciagu fibbonaciego. Zachowujemy wieksza skopiowana do mniejszej.
    Uaktualnia maksymalny indeks w celu usuniecia niepotrzebnych działań.
    */
    int maks;
    if(size1>size2)maks=size1; else maks=size2;
    int tmp=0;
    for(int i=0;i<maks;i++)
    {
        tmp+=tab1[i]+tab2[i];
        tab2[i]=tab1[i];
        tab1[i]=tmp%10;
        tmp=tmp/10;
    }
    while(tmp>0)
    {
        tab1[maks]=tmp%10;
        tmp=tmp/10;
        maks++;
    }

    size2=size1;
    size1=maks;
}

int dodawajDoTysiaca()
{
    /*
    Dodawanie dwie tablice do momentu osiagniecia 1000 cyfr w tablicy.
    */
    tab1[0]=tab2[0]=1;
    int indeks=2;
    while(size1<1000)
    {
        dodajTablice();
        indeks++;
    }
    return indeks;
}
