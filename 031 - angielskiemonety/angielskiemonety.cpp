#include <iostream>

using namespace std;
void dzielSume(int p, int c);
int ile =1;
int main()
{
    dzielSume(200,200);
    cout<<ile;
}

void dzielSume(int p, int c)
{
    /*
    Rekurencyjna funkcja licząca różne kombinacje wypłacenia 2 funtów.
    Przy czym przekazujemy oprócz sumy, wielkosc monety. Po to aby się nie cofać i nie liczyć kilka razy tych samym opcji.
    */
    if(p==0)
    ile++;
    if(p>0)
    {
        if(c>=100) dzielSume(p-100,100);
        if(c>=50) dzielSume(p-50,50);
        if(c>=20) dzielSume(p-20,20);
        if(c>=10) dzielSume(p-10,10);
        if(c>=5) dzielSume(p-5,5);
        if(c>=2) dzielSume(p-2,2);
        if(c>=1) dzielSume(p-1,1);
    }

}

