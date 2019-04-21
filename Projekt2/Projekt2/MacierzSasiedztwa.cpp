#include <iostream>
#include <assert.h>
#include "MacierzSasiedztwa.hpp"

void GrafMacierzSasiedztwa::Wyswietl()
{
	for (int i = 0; i < MaxIloscWierzcholkow; ++i)
	{
		std::cout << "\n";
		for (int j = 0; j < MaxIloscWierzcholkow; ++j)
			std::cout << MacierzSasiedztwa[i][j] << " ";
	}
	std::cout << "\n";
}

void GrafMacierzSasiedztwa::DodajKrawedz(int poczatkowy, int koncowy, int waga)
{	//czy nie lepiej bool - jezeli krawedz istnieje to nie ma co dodac return false
	//assert(MacierzSasiedztwa[poczatkowy][koncowy] == 0); //?
	assert(koncowy < MaxIloscWierzcholkow);
	if (MacierzSasiedztwa[poczatkowy][koncowy] == 0)
		MacierzSasiedztwa[poczatkowy][koncowy] = waga;
	else
		return;
}

void GrafMacierzSasiedztwa::UsunKrawedz(int poczatkowy, int koncowy)
{   // jezeli krawedzi nie ma to nie ma czego usuwac
	assert(koncowy < MaxIloscWierzcholkow);
	if (MacierzSasiedztwa[poczatkowy][koncowy] > 0)
		MacierzSasiedztwa[poczatkowy][koncowy] = 0;
	else
		return;
}