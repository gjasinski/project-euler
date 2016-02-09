#include<iostream>
#include<cmath>
using namespace std;
void sprawdzajLiczby();
bool prime(int n)
{
    for(int i=2;i*i<=n;i++)
        if(n%i==0)return false;
    return true;
}

int main()
{
    sprawdzajLiczby();
    return 0;
}

void sprawdzajLiczby()
{
    int licz=0;
    int liczby[10];
    int tmp;
    int tmpi;
    bool pierwsza;
    int tmpliczba;
    for(int i=2;i<1000001;i++)
    {
        if(prime(i))
        {
        //cout<<endl<<endl;
            for(int j=0;j<10;j++) liczby[j]=-1;
            tmp=i;
            tmpi=0;
            pierwsza=true;
            while(tmp>0 and pierwsza)
            {
                liczby[tmpi]=tmp%10;
                //if((tmp%10)%2==0) pierwsza=false;
                tmp=tmp/10;
                tmpi++;
            }

            for(int o=0;o<tmpi/2;o++)
            {
                tmp=liczby[o];
                liczby[o]=liczby[tmpi-1-o];
                liczby[tmpi-1-o]=tmp;
            }
            for(int m=0;m<tmpi and pierwsza;m++)
            {
                tmpliczba=0;
                for(int n=0;n<tmpi;n++)
                {
                    tmpliczba*=10;
                    tmpliczba+=liczby[(m+n)%tmpi];
                }
                if(!prime(tmpliczba)) pierwsza=false;
            }
            if(pierwsza) licz++;
        }
    }
    cout<<licz;
}

