#pragma once

class GrafListaSasiedztwa
{
private:
	int MaxIloscWierzcholkow;

	struct Wierzcholek
	{
		int wierzcholek;
		int waga;
		Wierzcholek *nastepny;
		Wierzcholek()
		{
			nastepny = NULL;
		}
	};

	struct ListaWierzcholkow
	{
		Wierzcholek *pierwszy;

		ListaWierzcholkow()
		{
			pierwszy = NULL;
		}

		void DodajWierzcholek(int wierzcholek, int waga)
		{
			Wierzcholek *nowy = new Wierzcholek; // tworzy nowy element listy

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
				Wierzcholek *temp = pierwszy;

				while (temp->nastepny)
				{
					// znajdujemy wskaŸnik na ostatni element
					temp = temp->nastepny;
				}

				temp->nastepny = nowy;  // ostatni element wskazuje na nasz nowy
				nowy->nastepny = 0;     // ostatni nie wskazuje na nic
			}

		}
		void WyswietlListe()
		{
			// wskaznik na pierszy element listy
			Wierzcholek *pom = pierwszy;
			// przewijamy wskazniki na nastepne elementy
			while (pom)
			{
				std::cout << " " << pom->wierzcholek << ":" << pom->waga;
				pom = pom->nastepny;
			}
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

	void DodajPolaczenie(int poczatkowy, int koncowy, int waga);
	void Wyswietl();
};