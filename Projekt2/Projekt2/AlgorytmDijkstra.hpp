#pragma once
#include "MacierzSasiedztwa.hpp"
#include "ListaSasiedztwa.hpp"
#include "KopiecDijkstra.hpp"
#include "Kolejka.hpp"

void AlgorytmDijkstra(GrafMacierzSasiedztwa *graf, int startowy, int IloscWierzcholkow);
void AlgorytmDijkstra(GrafListaSasiedztwa *graf, int startowy, int IloscWierzcholkow);