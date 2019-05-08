#include "Kolejka.hpp"


void Kolejka::dodaj(int element)
{
	nowy = new Kolejka;
	nowy->element = element;

	if (glowa == NULL) //dodaj pierwszy element do kolejki
	{
		glowa = nowy;
		ogon = nowy;
		nowy->nastepny = NULL;
	}

	else
	{
		nowy->nastepny = glowa;
		glowa = nowy;
	}
	wielkosc++;
}
int Kolejka::usun()
{
	int usuwany;
	if (ogon && ogon == glowa) 
	{
		usuwany = ogon->element;
		delete ogon;
		ogon = glowa = NULL;
		wielkosc--;
		return usuwany;
	}
	else if (ogon) 
	{
		pom = glowa;
		while (pom->nastepny != ogon)
		{
			pom = pom->nastepny;
		}
		usuwany = ogon->element;
		delete ogon;
		ogon = pom;
		wielkosc--;
		return usuwany;
	}
}

bool Kolejka::CzyPusta()
{
	return !wielkosc;
}