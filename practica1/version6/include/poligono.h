#ifndef _POLIGONO_H_
#define _POLIGONO_H_
#include "punto.h"

class Poligono{
private:
	static const int DIM=100;
	Punto ptos[DIM];
	int num_ptos;
public:
	void anadePunto(Punto p);
	int nPuntos(){ return num_ptos; }
	Punto getPunto(int n){ return ptos[n]; }
	double areaPoligono();
	Punto interiorPoligono(){ return ptos[0]; }	
};
#endif
