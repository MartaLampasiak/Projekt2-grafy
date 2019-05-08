#pragma once
#include "MacierzSasiedztwa.hpp"
#include "ListaSasiedztwa.hpp"
#include "KopiecDijkstra.hpp"
#include "Kolejka.hpp"

/* Algorytm Dijkstra dla reprezentacji grafu za pomoca macierzy */
void AlgorytmDijkstra(GrafMacierzSasiedztwa *graf, int startowy, int IloscWierzcholkow);

/* Algorytm Dijkstra dla reprezentacji grafu za pomoca listy sasiedztwa */
void AlgorytmDijkstra(GrafListaSasiedztwa *graf, int startowy, int IloscWierzcholkow);