/*
Program zlicza sume liczb zaprzyjazmionych od 1 do 10k.
*/
#include <iostream>


using namespace std;

void problem021();


int main()
{
	problem021();

	return 0;
};

int suma_podzielnikow(int l)
{
    /*
    Funkcja zwraca sume podzielnikow liczby l
    */
	int s=-l;
	int j=1;
	while(j*j<l)
		{
			if(l%j==0) s = s + j + l/j;
			j=j+1;
		}
	if(j*j==l) s = s +j;
	return s;
}

void problem021()
{
    /*
    Funkcja liczy sume liczb zaprzyjaznonych do 10000
    */
	int maks = 10000;
	int a = 0;
	int licz=0;
	for (int liczba = 1;liczba<maks;liczba++)
	{
		a=suma_podzielnikow(liczba);

		if (suma_podzielnikow(a)==liczba&&a>liczba) licz+=a+liczba;
	}
	cout<<licz;
}
