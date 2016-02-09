#include <iostream>

using namespace std;

bool palindrom10base(int liczba)
{
	//funkcja sprawdza czy liczba jest palindromem
	//podstawa (10)
	int a,b;
	a=liczba;
	b=0;
	while(a>0)
	{
		b=b*10;
		b=b+a%10;
		a=a/10;
	}
	if(b==liczba) return true; else return false;
}
bool palindrom2base(int l)
{
	//funkcja sprawdza czy liczba jest palindromem
	//podstawa (2)
    string liczba="";
    while(l>0)
    {
        liczba+=l%2+48;
        l=l/2;
    }
    cout<<liczba<<endl;
	for(int i=0;i<liczba.length();i++)
        if(liczba[i]!=liczba[liczba.length()-i-1]) return false;
	return true;
}

int main()
{
/*
	Program szukajacy palindromów liczb od 2 do 1 000 000 w systemach (10) i (2)
*/
    int suma=0;
    for(int i=0;i<1000000;i++)
    {
        if(palindrom10base(i) and palindrom2base(i))suma+=i;
    }
    cout<<suma;
}
