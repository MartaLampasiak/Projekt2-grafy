#include <iostream>
#include <chrono>
#include "GenerowanieGrafu.hpp"
#include "MacierzSasiedztwa.hpp"
#include "ListaSasiedztwa.hpp"
#include "AlgorytmDijkstra.hpp"



int main()
{
	std::chrono::duration<double> czasMacierz;
	std::chrono::duration<double> czasLista;

	int IloscWierzcholkow = 0, IloscKrawedzi = 0, startowy = 0;
	int poczatkowy = 0, koncowy = 0, waga = 0;

	int liczbaInstancji = 100;
	int IlosciWierzcholkow[5] = { 10, 50, 100, 500, 1000 };
	int Gestosc[4] = { 25, 50, 75, 100 };

	std::fstream graf;
	std::fstream CzasyMacierz;
	std::fstream CzasyLista;

	char nazwa_pliku[20] = "graf.txt";


	for (int wierzcholki = 0; wierzcholki < 5; ++wierzcholki)
	{
		std::cout << "Graf " << IlosciWierzcholkow[wierzcholki] << "\n";
		for (int gestosc = 0; gestosc < 4; ++gestosc)
		{
			double sumaCzasMacierz = 0, sumaCzasLista = 0;;

			std::cout << gestosc + 1 << ". Aktualna gestosc " << Gestosc[gestosc] << "\n";

			for (int i = 0; i < liczbaInstancji; ++i)
			{

				std::cout << i << "/" << liczbaInstancji << std::endl;
				GenerujGraf2(IlosciWierzcholkow[wierzcholki], Gestosc[gestosc]);

				graf.open(nazwa_pliku, std::ios::in);

				if (graf.good() == 0)
					return 0;

				graf >> IloscKrawedzi >> IloscWierzcholkow;
				GrafMacierzSasiedztwa *GrafM = new GrafMacierzSasiedztwa(IloscWierzcholkow);
				GrafListaSasiedztwa *GrafL = new GrafListaSasiedztwa(IloscWierzcholkow);
				graf >> startowy;

				while (!graf.eof())
				{
					graf >> poczatkowy >> koncowy >> waga;
					GrafM->DodajKrawedz(poczatkowy, koncowy, waga);
					GrafL->DodajKrawedz(poczatkowy, koncowy, waga);
				}

				auto start = std::chrono::system_clock::now();
				AlgorytmDijkstra(GrafM, startowy, IloscWierzcholkow);
				auto end = std::chrono::system_clock::now();

				czasMacierz = end - start;
				sumaCzasMacierz += czasMacierz.count();


				start = std::chrono::system_clock::now();
				AlgorytmDijkstra(GrafL, startowy, IloscWierzcholkow);
				end = std::chrono::system_clock::now();

				czasLista = end - start;
				sumaCzasLista += czasLista.count();

				graf.close();

			}

			CzasyMacierz.open("CzasyMacierz.txt", std::ios::out | std::ios::app);

			if (CzasyMacierz.good() == 0)
				return 0;

			CzasyMacierz << IlosciWierzcholkow[wierzcholki] << " " << Gestosc[gestosc] << " " << (sumaCzasMacierz / 100.0) << std::endl;
			CzasyMacierz.close();

			CzasyLista.open("CzasyLista.txt", std::ios::out | std::ios::app);

			if (CzasyLista.good() == 0)
				return 0;

			CzasyLista << IlosciWierzcholkow[wierzcholki] << " " << Gestosc[gestosc] << " " << (sumaCzasLista / 100.0) << std::endl;
			CzasyLista.close();
		}
	}

	system("pause");
	return 1;
}