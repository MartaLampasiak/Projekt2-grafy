#pragma once

#include <iostream>

/* Klasa umozliwiajaca tworzenie obiektow
   typu GrafMacierzSasiedztwa             
   (Reprezentuje graf oparty na macierzy sasiedztwa)
   Metody:
		  DodajKrawedz
		  UsunKrawedz
		  Wyswietl
		  CzySasiednie
		  ZwrocWageKrawedzi
														*/
class GrafMacierzSasiedztwa
{
private:

	int MaxIloscWierzcholkow;
	int **MacierzSasiedztwa;
	int IloscWierzcholkow = 0;

public:

	int IloscKrawedzi = 0;

	/* Konstruktor Macierzy sasiedztwa */
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

	/* Destruktor Macierzy sasiedztwa */
	~GrafMacierzSasiedztwa()
	{
		for (int i = 0; i < MaxIloscWierzcholkow; ++i)
			delete[] MacierzSasiedztwa[i];
		delete[] MacierzSasiedztwa;
		MacierzSasiedztwa = NULL;
	}

	/* Metoda dodajaca krawedz z okreslona waga w grafie nieskierowanym */
	void DodajKrawedz(int poczatkowy, int koncowy, int waga);

	/* Metoda usuwajaca krawedz */
	void UsunKrawedz(int poczatkowy, int koncowy);

	/* Metoda wyswietlajaca cala macierz sasiedztwa */
	void Wyswietl();

	/* Metoda sprawdzajaca czy wierzcholki sa przylegle (sasiednie)
	   Czy w macierzy wpisana jest waga krawedzi					*/
	bool CzySasiednie(int poczatkowy, int koncowy);

	/* Metoda zwracajaca wage krawedzi pomiedzy dwoma wybranymi wierzcholkami */
	int ZwrocWageKrawedzi(int poczatkowy, int koncowy);

};