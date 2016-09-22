#include <iostream>
#include <cmath>
#include "punto.h"
using namespace std;

class Poligono{
private:
	static const int DIM=100;
	Punto ptos[DIM];
	int num_ptos;
public:
	Poligono(){ num_ptos=0; }
	void anadePunto(Punto p);
	int nPuntos(){ return num_ptos; }
	Punto getPunto(int n){ return ptos[n]; }
	double areaPoligono();
	Punto interiorPoligono(){ return ptos[0]; }
	
};

void Poligono::anadePunto(Punto p){
	ptos[num_ptos]=p;
	num_ptos++;
}

double areaTriangulo(Punto pto1, Punto pto2, Punto pto3){
	double aux= (distancia(pto1,pto2)+distancia(pto2,pto3)+distancia(pto3,pto1))/2;
	double area= sqrt(aux*(aux-distacia(pto1,pto2))*(aux-distancia(pto2,pto3))*(aux-distancia(pto3,pto1)));
	return area;
}

double Poligono::areaPoligono(){
	double area_total=0;
	for(int i=1; i+1<=num_ptos; i++){
	    if(i+1<num_ptos){
		area_total+= areaPoligono(interiorPoligono(),ptos[i],ptos[i+1]);
	    }
	    else{
		area_total+= areaPoligono(interiorPoligono(),ptos[i],ptos[1]);
	    }
	}
	return area_total;
}

