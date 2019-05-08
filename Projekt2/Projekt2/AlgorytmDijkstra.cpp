#include <iostream>
#include <fstream>
#include "AlgorytmDijkstra.hpp"

constexpr auto oo = 2147483647;

void AlgorytmDijkstra(GrafMacierzSasiedztwa *graf, int startowy, int IloscWierzcholkow)
{
	int *odleglosc = new int[IloscWierzcholkow];
	bool *odwiedzone = new bool[IloscWierzcholkow];
	Kolejka *poprzedni = new Kolejka[IloscWierzcholkow];

	for (int i = 0; i <= IloscWierzcholkow; ++i)
	{
		odwiedzone[i] = 0;
		odleglosc[i] = oo;
	}


	odleglosc[startowy] = 0;

	for (int j = 0; j < graf->IloscKrawedzi; ++j)
	{
		odwiedzone[startowy] = 1;

		for (int i = 0; i < IloscWierzcholkow; ++i)
		{
			if ((odwiedzone[i] == 0) && graf->CzySasiednie(startowy, i))
			{
				if ((odleglosc[startowy] + graf->ZwrocWageKrawedzi(startowy, i) < odleglosc[i]) || (odleglosc[i] == oo))
				{
					odleglosc[i] = odleglosc[startowy] + graf->ZwrocWageKrawedzi(startowy, i);
					poprzedni[i].dodaj(startowy);
				}
			}
		}

		int najmniejszyWierzcholek = -1;
		int najkrotszaDroga = oo;
		for (int i = 0; i < IloscWierzcholkow; ++i)
		{
			if ((odwiedzone[i] == 0) && (odleglosc[i] >= 0) && ((najkrotszaDroga > odleglosc[i])))
			{
				najkrotszaDroga = odleglosc[i];
				najmniejszyWierzcholek = i;
			}
		}

		if (najmniejszyWierzcholek != -1)
			startowy = najmniejszyWierzcholek;
		else
			break;
	}

	std::fstream dijkstraMacierz;
	dijkstraMacierz.open("dijkstraMacierz.txt", std::ios::out | std::ios::app);

	if (dijkstraMacierz.good() == 0)
		return;

	for (int i = 0; i < IloscWierzcholkow; ++i)
	{
		dijkstraMacierz << i << " " << odleglosc[i] << " ";
		while (!(poprzedni[i].CzyPusta()))
		{
			int pom = poprzedni[i].usun();
			dijkstraMacierz << pom;
			if (!(poprzedni[i].CzyPusta()))
			{
				dijkstraMacierz << "->";
			}
		}
		dijkstraMacierz << "\n";
	}
	dijkstraMacierz << "\n";
}


void AlgorytmDijkstra(GrafListaSasiedztwa *graf, int startowy, int IloscWierzcholkow)
{

	int *odleglosc = new int[IloscWierzcholkow];
	bool *odwiedzony = new bool[IloscWierzcholkow];
	Kopiec *Q = new Kopiec(IloscWierzcholkow);
	elementKopca *przylegleW = new elementKopca[IloscWierzcholkow - 1];
	Kolejka *poprzedni = new Kolejka[IloscWierzcholkow];

	for (int i = 0; i < IloscWierzcholkow; ++i)
	{
		if (startowy != i)
		{
			odleglosc[i] = oo;
		}
		odleglosc[startowy] = 0;
		odwiedzony[i] = 0;
		Q->dodaj(i, odleglosc[i]);
	}

	while (!(Q->CzyPusta()))
	{
		for (int i = 0; i < IloscWierzcholkow - 1; ++i)
		{
			przylegleW[i].wierzcholek = -1;
			przylegleW[i].waga = 0;
		}
		elementKopca u = Q->usun();
		odwiedzony[u.wierzcholek] = 1;
		graf->ZwrocPrzylegleWierzcholki(przylegleW, u.wierzcholek, IloscWierzcholkow);

		for (int i = 0; i < IloscWierzcholkow - 1; i++)
		{
			if ((odwiedzony[przylegleW[i].wierzcholek] == 0) && (przylegleW[i].wierzcholek != -1))
			{
				if ((odleglosc[u.wierzcholek] + przylegleW[i].waga) < odleglosc[przylegleW[i].wierzcholek])
				{
					odleglosc[przylegleW[i].wierzcholek] = odleglosc[u.wierzcholek] + przylegleW[i].waga;
					Q->zamienWagi(przylegleW[i].wierzcholek, odleglosc[przylegleW[i].wierzcholek]);
					Q->przywrocMinKopiec();
					poprzedni[przylegleW[i].wierzcholek].dodaj(u.wierzcholek);
				}
			}
		}
	}

	std::fstream dijkstraLista;
	dijkstraLista.open("dijkstraLista.txt", std::ios::out | std::ios::app);

	if (dijkstraLista.good() == 0)
		return ;


	for (int i = 0; i < IloscWierzcholkow; ++i)
	{
		dijkstraLista << i << " " << odleglosc[i] << " ";
		while (!(poprzedni[i].CzyPusta()))
		{
			int temp = poprzedni[i].usun();
			dijkstraLista << temp;
			if (!(poprzedni[i].CzyPusta()))
			{
				dijkstraLista << "->";
			}
		}
		dijkstraLista << std::endl;
	}
	dijkstraLista << std::endl;
	dijkstraLista.close();
}




