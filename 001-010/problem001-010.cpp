#include <iostream>
#include <cmath>

using namespace std;

void problem001();
void problem002();
void problem003(long long int liczba);
void problem004();
void problem005();
void problem005b();
void problem006();
void problem007();
void problem008();
void problem009();
void problem010();

int main()
{
	//problem001();
	//problem002();
	//problem003(600851475143);
	//problem004();
    //problem005();
	problem005b();
	//problem006();
	//problem007();
	//problem008();
	//problem009();
	//problem010();
	return 0;
};

void problem001()
{
/*
    Rozwiazanie siłowe
    Rozwiazanie sprytne:
    Suma=suma_liczb_podzielnych_przez_3 + suma_liczb_podzielnych_przez_5 - suma_liczb_podzielnych_przez_15
    suma liczb podzielnych jest oczywiscie sumą ciągu arytmetycznego.
*/
	int suma=0;
	for (int i=1;i<1000;i++)
	{
		if (i%3==0) suma=suma+i;
		else
		{
			if (i%5==0) suma=suma+i;
		}
	}
	cout << suma;
}

void problem002()
{
	int a,b,c,suma;
	a=2;
	b=1;
	suma=0;
	while (a<4000000)
	{
		c=a;
		a=a+b;
		b=c;
		if (b%2==0)suma=suma+b;
	}
	cout << suma;
}

bool pierwsza(int l)
{
	bool flaga = true;
	if(l==2) return true;
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

void problem003(long long int liczba)
{
	int liczbapierwsza=0;
	int i=sqrt(liczba);

	while (liczbapierwsza==0)
	{
		i--;
		if(liczba%i==0 && pierwsza(i)==true) liczbapierwsza=i;
	}
	cout << i;
}

bool palindrom(int liczba)
{
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

void problem004()
{
	int a,i,p;
	p=0;
	i=998001;
	while (p==0 or p==-1)
	{
		a=999;
		if(p==-1)
		{
			p=0;
			i=i-1;
		}
		while(palindrom(i)==false) {i=i-1;}
		while((i%a)!=0 and (i/a)<1000) {a=a-1;}
		if(i/a<1000) p=i; else p=-1;
	}

	cout <<"palindrom "<<p<<" "<<"= "<<a<<"*"<<p/a;
}

void problem005()
{
	bool test=false;
	int i=20;
	while(test==false)
	{
		i=i+2;
		while(test==false)
		{
			if(i%20!=0) break;
			if(i%19!=0) break;
			if(i%18!=0) break;
			if(i%17!=0) break;
			if(i%16!=0) break;
			if(i%15!=0) break;
			if(i%14!=0) break;
			if(i%13!=0) break;
			if(i%12!=0) break;
			if(i%11!=0) break;
			test=true;
		}
	}
	cout<<i;
}

void problem005b()
{
	bool test=false;
	int i=20;
	while(test==false)
	{
		i=i+2;
		for(int j=20;j>10;j=j-1)
		{
			if(i%j!=0) j=0;
			if(j==11) test=true;
		}
	}
	cout<<endl<<i;
}

//-----------------------------------------------------------%%%%%%
void problem006()
{
	int suma1,suma2=0;
	for(int i=1;i<101;i=i+1) suma1= suma1+i*i;
	suma2=((1+100)*100)/2;
	suma2=suma2*suma2;
	cout <<suma2-suma1;
}

void problem007()
{
	int j;
	int licznik=1;
	bool flaga=false;
	int liczba=1;
	while(licznik <10002)
	{
		liczba=liczba+1;
		j=2;
		flaga = false;
		while (j*j<=liczba&&flaga==false)
		{
			if(liczba%j==0) flaga=true; else j=j+1;
		}
		if (flaga==false) licznik=licznik+1;
	}
	cout <<liczba;
}

void problem008()
{
	string ciagznakow="7316717653133062491922511967442657474235534919493496983520312774506326239578318016984801869478851843858615607891129494954595017379583319528532088055111254069874715852386305071569329096329522744304355766896648950445244523161731856403098711121722383113622298934233803081353362766142828064444866452387493035890729629049156044077239071381051585930796086670172427121883998797908792274921901699720888093776657273330010533678812202354218097512545405947522435258490771167055601360483958644670632441572215539753697817977846174064955149290862569321978468622482839722413756570560574902614079729686524145351004748216637048440319989000889524345065854122758866688116427171479924442928230863465674813919123162824586178664583591245665294765456828489128831426076900422421902267105562632111110937054421750694165896040807198403850962455444362981230987879927244284909188845801561660979191338754992005240636899125607176060588611646710940507754100225698315520005593572972571636269561882670428252483600823257530420752963450";
	long long int suma,max;
	max=0;
	int dlugosc = ciagznakow.length()-14;
	for(int i=0;i<dlugosc;i=i+1)
	{
		suma=1;
		for(int j=i;j<i+13;j=j+1)
		{
			suma=suma*((int)ciagznakow[j]-48);
		}
		if (suma>max) max=suma;
	}
	cout<<max;
}

void problem009()
{
	int a,b,c;
	bool flaga=true;
	for (a=1;a<999;a=a+1)
	{

		if(flaga==true)
		for(b=1;b<998;b=b+1)
		{

			c=1000-a-b;
			if(a*a+b*b==c*c)
			{
				cout<<a*b*c;
				flaga=false;
			}
		}
	}
}

void problem010()
{
	long long int suma=0;
	for (int i=2;i<2000001;i=i+1)
	{
		if(pierwsza(i)==true) suma=suma+i;
	}
	cout <<suma;
}
