#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

void problem011();
void problem012();
void problem013();
void problem014();
void problem015();
void problem016();
void problem017();
void problem018();
void problem019();
void problem020();

int main()
{
	//problem011();
	//problem012();
	//problem013();
	//problem014();
    //problem015();
	//problem016();
	//problem017();
	problem018();
	//problem019();
	//problem020();
	return 0;
};

void problem011()
{
	int dane[20][20];
	string ciag_znakow="08 02 22 97 38 15 00 40 00 75 04 05 07 78 52 12 50 77 91 08";
	ciag_znakow+="49 49 99 40 17 81 18 57 60 87 17 40 98 43 69 48 04 56 62 00";
	ciag_znakow+="81 49 31 73 55 79 14 29 93 71 40 67 53 88 30 03 49 13 36 65";
	ciag_znakow+="52 70 95 23 04 60 11 42 69 24 68 56 01 32 56 71 37 02 36 91";
	ciag_znakow+="22 31 16 71 51 67 63 89 41 92 36 54 22 40 40 28 66 33 13 80";
	ciag_znakow+="24 47 32 60 99 03 45 02 44 75 33 53 78 36 84 20 35 17 12 50";
	ciag_znakow+="32 98 81 28 64 23 67 10 26 38 40 67 59 54 70 66 18 38 64 70";
	ciag_znakow+="67 26 20 68 02 62 12 20 95 63 94 39 63 08 40 91 66 49 94 21";
	ciag_znakow+="24 55 58 05 66 73 99 26 97 17 78 78 96 83 14 88 34 89 63 72";
	ciag_znakow+="21 36 23 09 75 00 76 44 20 45 35 14 00 61 33 97 34 31 33 95";
	ciag_znakow+="18 17 53 28 22 75 31 67 15 94 03 80 04 62 16 14 09 53 56 92";
	ciag_znakow+="16 39 05 42 96 35 31 47 55 58 88 24 00 17 54 24 36 29 85 57";
	ciag_znakow+="86 56 00 48 35 71 89 07 05 44 44 37 44 60 21 58 51 54 17 58";
	ciag_znakow+="19 80 81 68 05 94 47 69 28 73 92 13 86 52 17 77 04 89 55 40";
	ciag_znakow+="04 52 08 83 97 35 99 16 07 97 57 32 16 26 26 79 33 27 98 66";
	ciag_znakow+="88 36 68 87 57 62 20 72 03 46 33 67 46 55 12 32 63 93 53 69";
	ciag_znakow+="04 42 16 73 38 25 39 11 24 94 72 18 08 46 29 32 40 62 76 36";
	ciag_znakow+="20 69 36 41 72 30 23 88 34 62 99 69 82 67 59 85 74 04 36 16";
	ciag_znakow+="20 73 35 29 78 31 90 01 74 31 49 71 48 86 81 16 23 57 05 54";
	ciag_znakow+="01 70 54 71 83 51 54 69 16 92 33 48 61 43 52 01 89 19 67 48";
	for (int i=0;i<20;i=i+1)
	{
		for (int j=0;j<20;j=j+1)
		{
			dane[i][j]=((int)ciag_znakow[i*59+j*3]-48)*10+((int)ciag_znakow[i*59+j*3+1]-48);
		}
	}
	int max=0;
	int suma=1;
	int k;
	for (int i=0;i<20;i=i+1)
	{
		for (int j=0;j<17;j=j+1)
		{
			suma=1;
			for (int k=0;k<4;k=k+1)
			{
				suma=suma*dane[i][j+k];
			}
			if(suma>max) max=suma;
		}
	}
	for (int i=0;i<20;i=i+1)
	{
		for (int j=0;j<17;j=j+1)
		{
			suma=1;
			for (int k=0;k<4;k=k+1)
			{
				suma=suma*dane[j+k][i];
			}
			if(suma>max) max=suma;
		}
	}
	for (int i=0;i<17;i=i+1)
	{
		for (int j=0;j<17;j=j+1)
		{
			suma=1;
			suma=suma*dane[i][j];
			suma=suma*dane[i+1][j+1];
			suma=suma*dane[i+2][j+2];
			suma=suma*dane[i+3][j+3];
			if(suma>max) max=suma;
		}
	}
	for (int i=0;i<17;i=i+1)
	{
		for (int j=3;j<20;j=j+1)
		{
			suma=1;
			suma=suma*dane[i][j];
			suma=suma*dane[i+1][j-1];
			suma=suma*dane[i+2][j-2];
			suma=suma*dane[i+3][j-3];
			if(suma>max) max=suma;
		}
	}
	cout << max;
}

int iloscDzielnikowLiczby(int liczba)
{
    //ilosc dzielnikow liczby
    int suma=0;
    int i;
    for(i=1;i*i<liczba;i++)
    {
        if(liczba%i==0) suma+=2;
    }
    if(i*i==liczba) suma++;
    return suma;
}
void problem012()
{
    //program sprawdza jaka jest 1. liczba trójkątna o wiekszej ilosci dzielnikow niz 500
    int liczbaTrojkatna=0;;
    int i=0;
    while(iloscDzielnikowLiczby(liczbaTrojkatna)<500)
    {
        i++;
        liczbaTrojkatna+=i;
    }
    cout<<liczbaTrojkatna;
}

void problem013()
{
    const int N = 1000;
    const int RLiczby = 50;
    const int IloscLiczb =100;
    string data = "37107287533902102798797998220837590246510135740250#46376937677490009712648124896970078050417018260538#74324986199524741059474233309513058123726617309629#91942213363574161572522430563301811072406154908250#23067588207539346171171980310421047513778063246676#89261670696623633820136378418383684178734361726757#28112879812849979408065481931592621691275889832738#44274228917432520321923589422876796487670272189318#47451445736001306439091167216856844588711603153276#70386486105843025439939619828917593665686757934951#62176457141856560629502157223196586755079324193331#64906352462741904929101432445813822663347944758178#92575867718337217661963751590579239728245598838407#58203565325359399008402633568948830189458628227828#80181199384826282014278194139940567587151170094390#35398664372827112653829987240784473053190104293586#86515506006295864861532075273371959191420517255829#71693888707715466499115593487603532921714970056938#54370070576826684624621495650076471787294438377604#53282654108756828443191190634694037855217779295145#36123272525000296071075082563815656710885258350721#45876576172410976447339110607218265236877223636045#17423706905851860660448207621209813287860733969412#81142660418086830619328460811191061556940512689692#51934325451728388641918047049293215058642563049483#62467221648435076201727918039944693004732956340691#15732444386908125794514089057706229429197107928209#55037687525678773091862540744969844508330393682126#18336384825330154686196124348767681297534375946515#80386287592878490201521685554828717201219257766954#78182833757993103614740356856449095527097864797581#16726320100436897842553539920931837441497806860984#48403098129077791799088218795327364475675590848030#87086987551392711854517078544161852424320693150332#59959406895756536782107074926966537676326235447210#69793950679652694742597709739166693763042633987085#41052684708299085211399427365734116182760315001271#65378607361501080857009149939512557028198746004375#35829035317434717326932123578154982629742552737307#94953759765105305946966067683156574377167401875275#88902802571733229619176668713819931811048770190271#25267680276078003013678680992525463401061632866526#36270218540497705585629946580636237993140746255962#24074486908231174977792365466257246923322810917141#91430288197103288597806669760892938638285025333403#34413065578016127815921815005561868836468420090470#23053081172816430487623791969842487255036638784583#11487696932154902810424020138335124462181441773470#63783299490636259666498587618221225225512486764533#67720186971698544312419572409913959008952310058822#95548255300263520781532296796249481641953868218774#76085327132285723110424803456124867697064507995236#37774242535411291684276865538926205024910326572967#23701913275725675285653248258265463092207058596522#29798860272258331913126375147341994889534765745501#18495701454879288984856827726077713721403798879715#38298203783031473527721580348144513491373226651381#34829543829199918180278916522431027392251122869539#40957953066405232632538044100059654939159879593635#29746152185502371307642255121183693803580388584903#41698116222072977186158236678424689157993532961922#62467957194401269043877107275048102390895523597457#23189706772547915061505504953922979530901129967519#86188088225875314529584099251203829009407770775672#11306739708304724483816533873502340845647058077308#82959174767140363198008187129011875491310547126581#97623331044818386269515456334926366572897563400500#42846280183517070527831839425882145521227251250327#55121603546981200581762165212827652751691296897789#32238195734329339946437501907836945765883352399886#75506164965184775180738168837861091527357929701337#62177842752192623401942399639168044983993173312731#32924185707147349566916674687634660915035914677504#99518671430235219628894890102423325116913619626622#73267460800591547471830798392868535206946944540724#76841822524674417161514036427982273348055556214818#97142617910342598647204516893989422179826088076852#87783646182799346313767754307809363333018982642090#10848802521674670883215120185883543223812876952786#71329612474782464538636993009049310363619763878039#62184073572399794223406235393808339651327408011116#66627891981488087797941876876144230030984490851411#60661826293682836764744779239180335110989069790714#85786944089552990653640447425576083659976645795096#66024396409905389607120198219976047599490197230297#64913982680032973156037120041377903785566085089252#16730939319872750275468906903707539413042652315011#94809377245048795150954100921645863754710598436791#78639167021187492431995700641917969777599028300699#15368713711936614952811305876380278410754449733078#40789923115535562561142322423255033685442488917353#44889911501440648020369068063960672322193204149535#41503128880339536053299340368006977710650566631954#81234880673210146739058568557934581403627822703280#82616570773948327592232845941706525094512325230608#22918802058777319719839450180888072429661980811197#77158542502016545090413245809786882778948721859617#72107838435069186155435662884062257473692284509516#20849603980134001723930671666823555245252804609722#53503534226472524250874054075591789781264330331690";
    short suma[N];
    short liczba[50];
    for(int i=0;i<N;i++) suma[i]=0;
    int licznik=0;
    int indeks=N-1;
    int tmp=0;
    for (int i=0;i<IloscLiczb;i++)
    {
        if(tmp!=0)cout<<"ERROR";tmp=0;
        indeks=N-1;
        for(int j=0;j<RLiczby;j++)
        {
            liczba[j]=(int)data[licznik]-48;
            licznik++;
        }
        licznik++;
        for(int j=RLiczby-1;j>=0;j--)
        {
            tmp = tmp+suma[indeks]+liczba[j];
            suma[indeks]=tmp%10;
            tmp=tmp/10;
            indeks--;
        }
        while(tmp>0)
        {
            tmp = tmp+suma[indeks];
            suma[indeks]=tmp%10;
            tmp=tmp/10;
            indeks--;
        }
    }
    indeks=0;
    while(suma[indeks]==0) indeks++;
    for(int i=indeks;i<indeks+10;i++) cout<<suma[i];
}

void problem014()
{
    int licz=0;
    int maks=0;
    int maxindeks=0;
    long long int j;
    for(int i=1;i<1000001;i++)
    {
        j=i;
        licz=0;
        while(j!=1)
        {
            if(j%2==0) j=j/2; else j=j*3+1;
            licz++;
        }
        if(licz>maks)
        {
            maks=licz;
            maxindeks=i;

        }
    }
    cout<<maxindeks<<endl<<maks;
}
long long int ilosc_rekurencji;
void dalej_rekurencjo(int k, int w, int g)
{
    if(k<g)dalej_rekurencjo(k+1,w,g);
    if(w<g)dalej_rekurencjo(k,w+1,g);
    if(k==g and w==g)ilosc_rekurencji++;
}
void problem015()
{
    ilosc_rekurencji=0;
    dalej_rekurencjo(0,0,20);
    cout<<ilosc_rekurencji;
}

void problem016()
{
    const int N=10000;
    int tab[N];
    for(int i=0;i<N;i++) tab[i]=0;
    tab[N-1]=2;
    int koniec=N-1;
    int tmp=0;
    for(int i=1;i<1000;i++)
    {
        tmp=0;
        for(int j=N-1;j>=koniec;j--)
        {
            tmp=tmp+tab[j]*2;
            tab[j]=tmp%10;
            tmp=tmp/10;
        }
        while(tmp>0)
        {
            koniec--;
            tab[koniec]=tmp%10;
            tmp=tmp/10;
        }

    }
    int licz=0;
    for(int i=0;i<N;i++)
    {
        licz=licz+tab[i];
    }

    cout<<licz;
}

void problem017()
{
    /*
    Funkcja liczy ilosc znaków w angielskich liczebnikach od 1 do 1000
    */
    int od1do9 = 36;
    int dziesiec = 3;
    int od11do19 = 67;
    int dzisiatki = 46;
    int sto = 7;
    int tysiac = 11;
    int i = 3;

    int od20do99= dzisiatki*10+od1do9*8;
    int od1do99=od1do9+dziesiec+od11do19+od20do99;
    cout<<od1do99<<endl;
    int od100do999=100*od1do9+900*sto+891*i+9*od1do99;
    cout<<od100do999<<endl;
    cout<<tysiac+od100do999+od1do99;
}
int tab[15][29];
int maks=0;
void liczpiramida(int k, int w, int s)
{
    if(k<15)
    {
        liczpiramida(k+1,w+1,s+tab[k][w]);
        liczpiramida(k+1,w-1,s+tab[k][w]);
    }
    else
    {
        if(s>maks)maks=s;
    }
}
void problem018()
{
    /*
    Wczytujemy trójkąt liczb, idąć od wierzchołka znajdujemy ścieżkę z najwieksza sumą wartości
    Bruteforce -rekurencyjny
    */
    fstream plik;
    plik.open("problem018.txt",ios::in);

    string linia;
    int i=0;
    int j=15;
    for(int i=0;i<15;i++)
        for(int j=0;j<29;j++)tab[i][j]=0;
    tab[0][14]=75;
    j=13;
    getline(plik,linia);
    for(int w=1;w<15;w++){
        linia="";
        getline(plik,linia);
        for(int k=0;k<=w;k++)
        {
            tab[w][j+2*k]=10*((int) linia[3*k]-48)+(int) linia[3*k+1]-48;
        };
        j--;
    }
    liczpiramida(0,14,0);
    cout<<maks;
}
int ile_nd(int pierwszydzientygodnia)
{
    //0 -  pn
    /*int msc=31;
    if(pierwszydzientygodnia!=0) msc=msc-7+pierwszydzientygodnia;
    cout<<msc<<endl;
    */
    //return 1+msc/7;
    if(pierwszydzientygodnia%7==6)return 1; else return 0;
}
void problem019()
{
    /*
    Program liczący ilosc niedziel w okresie 1 Jan 1901 to 31 Dec 2000
    Wrzesien, kwiecien, czerwiec, listopad - 30 dni
    luty -28/29 dni
    reszta 31 dni
    */
    int msc_nieprzestepny = 28;
    int msc_przestepny = 29;
    int msc_30=30;
    int msc_31=31;
    int suma_dni=365;
    int suma_nd=0;
    for(int i=1901;i<2001;i++)
    {
        //styczen
        suma_nd+=ile_nd(suma_dni%7);
        suma_dni+=msc_31;
        //luty
        suma_nd+=ile_nd(suma_dni%7);
        if(i%4!=0)suma_dni+=msc_nieprzestepny;
        else
        {
            if(i%1000==0)
            {
                if(i%400==0)suma_dni+=msc_przestepny; else suma_dni=+msc_nieprzestepny;
            }
            else suma_dni+=msc_przestepny;
        }
        //marzec
        suma_nd+=ile_nd(suma_dni%7);
        suma_dni+=msc_31;
        //kwiecien
        suma_nd+=ile_nd(suma_dni%7);
        suma_dni+=msc_30;
        //maj
        suma_nd+=ile_nd(suma_dni%7);
        suma_dni+=msc_31;
        //czer
        suma_nd+=ile_nd(suma_dni%7);
        suma_dni+=msc_30;
        //lip
        suma_nd+=ile_nd(suma_dni%7);
        suma_dni+=msc_31;
        //sierp
        suma_nd+=ile_nd(suma_dni%7);
        suma_dni+=msc_31;
        //wrz
        suma_nd+=ile_nd(suma_dni%7);
        suma_dni+=msc_30;
        //paz
        suma_nd+=ile_nd(suma_dni%7);
        suma_dni+=msc_31;
        //lis
        suma_nd+=ile_nd(suma_dni%7);
        suma_dni+=msc_30;
        //gr
        suma_nd+=ile_nd(suma_dni%7);
        suma_dni+=msc_31;
        cout<<suma_nd<<endl;
    }
    cout<<suma_nd;
}
int silnia(int silnia)
{
    /*
    Program liczący silnie duzych liczb, zmodyfikowany aby liczył sume cyfr
    */
	static int size = 10000;
	short tablica[size];
	tablica[size-1]=1;
	for (int i=0;i<size-1;i=i+1)
	{
		tablica[i]=0;
	}

	int b,bufor;
	b=bufor=0;
	int j;

	int k=size-2;
	int s=1;
	for (int i=size-1;i>=size-silnia;i=i-1)
	{
		bufor=0;
		j=size-1;
		while (j>k)
		{
			b=tablica[j]*s+bufor;
			tablica[j]=b%10;
			bufor=b/10;
			j=j-1;
		}
		while(bufor>0)
		{
			tablica[j]=bufor%10;
			bufor=bufor/10;
			j=j-1;
		}
		k=j-1;
		s=s+1;
	}
	while(bufor>0)
	{
		tablica[j]=bufor%10;
		bufor=bufor/10;
		j=j-1;
	}
	j=0;
	int wynik=0;
	for(int j=0;j<size;j++) wynik=wynik+tablica[j];
	return wynik;
}
void problem020()
{
    /*
    Suma cyfr 100!
    */
    cout<<silnia(100);
}
