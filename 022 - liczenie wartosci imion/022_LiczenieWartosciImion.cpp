#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int wczytajDane(string tablica[]);
void sortujTabStr(string tablica[], int N);
void liczWartosci(string tablica[], int wartosci[], int j);

int main()
{
    /*
    Program wczytuje serię imion, sortuje je alfabetycznie bombelkowo.
    Zamienia wartości liter na ich odpowiedniki numeryczne odpowiednio zaczynając
    od A = 1 do Z.
    Nastepnie sume odpowiedników liter każdego imienia mnoży przez swój numer w tablicy w kolejności alfabetycznej.
    Szukamy sumy tych pomnożonych sum.
    */
    int N=5200;
    string imiona[N];
    int sumaWartosci[N];

    int j=wczytajDane(imiona);
    sortujTabStr(imiona,j);
    liczWartosci(imiona,sumaWartosci,j);

    return 0;
}
int wczytajDane(string tablica[])
{
    /*
    Wczytanie danych i ich podzielenie do tablicy.
    */
    fstream plik;
    plik.open("problem022_names.txt",ios::in);
    string dane;
    getline(plik,dane);
    int j=0;
    while(dane.length()>0)
    {
        tablica[j]=dane.substr(dane.find_first_of('\"')+1,dane.find_first_of(',')-2);
        dane=dane.substr(dane.find_first_of(',')+1);
        j++;
    }
    return j;
}

void sortujTabStr(string tablica[], int N)
{
    /*
    Sortowanie tablicy bombelkowe.
    */
    bool porownywanie[N];
    int maks=0;
    int k;
    int r1,r2;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N-1;j++)
        {
            k=0;
            r1=tablica[j].length();
            r2=tablica[j+1].length();
            while(tablica[j][k]==tablica[j+1][k] and k<r1 and k<r2) k++;
            if(tablica[j][k]==tablica[j+1][k])
            {
                if(r1>r2)swap(tablica[j],tablica[j+1]);
            }
            else
            {
                if((int)tablica[j][k]>(int)tablica[j+1][k])
                    swap(tablica[j],tablica[j+1]);
            }
        }
    }
}

void liczWartosci(string tablica[], int wartosci[], int j)
{
    /*
    Przeliczanie imion na wartości i sumowanie tablicowe.
    */
    int k;
    for(int i=0;i<j;i++)
    {
        k=0;
        wartosci[i]=0;
        while(k<tablica[i].length())
        {
            wartosci[i]+=(int)tablica[i][k]-64;
            k++;
        }
        wartosci[i]=wartosci[i]*(i+1);

    }
    int X=20;
    int wynik[X];
    for(int i=0;i<X;i++) wynik[i]=0;
    int tmp=0;
    for(int i=0;i<j;i++)
    {
        tmp=0;
        k=X-1;
        tmp=wartosci[i];
        while(tmp>0)
        {
            tmp+=wynik[k];
            wynik[k]=tmp%10;
            tmp=tmp/10;
            k--;
        }
    }
    for(int i=0;i<X;i++) cout<<wynik[i];
}


