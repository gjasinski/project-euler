//UWAGA:
//wynik jest błędny. Powinien być o 1 wyższy.
#include <iostream>
#include <cmath>

using namespace std;
int ileKombinacji(int i);
int ileKombinacji2(int i);
const int N=101;
bool tab[N];

int main()
{
    for(int i=2;i<N;i++)
    {
        tab[i]=true;

    }
    int licz=0;
    /*for (int i=2;i<=100;i++)
    {
        if(tab[i]) liczkombinacje(i);
    }*/
    for(int i=2;i<N;i++)
    {
        if(tab[i])licz+=ileKombinacji(i);
        else licz+=ileKombinacji2(i);
    }
    cout<<licz<<endl;

}

int ileKombinacji(int i)
{

    int suma=99;
    for(int j=2;j<N;j++)
    {
        if(pow(i,j)<N)
        {
        //cout<<pow(i,j);
            suma+=99-floor(100/j)+1;
            //cout<<" "<<suma<<endl;
            //cout<<"test"<<99-floor(100/j)+1<<endl;
            tab[(int)pow(i,j)]=false;
        }

    }
    return suma;
}
int ileKombinacji2(int i)
{

    int suma=0;
    for(int j=2;pow(i,j)<N;j++)
            suma+=1-floor(100/j);
    return suma;
}
