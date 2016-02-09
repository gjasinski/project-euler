#include <iostream>

using namespace std;
bool pierwsza(int l);
int iloscPierwszych(int b, int c);

int main()
{
/*
    Program szukajacy współczynników b,c  kwadratówki n^2 + bn+c.
    Szukamy współczynników takich aby od n=0  było jak najwiecej liczb pierwszych wynikiem kwadratówki.
    Zauważamy ze wsp. c musi być liczbą pierwsza. => Nie może być ujemny.
*/
    int maks=0;
    int maksIloczyn=0;
    int tmp;
    for(int c=0;c<1000;c++)
    {
        if(pierwsza(c))
        {
            for(int b=0;b<1000;b++)
            {
               tmp=iloscPierwszych(b,c);
               if(tmp>maks)
                {
                    maks=tmp;
                    maksIloczyn=b*c;
                }
               tmp=iloscPierwszych(-b,c);
               if(tmp>maks)
               {
                    maks=tmp;
                    maksIloczyn=-b*c;
                }
            }
        }
    }
    cout<<maksIloczyn;
    return 0;
}

bool pierwsza(int l)
{
    //sprawdzam czy l jest pierwsza
	bool flaga = true;
	if(l==2) return true;
	if(l<2)return false;
	for (int i=3;i*i<=l;i=i+2)
	{
		if(l%i==0)
		{
			flaga = false;
			break;
		}
	}
	return flaga;
}

int iloscPierwszych(int b, int c)
{
    //zwraca ilosc liczb pierwszych jako wynik kwadratówki konsekwentnie od 0;
    bool koniec=false;
    int i=0;
    while(!koniec)
    {
        if(pierwsza(i*i+b*i+c)) i++; else koniec=true;
    }
    return i+1;
}
