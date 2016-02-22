#include<iostream>
#include<cmath>
using namespace std;

void szukajPitagorasa();

int main()
{
    szukajPitagorasa();
}

void szukajPitagorasa()
{
    int tab[10001];
    int tmp;
    for(int i=1;i<1001;i++)tab[i]=0;
    for(int i=1;i<1001;i++)
    {
        for(int j=1;j<1001;j++)
        {
            tmp=i*i+j*j;
            if(sqrt(tmp)==floor(sqrt(tmp)))
            {
                tmp=i+j+sqrt(tmp);
                if(tmp<=1000) tab[tmp]++;
            }
        }
    }
    int maks=tab[1];
    int maksi=1;
    for (int i=0;i<1001;i++)
    {
        if(maks<tab[i])
        {
            maks=tab[i];
            maksi=i;
        }
    }
    cout<<maksi;
}
