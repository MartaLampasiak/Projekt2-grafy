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
{	
	assert(koncowy < MaxIloscWierzcholkow);
	if (MacierzSasiedztwa[poczatkowy][koncowy] == 0)
	{
		MacierzSasiedztwa[poczatkowy][koncowy] = waga;
		MacierzSasiedztwa[koncowy][poczatkowy] = waga;
	}
	else
		return;
}

void GrafMacierzSasiedztwa::UsunKrawedz(int poczatkowy, int koncowy)
{   // jezeli krawedzi nie ma to nie ma czego usuwac
	assert(koncowy < MaxIloscWierzcholkow);
	if (MacierzSasiedztwa[poczatkowy][koncowy] > 0)
	{
		MacierzSasiedztwa[poczatkowy][koncowy] = 0;
		MacierzSasiedztwa[koncowy][poczatkowy] = 0;
	}
	else
		return;
}