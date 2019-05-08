#include "GenerowanieGrafu.hpp"


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









