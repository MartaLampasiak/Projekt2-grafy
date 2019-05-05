#include <iostream>
#include "GenerowanieGrafu.hpp"
#include "MacierzSasiedztwa.hpp"
#include "ListaSasiedztwa.hpp"
#include "AlgorytmDijkstra.hpp"


int main()
{
	int maksymalnaIloscWierzcholkow = 10;
	GrafMacierzSasiedztwa *Graf1 = new GrafMacierzSasiedztwa(maksymalnaIloscWierzcholkow);
	GrafListaSasiedztwa *Graf2 = new GrafListaSasiedztwa(maksymalnaIloscWierzcholkow);
	//Graf2->DodajKrawedz(0, 1, 3);
	//Graf2->DodajKrawedz(0, 1, 3);
	//Graf2->DodajKrawedz(2, 0, 3);
	//Graf2->DodajKrawedz(0, 2, 3);
	//Graf2->DodajKrawedz(0, 1, 3);
	//Graf2->Wyswietl();
	//Graf1->DodajKrawedz(0, 9, 1);
	//Graf1->DodajKrawedz(0, 8, 2);
	//Graf1->Wyswietl();
	//Graf1->UsunKrawedz(0,9);
	//Graf1->Wyswietl();
	GenerujGraf2(maksymalnaIloscWierzcholkow, 100);
	std::fstream graf;
	char nazwa_pliku[20] = "graf.txt";
	
	graf.open(nazwa_pliku, std::ios::in);

	if (graf.good() == 0)
	{
		return 0;
	}

	int poczatkowy = 0, koncowy = 0, waga = 0;
	std::string pierwszy;
	getline(graf, pierwszy);

	while (!graf.eof())
	{
		graf >> poczatkowy >> koncowy >> waga;
		//std::cout << poczatkowy << " " << koncowy << " " << waga << "\n";
		//Graf1->DodajKrawedz(poczatkowy, koncowy, waga);
	}
	
	graf.close();

	//std::cout << Graf1->ZwrocWageKrawedzi(2,3);
	
	//Graf1->Wyswietl();

	Kolejka Q(100);   // kolejka 10-cio elementowa
	int i, p, v;

	srand(time(NULL));

	for (i = 0; i < 100; i++)
	{
		v = rand() % 100;
		p = rand() % 10;
		std::cout <<  v << ":" << p << std::endl;
		Q.dodaj(v, p);
	}

	std::cout << "----\n";

	elementKolejki pom;
	while (!Q.CzyPusta())
	{
		pom = Q.usun();
		std::cout << pom.wierzcholek << ":" << pom.waga << std::endl;
		//Q.pop();
	}
	std::cout << Q.CzyPusta();

	system("pause");
	return 1;
}