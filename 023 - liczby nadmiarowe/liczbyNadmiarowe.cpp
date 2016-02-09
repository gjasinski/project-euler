#include <iostream>

using namespace std;

const int N =28130;
bool liczbaNadmiarowa[N];
void znajdzLiczbyNadmiarowe();
int sumaLiczb();

int main()
{
    /*
    Program szuka sumy licz które nie da się zapisać jako sumy dwuch liczb nadmiarowych.
    Liczba nadmiarowa liczba której suma dzielników właściwych jest wieksza od jej samej.
    Tablicujemy liczby nadmiarowe do 28130. Bo wiemy że powyżej tego wszystkie l. da się zapisać jako dwie nadmiarowe.
    Potem sprawdzamy czy da się zapisać jako suma dwuch nadmiarowych. I sumjemy
    */
    znajdzLiczbyNadmiarowe();
    cout<<sumaLiczb();
    return 0;
}

void znajdzLiczbyNadmiarowe()
{
    /*
    Tablicujemy liczby nadmiarowe do 28130. Bo wiemy że powyżej tego wszystkie l. da się zapisać jako dwie nadmiarowe.
    True, jest nadmiarowa, false nie jest.
    */
    int suma;
    int k;
    for(int i=0;i<11;i++) liczbaNadmiarowa[i]=false;
    for(int i=11;i<N;i++)
    {
        suma=1;
        k=2;
        while(k*k<i)
        {
            if(i%k==0) suma+=k+i/k;
            k++;
        }
        if(k*k==i)suma+=k;
        if(suma>i)liczbaNadmiarowa[i]=true; else liczbaNadmiarowa[i]=false;
    }
}

bool czyLiczbaZawieraDwieNadmiarowe(int liczba)
{
    /*
    Sprawdzamy czy liczbe mozna zapisać jako sume 2 liczb nadmiarowych.
    Zwracamy true gdy da sę zapisać, false gdy się nie da.
    */
    int i=1;
    bool koniec=false;
    while(i<liczba and !koniec)
    {
        if(liczbaNadmiarowa[i]==true)
        {
            if(liczbaNadmiarowa[liczba-i]==true) koniec=true;
        }
        i++;
    }
    if(koniec) return true; else return false;
}


int sumaLiczb()
{
    /*
    Sumujemy liczby które nie da sie zapisac jako 2 nadmiarowe.
    Zwracamy sume.
    */
    int suma=0;
    for(int i=0;i<N;i++)
    {
        cout<<i<<endl;
        if(!czyLiczbaZawieraDwieNadmiarowe(i)) suma+=i;
    }
    return suma;
}
