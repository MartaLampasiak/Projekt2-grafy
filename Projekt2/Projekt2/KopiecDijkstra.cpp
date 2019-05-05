#include "KopiecDijkstra.hpp"

// Konstruktor - rezerwuje pamiêæ na kopiec
//-----------------------------------------
Kolejka::Kolejka(int MaxIloscWierzcholkow)
{
	T = new elementKolejki[MaxIloscWierzcholkow];  // tworzymy tablicê dynamiczn¹
	size = 0;                 // kopiec jest pusty
}

// Destruktor - usuwa tablicê z pamiêci
//-------------------------------------
Kolejka::~Kolejka()
{
	delete[] T;
}

// Sprawdza, czy kolejka jest pusta
//---------------------------------
bool Kolejka::CzyPusta()
{
	return !size;
}

// Zwraca pocz¹tek kolejki.
//-----------------------------
int Kolejka::front()
{
	return T[0].wierzcholek;
}

// Zwraca priorytet pierwszego elementu
//-------------------------------------
int Kolejka::frontWeight()
{
	return T[0].waga;
}

// Zapisuje do kolejki wg priorytetu
//----------------------------------
void Kolejka::dodaj(int wierzcholek, int waga)
{
	int i, j;

	i = size;
	size++;
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
elementKolejki Kolejka::usun()
{
	elementKolejki pom;
	pom.wierzcholek = T[0].wierzcholek;
	pom.waga = T[0].waga;
	int i, j, wierzcholek, waga;

	if (size--)
	{
		waga = T[size].waga;
		wierzcholek = T[size].wierzcholek;

		i = 0;
		j = 1;

		while (j < size)
		{
			if (j + 1 < size && T[j + 1].waga < T[j].waga) j++;
			if (waga <= T[j].waga) break;
			T[i] = T[j];
			i = j;
			j = 2 * j + 1;
		}

		T[i].waga = waga;
		T[i].wierzcholek = wierzcholek;
	}
	return pom;
}
