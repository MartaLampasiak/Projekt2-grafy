#include <iostream>
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
	MacierzSasiedztwa[poczatkowy][koncowy] = waga;
}