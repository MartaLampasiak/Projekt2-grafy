#include <iostream>
#include "MacierzSasiedztwa.hpp"
#include "ListaSasiedztwa.hpp"

int main()
{
	int maksymalnaIloscWierzcholkow = 10;
	GrafMacierzSasiedztwa *Graf1 = new GrafMacierzSasiedztwa(maksymalnaIloscWierzcholkow);
	GrafListaSasiedztwa *Graf2 = new GrafListaSasiedztwa(maksymalnaIloscWierzcholkow);
	Graf2->DodajPolaczenie(0, 1, 3);
	Graf2->DodajPolaczenie(0, 2, 3);
	Graf2->DodajPolaczenie(1, 2, 4);
	Graf2->Wyswietl();
	//Graf1->DodajKrawedz(0, 9, 1);
	//Graf1->DodajKrawedz(0, 9, 2);
	//Graf1->Wyswietl();
	//Graf1->UsunKrawedz(0,9);
	//Graf1->Wyswietl();

	system("pause");
	return 1;
}