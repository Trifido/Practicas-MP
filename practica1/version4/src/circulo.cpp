#include <iostream>
#include <cmath>
#include "punto.h"

using namespace std;

class Circulo {
private:
    Punto centro; ///< Centro del círculo
    double radio; ///< radio del círculo
public:
    Circulo(){ centro.setX(0);
	       centro.setY(0);
	       radio=0;
    } ///< Constructor: Pone a 0 el punto y el radio
    Circulo(Punto centro, double radio){ this->centro= centro; this-> radio= radio; } ///< Constructor: Inicializa el círculo con un centro y un radio
    void set(Punto centro, double radio1){ this->centro= centro; this->radio= radio; } ///< Asigna el centro y el radio a un circulo
    Punto getCentro() const { return centro; } ///< Devuelve el centro de un circulo
    double getRadio() const { return radio; } ///< Devuelve el radio de un circulo
    void escribir() const; ///< Escribe círculo en formato radio-centro
    void leer(); ///< lee círculo en formato radio-centro
    double area() const; ///< Devuelve el área de un círculo
};

void Circulo::escribir() const{
    // Formato de escritura del círculo: radio-(x,y)
    cout <<  radio << "-(" << centro.getX() << ", " << centro.getY() << ")" << endl;
}

void Circulo::leer(){
    // Formato de lectura del círculo: radio-(x,y)
    char aux;

    cin >> radio >> aux;
    centro.leer();
}

double Circulo::area() const{
    return M_PI*radio*radio;
}


/**
@brief Calcula la distancia entre dos circulos
@param c1 primer círculo
@param c2 segundo círculo
@return la distancia entre el círculo @a c1 y el círculo @a c2

La distancia entre dos círculos se define como la distancia entre los centros menos los dos radios.
Nótese que la distancia puede ser negativa si los círculos se intersecan
*/
double distancia (Circulo c1, Circulo c2){
    double dist= (distancia(c1.getCentro(), c2.getCentro())) - (c1.getRadio() + c2.getRadio());
    if(dist<0)
	dist*(-1);
    return dist;
}


/**
@brief Comprueba si un punto es interior a un círculo
@param p punto a comprobar
@param c circulo
@retval true si el punto @a p es interior al círculo @a c
@retval false en caso contrario
*/
bool interior (Punto p, Circulo c){
     double dist= distancia(p, c.getCentro());

     if(dist>c.getRadio())
	return false;
     else
	return true;
}
