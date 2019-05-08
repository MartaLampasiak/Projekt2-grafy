#pragma once

#include <iostream>
#include "KopiecDijkstra.hpp"

class GrafListaSasiedztwa
{
private:

	int MaxIloscWierzcholkow;

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

	struct ListaWierzcholkow
	{
		Element *pierwszy;

		ListaWierzcholkow()
		{
			pierwszy = NULL;
		}

		void DodajElement(int wierzcholek, int waga)
		{
			Element *nowy = new Element; // tworzy nowy element listy

			// wype³niamy danymi
			nowy->wierzcholek = wierzcholek;
			nowy->waga = waga;

			if (pierwszy == 0) // sprawdzamy czy to pierwszy element listy
			{
				// je¿eli tak to nowy element jest teraz pocz¹tkiem listy
				pierwszy = nowy;
			}

			else
			{
				// w przeciwnym wypadku wêdrujemy na koniec listy
				Element *pom = pierwszy;

				while (pom->nastepny)
				{
					// znajdujemy wskaŸnik na ostatni element
					pom = pom->nastepny;
				}

				pom->nastepny = nowy;  // ostatni element wskazuje na nasz nowy
				nowy->nastepny = 0;     // ostatni nie wskazuje na nic
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

			//jezeli jest to ostatni element, wyzeruj wskaznik ??
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

	GrafListaSasiedztwa(int MaxIloscWierzcholkow)
	{
		this->MaxIloscWierzcholkow = MaxIloscWierzcholkow;
		Lista = new ListaWierzcholkow[MaxIloscWierzcholkow];
	}

	~GrafListaSasiedztwa()
	{
		delete[] Lista;
		Lista = NULL;
	}

	void DodajKrawedz(int poczatkowy, int koncowy, int waga);
	void Wyswietl();
	void ZwrocPrzylegleWierzcholki(elementKopca przylegle[], int wierzcholek, int IloscWierzcholkow);

};