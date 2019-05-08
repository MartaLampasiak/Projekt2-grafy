#include "ListaSasiedztwa.hpp"

void GrafListaSasiedztwa::DodajKrawedz(int poczatkowy, int koncowy, int waga)
{
	if (Lista[poczatkowy].pierwszy == NULL)
	{
		Lista[poczatkowy].DodajElement(koncowy, waga);
		Lista[koncowy].DodajElement(poczatkowy, waga);
	}
	else if ((Lista[poczatkowy].CzySasiednie(koncowy) == 0) &&
			(Lista[koncowy].CzySasiednie(poczatkowy) == 0))
	{
		Lista[poczatkowy].DodajElement(koncowy, waga);
		Lista[koncowy].DodajElement(poczatkowy, waga);
	}
	else
		return;

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

void GrafListaSasiedztwa::ZwrocPrzylegleWierzcholki(elementKopca przylegle[], int wierzcholek, int IloscWierzcholkow)
{
	Lista[wierzcholek].przylegleWierzcholki(przylegle, IloscWierzcholkow);
}
