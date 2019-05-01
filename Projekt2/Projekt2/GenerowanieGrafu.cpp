#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
#include "GenerowanieGrafu.hpp"

void GenerujGraf(int IloscWierzcholkow, int gestoscGrafu)
{
	srand(time(NULL));
	int MaxIloscKrawedzi = (((gestoscGrafu / 100.0)*IloscWierzcholkow*(IloscWierzcholkow - 1))*0.5);
	int IloscKrawedzi = 0;
	//std::cout << MaxIloscKrawedzi;
	std::fstream graf;
	char nazwa_pliku[20] = "graf.txt";

	graf.open(nazwa_pliku, std::ios::out | std::ios::app | std::ios::in);

	if (graf.good() == true)
	{
		graf << MaxIloscKrawedzi << " " << IloscWierzcholkow << " " << 0 << "\n";
		graf << 1 << " " << 0 << " " << (std::rand() % 10) + 1 << "\n";
		for (int i = 2; i < IloscWierzcholkow; ++i)
		{
			int wierzcholek = std::rand() % (i - 1);
			graf << i << " " << wierzcholek << " " << (std::rand() % 10) + 1 << "\n";
			IloscKrawedzi++;
		}
		graf.seekg(0, std::ios_base::beg);
		std::string pierwszy;
		getline(graf, pierwszy);
		//graf.close();
		for (IloscKrawedzi; IloscKrawedzi < MaxIloscKrawedzi; ++IloscKrawedzi)
		{
			int pomWierzcho쿮kPoczatkowy, pomWierzcholekKoncowy, pomWaga = 0;
			while (!graf.eof())
			{
				graf >> pomWierzcho쿮kPoczatkowy >> pomWierzcholekKoncowy >> pomWaga;
				/*graf >> pomWierzcholekKoncowy;
				graf >> pomWaga;*/
				//std::cout << pomWierzcho쿮kPoczatkowy << " " << pomWierzcholekKoncowy << " " << pomWaga << "\n";
				int wierzcholek_poczatkowy = std::rand() % IloscWierzcholkow;
				int wierzcholek_koncowy = std::rand() % IloscWierzcholkow;
				//graf << wierzcholek_poczatkowy << " " << wierzcholek_koncowy << " " << 2 << "\n";
				while (((wierzcholek_poczatkowy == pomWierzcho쿮kPoczatkowy) && (wierzcholek_koncowy == pomWierzcholekKoncowy)) ||
					((wierzcholek_poczatkowy == pomWierzcholekKoncowy) && (wierzcholek_koncowy == pomWierzcho쿮kPoczatkowy)))
				{
					wierzcholek_poczatkowy = std::rand() % IloscWierzcholkow;
					wierzcholek_koncowy = std::rand() % IloscWierzcholkow;
				}
				std::cout << wierzcholek_poczatkowy << " " << wierzcholek_koncowy << " " << (std::rand() % 10) + 1 << "\n";
				/*while (wierzcholek_poczatkowy == pomWierzcho쿮kPoczatkowy && wierzcholek_poczatkowy == pomWierzcholekKoncowy)
				{
					wierzcholek_poczatkowy = std::rand() % IloscWierzcholkow;
				}
				while (wierzcholek_koncowy == pomWierzcholekKoncowy && wierzcholek_koncowy == pomWierzcho쿮kPoczatkowy)
				{
					wierzcholek_koncowy = std::rand() % IloscWierzcholkow;
				}*/
				//graf << wierzcholek_poczatkowy << " " << wierzcholek_koncowy << " " << (std::rand() % 10) + 1 << "\n";
			}

		}
		//	graf <<  << std::endl;
		graf.close();
	}
}