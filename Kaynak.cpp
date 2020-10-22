#include<iostream>
#include<iomanip>
#include<windows.h>
#include<time.h>
using namespace std;
struct Sahne
{
	int genislik;
	int yukseklik;
};
struct Lsekli
{
	int x;
	int y;
	int boyut;
	char Lkarakter;
};
void koordinatAta(int x, int y);
Sahne sahneOlustur();
Lsekli lsekliOlustur();
void lSekliCiz(Lsekli h2);
Lsekli lSekliAsagiGotur(Lsekli l);
int main()
{
	srand(time(0));
	Lsekli l1;
	l1 = lsekliOlustur();
	Sahne s1;
	s1 = sahneOlustur();
	while (1)
	{
		system("cls");
		lSekliCiz(l1);
		l1 = lSekliAsagiGotur(l1);
		if (l1.y + l1.boyut * 2 == s1.yukseklik - 1)
		{
			l1 = lsekliOlustur();
		}
		Sleep(100);
	}
}
void koordinatAta(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
Sahne sahneOlustur()
{
	Sahne h1;
	int a;
	int b;
	char karakterler[] = { '+','*','@','$','#' };
	a = rand() % 5;
	karakterler[a];
	int degerler[] = { 30,40,50 };
	b = rand() % 3;
	degerler[b];
	h1.genislik = degerler[b];
	h1.yukseklik = rand() % 11 + 20;
	for (int i = 0; i < h1.genislik; i++)
	{
		cout << karakterler[a];
		Sleep(100);
	}
	for (int i = 0; i < h1.yukseklik; i++)
	{
		koordinatAta(h1.genislik - 1, i);
		cout << karakterler[a];
		Sleep(100);
	}

	for (int i = 0; i < h1.genislik; i++)
	{
		koordinatAta(h1.genislik - 1 - i, h1.yukseklik);
		cout << karakterler[a];
		Sleep(100);
	}

	for (int i = 0; i < h1.yukseklik; i++)
	{
		koordinatAta(0, h1.yukseklik - 1 - i);
		cout << karakterler[a];
		Sleep(100);
	}
	for (int i = 0; i < h1.yukseklik + 3; i++)
		cout << endl;

	return h1;
}
Lsekli lsekliOlustur()
{
	Lsekli h2;
	h2.x = rand() % 21 + 5;
	h2.y = 3;
	h2.boyut = rand() % 6 + 2;
	char  ldizi[] = "*#$+@";
	int lrastgele = rand() % 5;
	h2.Lkarakter = ldizi[lrastgele];
	return h2;
}
void lSekliCiz(Lsekli h2)
{
	for (int i = 0; i < h2.boyut; i++)
	{
		// l seklinin en ustu yatayda 
		koordinatAta(h2.x + i, h2.y);
		cout << h2.Lkarakter;
	}
	for (int i = 0; i < (h2.boyut * 2) + 1; i++)
	{
		//l seklinin boyu komple
		koordinatAta(h2.x, h2.y + i);
		cout << h2.Lkarakter;
	}
	for (int i = 0; i < (h2.boyut) * 2 + 1; i++)
	{
		// l seklinin en alt yatay
		koordinatAta(h2.x + i, h2.y + h2.boyut * 2);
		cout << h2.Lkarakter;
	}
	for (int i = 0; i < h2.boyut + 1; i++)
	{
		// l seklinin dik kýsmý
		koordinatAta(h2.x + h2.boyut - 1, h2.y + i);
		cout << h2.Lkarakter;
	}
	for (int i = 0; i < h2.boyut + 1; i++)
	{
		// l seklinin orta yatay kýsmý
		koordinatAta(h2.x + h2.boyut - 1 + i, h2.y + h2.boyut);
		cout << h2.Lkarakter;
	}
	for (int i = 0; i < h2.boyut + 1; i++)
	{
		// l seklinin alt dik kýsmý
		koordinatAta(h2.x + (h2.boyut) * 2 - 1, h2.y + h2.boyut + i);
		cout << h2.Lkarakter;
	}
}
Lsekli lSekliAsagiGotur(Lsekli l)
{
	l.y++;
	return l;
}
