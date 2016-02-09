#include<iostream>
#include<cmath>
using namespace std;

int generujPierwsze(bool tablica[], int limit);
int szukajSumyPierwszych(bool tablica[]);
const int N = 1000000;
int main()
{
/*
    Program szuka liczb pierwszych które podczas usuwania licz z przodu i z tyłu nadal są l. pierwzymi
    NP:
    The number 3797 has an interesting property. Being prime itself, it is possible to continuously remove digits from left to right,
    and remain prime at each stage: 3797, 797, 97, and 7. Similarly we can work from right to left: 3797, 379, 37, and 3.
    Dla n>=10;
*/

    bool tab[N];
    int j = generujPierwsze(tab,N);
    cout<<szukajSumyPierwszych(tab);
}

int generujPierwsze(bool tablica[], int limit)
{
//generowanie l.pierwszych
    int i=2;
    int j=0;
    int tmp;
    bool pierwsza;
    tablica[0]=tablica[1]=false;
    for(int i=2;i<limit;i++)tablica[i]=true;
    for(int i=2;i<limit;i++)
    {
        if(tablica[i])
        {
            tmp=2;
            while(i*tmp<limit)
            {
                tablica[i*tmp]=false;
                tmp++;
            }
        }
    }
    return 0;
}
//szuamy najdłuższego ciągu liczb pierwszych który jest liczba pierwsza
//nalezy uwzglednic ze ciąg nie musi sie zaczynać od 2
int szukajSumyPierwszych(bool tablica[])
{
    int suma=0;
    int licz=0;
    int i=10;
    int tmp, tmp2, j, tmps;
    bool sprawdzaj;
    while(licz<11 and i<=N)
    {
        if(tablica[i])
        {
            sprawdzaj=true;
            tmp=i;
            tmp2=0;
            //usuwamy cyfry od konca i sprawdzamy czy l nadal jest pierwsza
            while(tmp>0 and sprawdzaj)
            {
                    if(!tablica[tmp]) sprawdzaj=false;
                    tmp=tmp/10;
            }

            tmp=i;
            //usuwamy cyfry od poczatku i spawdzamy czy l nadal jest pierwsza
            while(tmp>0 and sprawdzaj)
            {
                //cout<<"test";
                tmp2=0;
                j=0;
                tmps=0;
                //usuniecie początkowej cyfry
                while(tmp>0)
                {
                    tmp2+=tmps;
                    tmps=(tmp%10)*pow(10,j);
                    tmp/=10;
                    j++;
                }
                tmp=tmp2;
                if(tmp!=0 and !tablica[tmp])sprawdzaj=false;
            }
            if(sprawdzaj)
            {
                licz+=1;
                suma+=i;
            }
        }

        i++;
    }
    return suma;
}
