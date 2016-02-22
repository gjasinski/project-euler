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
    int i, iloscLiczb;
    i=1;
    iloscLiczb=0;
    for (int k=1;k<7;k++)
    {
        while(iloscLiczb<=pow(10,k))
        {
            if(floor(log10(i))!=log10(i))
            iloscLiczb+=floor(log10(i))+1;
            else{
            iloscLiczb+=floor(log10(i));cout<<i<<"AKAKK"<<endl;}
            i++;
        }
        cout<<i-1<<"  "<<iloscLiczb-pow(10,k)<<" ";
        cout<<zwrocNLiczbe(i-1,iloscLiczb-pow(10,k))<<endl;;
        liczba*=zwrocNLiczbe(i-1,iloscLiczb-pow(10,k));
    }
    cout<<liczba;
}
