#include <iostream>
#include "ListaSasiedztwa.hpp"

void GrafListaSasiedztwa::DodajPolaczenie(int poczatkowy, int koncowy, int waga)
{
	Lista[poczatkowy].DodajWierzcholek(koncowy, waga);
	Lista[koncowy].DodajWierzcholek(poczatkowy, waga);
}

void GrafListaSasiedztwa::Wyswietl()
{
	for (int i = 0; i < MaxIloscWierzcholkow; ++i)
	{
		std::cout << i << " ";
		Lista[i].WyswietlListe();
		std::cout << "\n";
	}
}