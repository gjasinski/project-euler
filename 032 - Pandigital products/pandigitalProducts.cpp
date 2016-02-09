#include<iostream>
#include<string>
#include<cmath>
using namespace std;

int searchProducts();
bool tab[9];

bool allDigitsUsed(string number)
{
    if(number.length()!=9) return false;
    for(int i=0;i<9;i++) tab[i]=false;
    for(int i=0;i<9;i++)
    {
        if(tab[number[i]-49]) return false;
        tab[number[i]-49]=true;
    }
    return true;
}
string intToStr(int number)
{
    //w tym programie nie potrzebujemy zachowanej kolejności cyfr w liczbie!
    string wynik="";
    while(number>0)
    {
        wynik+=(char)48+number%10;
        number/=10;
    }
    return wynik;
}
int main()
{
    cout<<searchProducts();
}

int searchProducts()
{
    int a;
    bool b;
    int N=10000000;
    int sum=0;
    int j,k;
    int tablica[20];
    for(int i=0;i<20;i++) tab[i]=0;
    for(int i=1;i<N;i++)
    {

        j=i;
        while(log10(i)+log10(j)+log10(i*j)<9)
        //for(int j=i;j<N and !b;j++)
        {
            a=i*j;
            //if(a>500000000) b=true;
            if(allDigitsUsed(intToStr(i)+intToStr(j)+intToStr(a)))
            {
                b=false;
                k=0;
                while(tablica[k]!=0 and !b)
                {
                    if(tablica[k]==a) b=true;
                    k++;
                }
                if(!b)
                {
                    sum+=a;
                    tablica[k]=a;
                }
            }
            j++;
        }
    }
    return sum;
}
