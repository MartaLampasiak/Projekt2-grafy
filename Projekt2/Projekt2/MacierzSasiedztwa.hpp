#pragma once

class GrafMacierzSasiedztwa
{
private:
	int MaxIloscWierzcholkow;
	int **MacierzSasiedztwa;

public:
	GrafMacierzSasiedztwa(int MaxIloscWierzcholkow)
	{
		this->MaxIloscWierzcholkow = MaxIloscWierzcholkow; 
		MacierzSasiedztwa = new int *[MaxIloscWierzcholkow];
		for (int i = 0; i < MaxIloscWierzcholkow; ++i)
		{
			MacierzSasiedztwa[i] = new int[MaxIloscWierzcholkow];
		}
		for (int i = 0; i < MaxIloscWierzcholkow; ++i)
		{
			for (int j = 0; j < MaxIloscWierzcholkow; ++j)
				MacierzSasiedztwa[i][j] = 0;
		}
	}

	~GrafMacierzSasiedztwa();

	void Wyswietl();
	void DodajKrawedz(int poczatkowy, int koncowy, int waga);
	
};