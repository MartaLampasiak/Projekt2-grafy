#include "MacierzSasiedztwa.hpp"



void GrafMacierzSasiedztwa::DodajKrawedz(int poczatkowy, int koncowy, int waga)
{

	if ((MacierzSasiedztwa[poczatkowy][koncowy] == 0) && (MacierzSasiedztwa[koncowy][poczatkowy] == 0))
	{
		MacierzSasiedztwa[poczatkowy][koncowy] = waga;
		MacierzSasiedztwa[koncowy][poczatkowy] = waga;
		IloscKrawedzi++;
	}

}

void GrafMacierzSasiedztwa::UsunKrawedz(int poczatkowy, int koncowy)
{
	if ((MacierzSasiedztwa[poczatkowy][koncowy] > 0) && (MacierzSasiedztwa[koncowy][poczatkowy] > 0))
	{
		MacierzSasiedztwa[poczatkowy][koncowy] = 0;
		MacierzSasiedztwa[koncowy][poczatkowy] = 0;
		IloscKrawedzi--;
	}

}

void GrafMacierzSasiedztwa::Wyswietl()
{
	for (int i = 0; i < MaxIloscWierzcholkow; ++i)
	{
		std::cout << "\n";
		for (int j = 0; j < MaxIloscWierzcholkow; ++j)
			std::cout << MacierzSasiedztwa[i][j] << " ";
	}
	std::cout << "\n";
}

bool GrafMacierzSasiedztwa::CzySasiednie(int poczatkowy, int koncowy)
{
	if ((MacierzSasiedztwa[poczatkowy][koncowy] > 0) || (MacierzSasiedztwa[koncowy][poczatkowy] > 0))
		return true;
	else
		return false;
}

int GrafMacierzSasiedztwa::ZwrocWageKrawedzi(int poczatkowy, int koncowy)
{
	return MacierzSasiedztwa[poczatkowy][koncowy];
}