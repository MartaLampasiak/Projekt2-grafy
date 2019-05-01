#pragma once

class GrafListaSasiedztwa
{
private:
	int MaxIloscWierzcholkow;

	struct Element
	{
		int wierzcholek;
		int waga;
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
				Element *temp = pierwszy;

				while (temp->nastepny)
				{
					// znajdujemy wskaŸnik na ostatni element
					temp = temp->nastepny;
				}

				temp->nastepny = nowy;  // ostatni element wskazuje na nasz nowy
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
	};

	ListaWierzcholkow *Lista;

public:
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
	//void UsunKrawedz(int poczatkowy, int koncowy);
	void Wyswietl();
	
};