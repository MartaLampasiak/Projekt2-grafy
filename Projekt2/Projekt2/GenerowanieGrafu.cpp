#include "GenerowanieGrafu.hpp"

void GenerujGraf(int IloscWierzcholkow, int gestoscGrafu)
{
	srand(time(NULL));
	int MaxIloscKrawedzi = (((gestoscGrafu / 100.0)*IloscWierzcholkow*(IloscWierzcholkow - 1))*0.5);
	int IloscKrawedzi = 0;
	std::fstream graf;
	char nazwa_pliku[20] = "graf.txt";

	graf.open(nazwa_pliku, std::ios::trunc | std::ios::out);
	graf.close();

	graf.open(nazwa_pliku, std::ios::out | std::ios::app);

	if (graf.good() == 0)
	{
		return;
	}
	graf << MaxIloscKrawedzi << " " << IloscWierzcholkow << " " << 0 << "\n";
	graf << 1 << " " << 0 << " " << (std::rand() % 9) + 1 << "\n";
	for (int i = 2; i < IloscWierzcholkow; ++i)
	{
		int wierzcholek = std::rand() % (i - 1);
		graf << i << " " << wierzcholek << " " << (std::rand() % 9) + 1 << "\n";
		IloscKrawedzi++;
	}
	graf.close();
	graf.open(nazwa_pliku, std::ios::in | std::ios::out | std::ios::app);
	if (graf.good() == false)
	{
		return;
	}

	std::string pierwszy;
	getline(graf, pierwszy);

	for (IloscKrawedzi; IloscKrawedzi < MaxIloscKrawedzi - 1; ++IloscKrawedzi)
	{
		int pomWierzcholekPoczatkowy = 0, pomWierzcholekKoncowy = 0, pomWaga = 0;
		int wierzcholek_poczatkowy = 0, wierzcholek_koncowy = 0;

		do
		{
			wierzcholek_poczatkowy = std::rand() % IloscWierzcholkow;
			wierzcholek_koncowy = std::rand() % IloscWierzcholkow;
		} while (wierzcholek_poczatkowy == wierzcholek_koncowy);

	
		graf.clear();
		graf.seekg(0, std::ios_base::beg);
		getline(graf, pierwszy);

		do
		{
			graf >> pomWierzcholekPoczatkowy >> pomWierzcholekKoncowy >> pomWaga;

			while ((((wierzcholek_poczatkowy == pomWierzcholekPoczatkowy) && (wierzcholek_koncowy == pomWierzcholekKoncowy)) ||
				((wierzcholek_poczatkowy == pomWierzcholekKoncowy) && (wierzcholek_koncowy == pomWierzcholekPoczatkowy))) ||
				(wierzcholek_poczatkowy == wierzcholek_koncowy))
			{
				wierzcholek_poczatkowy = std::rand() % IloscWierzcholkow;
				wierzcholek_koncowy = std::rand() % IloscWierzcholkow;
				//std::cout << "ZAMIANA!" << "\n";
				graf.clear();
				graf.seekg(0, std::ios_base::beg);
				getline(graf, pierwszy);
			}


		} while (!graf.eof());
			std::cout << IloscKrawedzi << "/"<< MaxIloscKrawedzi << "\n";

		graf.clear();
		graf.seekp(0, std::ios_base::end);
		graf << wierzcholek_poczatkowy << " " << wierzcholek_koncowy << " " << (std::rand() % 9) + 1 << "\n";
		
	}//for
	std::cout << "koniec dodawania";
	graf.close();

}//void


void GenerujGraf2(int IloscWierzcholkow, int gestoscGrafu)
{
	srand(time(NULL));
	int MaxIloscKrawedzi = (((gestoscGrafu / 100.0)*IloscWierzcholkow*(IloscWierzcholkow - 1))*0.5);
	int IloscKrawedzi = 0;
	std::fstream graf;
	char nazwa_pliku[20] = "graf.txt";

	graf.open(nazwa_pliku, std::ios::trunc | std::ios::out);
	graf.close();

	graf.open(nazwa_pliku, std::ios::app);

	if (graf.good() == 0)
	{
		return;
	}
	graf << MaxIloscKrawedzi << " " << IloscWierzcholkow << " " << 0 << "\n";

	int ileWierzcholkowZrobiono = 0;
	for (int j = 1; j < IloscWierzcholkow; ++j)
	{
		for (int i = 0; i < IloscWierzcholkow; ++i)
		{
			graf << i % IloscWierzcholkow << " " << (i + j) % IloscWierzcholkow << " " << (std::rand() % 9) + 1 << "\n";
			ileWierzcholkowZrobiono++;

			if (ileWierzcholkowZrobiono == MaxIloscKrawedzi)
				break;
		}
		if (ileWierzcholkowZrobiono == MaxIloscKrawedzi)
			break;
	}
	graf.close();
}