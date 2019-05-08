#pragma once


struct elementKopca
{
	int wierzcholek;
	int waga;
};

/* Klasa pozwalajaca na utworzenie kopca
   dodatkowej struktury danych potrzebnej do algorytmu
   Dijkstry - sluzy jako kolejka priorytetowa			*/
													
class Kopiec
{
private:
	elementKopca * T;  
	int IloscWierzcholkow;         

public:
	/* Konstruktor kopca - rezerwacja pamieci */
	Kopiec(int MaxIloscWierzcholkow);

	/* Destruktor kopca - usuwanie z pamieci */
	~Kopiec();

	/* Metoda sprawdzajaca czy kopiec(kolejka priorytetowa) jest pusty */
	bool CzyPusta();

	/* Metoda zapisujaca do kopca (kolejki priorytetowej) wedlug priorytetu */
	void dodaj(int wierzcholek, int waga);

	/* Metoda usuwajaca element z kopca */
	elementKopca usun();

	/* Metoda zamieniajaca wage na inna (nowa) */
	void zamienWagi(int wierzcholek, int innaWaga);

	/* Metoda przywracajaca minimalny kopiec */
	/* Rodzic mniejszy od dziecka			 */		
	void przywrocMinKopiec();
};