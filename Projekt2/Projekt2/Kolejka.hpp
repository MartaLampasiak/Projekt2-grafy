#pragma once

#include <iostream>

class Kolejka
{
private:

	int element = 0;
	int wielkosc = 0;
	Kolejka *glowa = NULL, *ogon = NULL,
			*nowy = NULL, *pom = NULL;
	Kolejka *nastepny;

public:

	bool CzyPusta();
	void dodaj(int element);
	int usun();	
};
