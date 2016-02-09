#include <iostream>

using namespace std;
struct ulamek
{
    /*
    Struktura ułamek
    l - liczba całkowita
    m - liczba całkowita dodatnia
    */
    int l;
    int m;
};
int iledwapiec(int a)
{
    /*
    Z własności ułamka wynika że ilość liczb przed okresem jest to wieksza z liczb
    ilosci podzielnosci liczbika przez dwa lub piec.
    Funkcja znajduje ta liczbe
    */
    int iledwa, ilepiec;
    iledwa=0;
    while(a%2==0 and a>0)
    {
        iledwa++;
        a=a/2;
    }
    ilepiec=0;
    while(a%5==0 and a>0)
    {
        ilepiec++;
        a=a/5;
    }
    if(iledwa>ilepiec)return iledwa; else return ilepiec;
}
int maksokres(ulamek a)
{
    a.l=a.l%a.m;
    if(a.l>0)
    {
        int tmp=iledwapiec(a.m);
        for(int i=0;i<tmp;i++)
        {
            a.l=a.l*10;
            a.l=a.l%a.m;
        }
    }
    int licz=0;
    if(a.l>0)
    {
        int p=a.l;
        do
        {
            a.l=a.l*10;
            a.l=a.l%a.m;
            licz++;
        } while(a.l!=p);

    }
    return licz;
}

int main()
{
    int maks=0;
    int dmaks=0;
    int tmp;
    ulamek u;
    for(int i=1;i<1000;i++)
    {
        u.l=1;
        u.m=i;
        tmp=maksokres(u);
        if(tmp>maks) {maks=tmp;dmaks=i;}
    }

    cout<<dmaks;
}
