#pragma once

#include <iostream>

/* Klasa pozwalajaca na utworzenie kolejki
   dodatkowej struktury danych potrzebnej do pozniejszego
   wyswietlania wynikowej sciezki dla kazdego wierzcholka 
   w algorytmie Dijkstry								*/

class Kolejka
{
private:

	int element = 0;
	int wielkosc = 0;
	Kolejka *glowa = NULL, *ogon = NULL,
			*nowy = NULL, *pom = NULL;
	Kolejka *nastepny;

public:

	/* Metoda sprawdzajaca czy kolejka jest pusta */
	bool CzyPusta();

	/* Metoda dodajaca element */
	void dodaj(int element);

	/* Metoda usuwajaca element */
	int usun();	
};
