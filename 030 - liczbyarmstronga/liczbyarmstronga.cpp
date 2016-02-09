#include <iostream>
#include <math.h>

using namespace std;
int liczSilnie();
int main()
{
    liczSilnie();
}

int piatePotegi()
{
    /*
    Szukamy liczb których cyfry podniesione do 5 potęgi dadzą tą samą liczbę.
    Ustawiamy sobie pewną górną granice, poniewaz w pewnym momencie liczby przekraczaja sume 5 poteg cyfr.
*/
    int suma=0;
    int l, s;

    for(int i=2;i<300000;i++)
    {
        s=0;
        l=i;
        while(l>0)
        {

            s+=pow(l%10,5);

            l=l/10;
        }
        if(s==i) suma+=i;
    }
    cout<<suma;
    return suma;
}
int silnia(int n)
{
    int wynik=1;
    for(int i=1;i<=n;i++) wynik*=i;
    return wynik;
}

int liczSilnie()
{
    int suma=0;
    int l, s;

    for(int i=3;i<9000000;i++)
    {
        s=0;
        l=i;
        while(l>0)
        {

            s+=silnia(l%10);

            l=l/10;
        }
        if(s==i) suma+=i;
    }
    cout<<suma;
    return suma;

}
