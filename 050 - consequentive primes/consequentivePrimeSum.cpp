#include<iostream>

using namespace std;

int generujPierwsze(bool tablica[], int limit);
int najdluzszyCiag(bool tablica[], int n, int limit);
int main()
{
/*
    Program szuka najdluzszego ciagłego ciągu liczb pierwszych takich że da się zbudować z nich liczbę pierwsza
*/
    const int N = 1000000;
    bool tab[N];
    int j = generujPierwsze(tab,N);
    cout<<najdluzszyCiag(tab,j,N);
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
int najdluzszyCiag(bool tablica[], int n, int limit)
{
    int suma=0;
    int maksciag=0;
    int tmp;
    int makspierwsza=0;
    for(int i=0;i<limit;i++)
    {
        tmp=suma=0;
        for(int j=i;j<limit and suma<limit;j++)
        {
            if(tablica[j])
            {
                suma+=j;
                if(suma<limit and maksciag<tmp)
                {

                    if(tablica[suma])
                    {
                    makspierwsza=suma;
                    maksciag=tmp;
                    }
                }
                tmp++;
            }
        }
    }
    return makspierwsza;
}
