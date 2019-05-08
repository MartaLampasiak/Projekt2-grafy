#include "KopiecDijkstra.hpp"

// Konstruktor - rezerwuje pamiêæ na kopiec
//-----------------------------------------
Kopiec::Kopiec(int MaxIloscWierzcholkow)
{
	T = new elementKopca[MaxIloscWierzcholkow];  // tworzymy tablicê dynamiczn¹
	IloscWierzcholkow = 0;                 // kopiec jest pusty
}

// Destruktor - usuwa tablicê z pamiêci
//-------------------------------------
Kopiec::~Kopiec()
{
	delete[] T;
}

// Sprawdza, czy kolejka jest pusta
//---------------------------------
bool Kopiec::CzyPusta()
{
	return !IloscWierzcholkow;
}

// Zapisuje do kolejki wg priorytetu
//----------------------------------
void Kopiec::dodaj(int wierzcholek, int waga)
{
	int i, j;

	i = IloscWierzcholkow;
	IloscWierzcholkow++;
	j = (i - 1) / 2;

	while (i > 0 && T[j].waga > waga)
	{
		T[i] = T[j];
		i = j;
		j = (i - 1) / 2;
	}

	T[i].waga = waga;
	T[i].wierzcholek = wierzcholek;
}

// Usuwa z kolejki
//----------------
elementKopca Kopiec::usun()
{
	elementKopca pom;
	pom.wierzcholek = T[0].wierzcholek;
	pom.waga = T[0].waga;
	int i, j, wierzcholek, waga;

	if (IloscWierzcholkow--)
	{
		waga = T[IloscWierzcholkow].waga;
		wierzcholek = T[IloscWierzcholkow].wierzcholek;
		i = 0;
		j = 1;

		while (j < IloscWierzcholkow)
		{
			if (j + 1 < IloscWierzcholkow && T[j + 1].waga < T[j].waga)
				j++;
			if (waga <= T[j].waga)
				break;

			T[i] = T[j];
			i = j;
			j = 2 * j + 1;
		}

		T[i].waga = waga;
		T[i].wierzcholek = wierzcholek;
	}
	return pom;
}

void Kopiec::zamienWagi(int wierzcholek, int innaWaga)
{
	int i = 0;
	while (T[i].wierzcholek != wierzcholek)
	{
		i++;
		if (i == IloscWierzcholkow)
			return;
	}
	T[i].waga = innaWaga;
}


void Kopiec::przywrocMinKopiec()
{
	for (int IdRodzica = 0; IdRodzica < IloscWierzcholkow; ++IdRodzica)
	{
		// zapis elementow drzewa za pomoca indeksow tablicy
		int najmniejszy = IdRodzica;
		int leweDziecko = 2 * IdRodzica + 1;
		int praweDziecko = 2 * IdRodzica + 2;

		if ((leweDziecko < IloscWierzcholkow) && (T[leweDziecko].waga < T[najmniejszy].waga))
			najmniejszy = leweDziecko;

		if ((praweDziecko < IloscWierzcholkow) && (T[praweDziecko].waga < T[najmniejszy].waga))
			najmniejszy = praweDziecko;

		if (najmniejszy != IdRodzica)
		{
			elementKopca pom = T[IdRodzica];
			T[IdRodzica] = T[najmniejszy];
			T[najmniejszy] = pom;
		}
	}
}