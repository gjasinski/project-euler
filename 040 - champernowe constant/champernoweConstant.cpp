#include <iostream>
#include <stack>
#include <cmath>
using namespace std;
int generujLiczbe();
int main()
{
    generujLiczbe();
}

int zwrocNLiczbe(int l, int n)
{
    stack <int> stos;
    while(l>0)
    {
        stos.push(l%10);
        l=l/10;
    }
    for (int i=1;i<n;i++) stos.pop();
    return stos.top();
}

int generujLiczbe()
{
    int liczba=1;
    int i, iloscLiczb, potega;
    i=1;
    iloscLiczb=1;
    for (int k=1;k<7;k++)
    {
        potega=pow(10,k);
        while(iloscLiczb<potega)
        {
            if(floor(log10(i))!=log10(i))
            iloscLiczb+=floor(log10(i))+1;
            else{
            iloscLiczb+=floor(log10(i));}
            i++;
        }
        liczba*=zwrocNLiczbe(i-1,iloscLiczb-potega);
    }
    cout<<liczba;
}
