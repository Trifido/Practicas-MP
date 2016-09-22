#ifndef _CIRCULO_H_
#define _CIRCULO_H_
#include "punto.h"
class Circulo {
private:
    Punto centro; ///< Centro del círculo
    double radio; ///< radio del círculo
public:
    Circulo(){ centro.setX(0); centro.setY(0); radio=0; } ///< Constructor: Pone a 0 el punto y el radio
    Circulo(Punto centro, double radio){ this->centro= centro; this->radio= radio; } ///< Constructor: Inicializa el círculo con un centro y un radio
    void set(Punto centro, double radio){ this->centro= centro; this->radio= radio; } ///< Asigna el centro y el radio a un circulo
    Punto getCentro() const { return centro; }
    double getRadio() const { return radio; }
    void escribir() const; ///< Escribe círculo en formato radio-centro
    void leer(); ///< lee círculo en formato radio-centro
    double area() const; ///< Devuelve el área de un círculo
};
double distancia (Circulo c1, Circulo c2);
bool interior (Punto p, Circulo c);
#endif
