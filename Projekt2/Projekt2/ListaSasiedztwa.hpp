#pragma once

#include <iostream>
#include "KopiecDijkstra.hpp"

/* Klasa umozliwiajaca tworzenie obiektow
   typu GrafListaSasiedztwa
   (Reprezentuje graf oparty na liscie sasiedztwa)
   Metody:
		  DodajKrawedz
		  Wyswietl
		  ZwrocPrzylegleWierzcholki
														*/
class GrafListaSasiedztwa
{
private:

	int MaxIloscWierzcholkow;

	/*	Struktura elementu przechowywanego przez liste	*/
	struct Element
	{
		int wierzcholek = 0;
		int waga = 0;
		Element *nastepny;
		Element()
		{
			nastepny = NULL;
		}
	};

	/* Struktura listy potrzebnej do zaimplementowania listy sasiedztwa			  */
	/* listy beda przechowywac wierzcholki przylegle z wagami dla danych wierzcholkow*/
	struct ListaWierzcholkow
	{
		Element *pierwszy;

		ListaWierzcholkow()
		{
			pierwszy = NULL;
		}

		void DodajElement(int wierzcholek, int waga)
		{
			Element *nowy = new Element; 

			nowy->wierzcholek = wierzcholek;
			nowy->waga = waga;

			if (pierwszy == 0) //  czy pierwszy element listy?
			{
				//  nowy element to pocz¹tkiem listy
				pierwszy = nowy;
			}

			else
			{
				Element *pom = pierwszy;

				while (pom->nastepny)
				{
					// znajdujemy wskaŸnik na ostatni element
					pom = pom->nastepny;
				}

				pom->nastepny = nowy;  
				nowy->nastepny = 0;     
			}
		}
		void UsunPierwszyElement()
		{
			Element *pom = pierwszy;

			if (pom)
			{
				pierwszy = pom->nastepny;
				delete pom;
			}
		}
		void UsunDowolnyElement(int wierzcholek)
		{
			Element *pom, *usuwany;

			if (pierwszy->wierzcholek == wierzcholek)
				UsunPierwszyElement();
			while (pom->nastepny->wierzcholek != wierzcholek)
			{
				pom = pom->nastepny;
			}

			usuwany = pom->nastepny;
			pom->nastepny = pom->nastepny->nastepny;
			delete usuwany;
		}
		void WyswietlListe()
		{
			// wskaznik na pierszy element listy
			Element *pom = pierwszy;
			// przewijamy wskazniki na nastepne elementy
			while (pom)
			{
				std::cout << " " << pom->wierzcholek << ":" << pom->waga;
				pom = pom->nastepny;
			}
		}
		bool CzySasiednie(int wierzcholek)
		{
			Element *pom = pierwszy;
			while (pom)
			{
				if (pom->wierzcholek == wierzcholek)
				{
					return 1;
				}
				pom = pom->nastepny;
			}
			return 0;
		}
		void przylegleWierzcholki(elementKopca przylegle[], int IloscWierzcholkow)
		{
			Element *pom = pierwszy;
			int i = 0;
			while (pom)
			{
				przylegle[i].wierzcholek = pom->wierzcholek;
				przylegle[i].waga = pom->waga;
				pom = pom->nastepny;
				i++;
				if (i == IloscWierzcholkow - 1)
					break;
			}
		}
	};

	ListaWierzcholkow *Lista;

public:
	int IloscKrawedzi = 0;

	/* Konstruktor listy sasiedztwa */
	GrafListaSasiedztwa(int MaxIloscWierzcholkow)
	{
		this->MaxIloscWierzcholkow = MaxIloscWierzcholkow;
		Lista = new ListaWierzcholkow[MaxIloscWierzcholkow];
	}

	/* Destruktor listy sasiedztwa*/
	~GrafListaSasiedztwa()
	{
		delete[] Lista;
		Lista = NULL;
	}

	/* Metoda dodajaca krawedz do listy sasiedztwa wraz z jej waga*/
	void DodajKrawedz(int poczatkowy, int koncowy, int waga);

	/* Metoda wyswietlajaca liste sasiedztwa */
	void Wyswietl();

	/* Metoda zwracajaca wierzcholki przylegle(sasiadow),
	   wykorzystujaca metode zawarta w strukturze listy   */
	void ZwrocPrzylegleWierzcholki(elementKopca przylegle[], int wierzcholek, int IloscWierzcholkow);

};