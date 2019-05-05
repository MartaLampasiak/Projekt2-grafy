#pragma once

#include <iostream>

class GrafMacierzSasiedztwa
{
private:
	int MaxIloscWierzcholkow;
	int **MacierzSasiedztwa;

public:
	// Konstruktor 
	GrafMacierzSasiedztwa(int MaxIloscWierzcholkow)
	{
		this->MaxIloscWierzcholkow = MaxIloscWierzcholkow; 
		MacierzSasiedztwa = new int *[MaxIloscWierzcholkow]; 
		for (int i = 0; i < MaxIloscWierzcholkow; ++i)
		{
			MacierzSasiedztwa[i] = new int[MaxIloscWierzcholkow];

			for (int j = 0; j < MaxIloscWierzcholkow; ++j)
				MacierzSasiedztwa[i][j] = 0;
		}
	}

	//Destruktor
	~GrafMacierzSasiedztwa()
	{
		for (int i = 0; i < MaxIloscWierzcholkow; ++i)
			delete[] MacierzSasiedztwa[i];
		delete[] MacierzSasiedztwa;
		MacierzSasiedztwa = NULL;
	}

	void Wyswietl();
	void DodajKrawedz(int poczatkowy, int koncowy, int waga);
	void UsunKrawedz(int poczatkowy, int koncowy);
	bool CzySasiednie(int poczatkowy, int koncowy);
	int ZwrocWageKrawedzi(int poczatkowy, int koncowy);
	
};