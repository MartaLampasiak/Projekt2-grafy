#pragma once


struct elementKopca
{
	int wierzcholek;
	int waga;
};

class Kopiec
{
private:
	elementKopca * T;  // kopiec dynamiczny
	int IloscWierzcholkow;         // liczba elementów

public:
	Kopiec(int MaxIloscWierzcholkow);
	~Kopiec();
	bool CzyPusta();
	void dodaj(int wierzcholek, int waga);
	elementKopca usun();
	void zamienWagi(int wierzcholek, int innaWaga);
	void przywrocMinKopiec();
};