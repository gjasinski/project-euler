#include <iostream>

using namespace std;

int main()
{
/*
    Program liczący wartostosci na przekatnych tablicy.
    Tablica ta jest wypełaniana po ślimaku od wew.
    21 22 23 24 25
    20  7  8  9 10
    19  6  1  2 11
    18  5  4  3 12
    17 16 15 14 13
    Nie wypelniamy tablicy zauważamy jednak ze różnica elementów na przekatnych w tej samej iteracji,
    wynosi rozmiar (kolumny/wiersza)-1
*/
    long long int suma=1;
    int popWartosc=1;
    for(int i=3;i<1002;i=i+2)
    {
        suma+=(i-1)*10 +4*popWartosc;
        popWartosc=popWartosc+4*(i-1);
    }
    cout<<suma;
    return 0;
}
