#include<iostream>
#include<cmath>
using namespace std;

int tab[10];

void szukaj();

int main()
{
    szukaj();
}

bool pandigital()
{
    int i=1;
    while(i<10)
    {
        if(tab[i]!=1)return false;
        i++;
    }
    return true;
}

bool nastepny()
{
    int i=1;
    while(i<10)
    {
        if(tab[i]>1)return true;
        i++;
    }
    return false;
}

void szukaj()
{
    int k,tmp,wynik;
    int m=0;
    for (int i=1;i<329218108;i++)
    {
        for (int j=0;j<10;j++)tab[j]=0;
        k=1;
        wynik=0;
        do
        {
            tmp=i*k;
            wynik*=pow(10,floor(log10(tmp))+1);
            wynik+=tmp;
            while(tmp>0)
            {
                tab[tmp%10]++;
                tmp=tmp/10;
            }
            k++;
            if(log10(wynik)>9 or wynik<0)break;
            if(pandigital())
            {
                if(wynik>m)m=wynik;
                break;
            }
        }while(!nastepny());

    }
    cout<<m;
}
