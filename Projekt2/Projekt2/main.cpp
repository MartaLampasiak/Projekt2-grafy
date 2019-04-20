#include <iostream>
#include "MacierzSasiedztwa.hpp"

int main()
{
	int maksymalnaIloscWierzcholkow = 10;
	GrafMacierzSasiedztwa *Graf1 = new GrafMacierzSasiedztwa(maksymalnaIloscWierzcholkow);
	Graf1->Wyswietl();
	Graf1->DodajKrawedz(0,1,3);
	Graf1->Wyswietl();

	system("pause");
	return 1;
}