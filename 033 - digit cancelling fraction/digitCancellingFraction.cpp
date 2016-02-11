#include <iostream>

using namespace std;

struct ulamek
{
    int l;
    int m;
};

void generujUlamki();

int main()
{
    generujUlamki();
}

bool zawierajaTakaSamaCyfre(ulamek u)
{
    int d1,d2, m;
    d1=u.l%10;
    u.l/=10;
    if(u.l>0) d2=u.l;
    else d2=-1;

    m=u.m%10;
    if(m==d1 or m==d2) return true;
    u.m/=10;
    if(u.m>0)
        if(u.m==d1 or u.m==d2) return true;
    return false;
}

bool moznaSkracac(ulamek u)
{
    ulamek tmp=u;
    int l1, l2, m1, m2;
    l1=u.l%10;
    u.l/=10;
    if(u.l>0) l2=u.l;
    else l2=-1;

    m1=u.m%10;
    u.m/=10;
    if(u.m>0) m2=u.m;
    else m2=-1;
    u=tmp;
    //if(l1 == m1 and u.l*m2==u.m*l2) return true;
    //poniważ interesują nas nietrywialne, a ten warunek działa na ułamki typu 20/30->2/3
    if(l1 == m2 and u.l*m1==u.m*l2) return true;
    if(l2 == m2 and u.l*m1==u.m*l1) return true;
    if(l2 == m1 and u.l*m2==u.m*l1) return true;
    return false;
}
int nwd(int a, int b)
{
    int tmp;
    while(true)
    {
        if(a>b) a=a%b;
        if(a==0)return b;
        if(a<b) b=b%a;
        if(b==0)return a;

    }
}
void skroc(ulamek &u)
{
    int tmp=nwd(u.l,u.m);
    u.l/=tmp;
    u.m/=tmp;
}
void generujUlamki()
{
    ulamek u;
    u.l=1;
    u.m=1;
    ulamek tab[4];
    int i=0;
    while (u.m!=99 or u.l!=98)
    {
        u.l++;
        if(u.l>=u.m)
        {
            u.m++;
            u.l=1;
        }
        if(zawierajaTakaSamaCyfre(u) and moznaSkracac(u))
        {
            tab[i]=u;
            i++;
        }
    }
    for (i=0;i<4;i++)
    {
        skroc(tab[i]);
        cout<<tab[i].l<<"/"<<tab[i].m<<endl;
    }
    u.l=u.m=1;
    for (i=0;i<4;i++)
    {
        u.l*=tab[i].l;
        u.m*=tab[i].m;
    }
    skroc(u);
    cout<<u.l<<"/"<<u.m;
}
