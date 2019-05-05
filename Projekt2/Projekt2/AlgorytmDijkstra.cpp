#include "AlgorytmDijkstra.hpp"

constexpr auto oo = 2147483647;

void AlgorytmDijkstra(GrafMacierzSasiedztwa graf, int startowy, int IloscWierzcholkow)
{
	int *odleglosc = new int[IloscWierzcholkow];
	bool *odwiedzony = new bool[IloscWierzcholkow];

	for (int i = 0; i <= IloscWierzcholkow; ++i)
	{
		odleglosc[i] = oo;
		odwiedzony[i] = 0;
	}

	odleglosc[startowy] = 0;
	odwiedzony[startowy] = 1;
	

	for (int i = 1; i <= IloscWierzcholkow; ++i)
	{
		if ((odwiedzony[i] == 0) && graf.CzySasiednie(startowy, i))
		{
			if ((odleglosc[startowy] + graf.ZwrocWageKrawedzi(startowy, i)) < odleglosc[i] || (odleglosc[i] == oo))
				odleglosc[i] = odleglosc[startowy] + graf.ZwrocWageKrawedzi(startowy, i);
		}
	}
}

void AlgorytmDijkstra(GrafListaSasiedztwa graf, int startowy, int IloscWierzcholkow)
{
	int *odleglosc = new int[IloscWierzcholkow];
	bool *odwiedzony = new bool[IloscWierzcholkow];

	for (int i = 0; i <= IloscWierzcholkow; ++i)
	{
		odleglosc[i] = oo;
		odwiedzony[i] = 0;
	}

	odleglosc[startowy] = 0;
	odwiedzony[startowy] = 1;

	Kolejka *Q = new Kolejka(IloscWierzcholkow);
	//Q->dodaj();
}
