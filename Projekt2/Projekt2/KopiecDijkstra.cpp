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
	return T[0].vertex;
}

// Zwraca priorytet pierwszego elementu
//-------------------------------------
int Kolejka::frontWeight()
{
	return T[0].weight;
}

// Zapisuje do kolejki wg priorytetu
//----------------------------------
void Kolejka::push(int vertex, int weight)
{
	int i, j;

	i = size;
	size++;
	j = (i - 1) / 2;

	while (i > 0 && T[j].weight > weight)
	{
		T[i] = T[j];
		i = j;
		j = (i - 1) / 2;
	}

	T[i].weight = weight;
	T[i].vertex = vertex;
}

// Usuwa z kolejki
//----------------
elementKolejki Kolejka::pop()
{
	elementKolejki pom;
	pom.vertex = T[0].vertex;
	pom.weight = T[0].weight;
	int i, j, vertex, weight;

	if (size--)
	{
		weight = T[size].weight;
		vertex = T[size].vertex;

		i = 0;
		j = 1;

		while (j < size)
		{
			if (j + 1 < size && T[j + 1].weight < T[j].weight) j++;
			if (weight <= T[j].weight) break;
			T[i] = T[j];
			i = j;
			j = 2 * j + 1;
		}

		T[i].weight = weight;
		T[i].vertex = vertex;
	}
	return pom;
}
