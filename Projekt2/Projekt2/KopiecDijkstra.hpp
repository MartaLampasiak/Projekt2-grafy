#pragma once


struct elementKolejki
{
	int weight, vertex;
};

class Kolejka
{
private:
	elementKolejki * T;  // kopiec dynamiczny
	int size;         // liczba element�w

public:
	Kolejka(int MaxIloscWierzcholkow);
	~Kolejka();
	bool CzyPusta();
	int  front();
	int  frontWeight();
	void push(int vertex, int weigh);
	elementKolejki pop();
};