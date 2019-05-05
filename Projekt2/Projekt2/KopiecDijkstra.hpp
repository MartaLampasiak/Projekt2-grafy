#pragma once


struct elementKolejki
{
	int wierzcholek;
	int waga;
};

class Kolejka
{
private:
	elementKolejki * T;  // kopiec dynamiczny
	int size;         // liczba elementów

public:
	Kolejka(int MaxIloscWierzcholkow);
	~Kolejka();
	bool CzyPusta();
	int  front();
	int  frontWeight();
	void dodaj(int wierzcholek, int waga);
	elementKolejki usun();
};