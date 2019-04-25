#include <iostream>
#include "ListaSasiedztwa.hpp"

void GrafListaSasiedztwa::DodajKrawedz(int poczatkowy, int koncowy, int waga)
{
	if (Lista[poczatkowy].pierwszy == NULL)
	{
		Lista[poczatkowy].DodajElement(koncowy, waga);
		Lista[koncowy].DodajElement(poczatkowy, waga);
	}
	else if ((Lista[poczatkowy].CzySasiednie(Lista[poczatkowy].pierwszy, koncowy) == 0) && 
			 (Lista[koncowy].CzySasiednie(Lista[koncowy].pierwszy, poczatkowy) == 0))
	{
		Lista[poczatkowy].DodajElement(koncowy, waga);
		Lista[koncowy].DodajElement(poczatkowy, waga);
	}
	else
	{
		return;
	}
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

