#include <iostream>
#include <cmath> // sqrt, M_PI
using namespace std;

class Punto {
private:
    double x; ///< coordenada x del punto
    double y; ///< coordenada y del punto

public:
    Punto(){ x= 0, y= 0;} ///< constructor. Pone a 0 las dos coordenadas
    Punto(double x, double y){ this->x= x; this->y= y; } ///< constructor. Inicializa un punto con dos valores x y
    double getX() const { return x; } ///< Devuelve la coordenada x del punto
    double getY() const { return y; } ///< Devuelve la coordenada y del punto
    void setX(double newXValue){ x= newXValue; } ///< Asigna el valor newXValue a la coordenada x del punto
    void setY(double newYValue){ y= newYValue; } ///< Asigna el valor newYValue a la coordenada y del punto
    void escribir() const; ///<  Escribe un punto en formato (x,y)
    void leer(); ///< // Lee un punto en el formato (x,y)
};


void Punto::escribir() const{
    // Formato de escritura del punto: (x,y)
    cout << "(" << x << ", " << y << ")" << endl;

}

void Punto::leer(){
    // Formato de lectura del punto: (x,y)
    char aux;

    cin >> aux >> x >> aux >> y >> aux;
}

/**
@brief Calcula la distancia entre dos puntos
@param p1 primer punto
@param p2 segundo punto
@return la distancia entre el punto @a p1 y el punto @a p2
*/
double distancia(Punto p1, Punto p2){
    return sqrt((p2.getX() - p1.getX())*(p2.getX() - p1.getX()) + (p2.getY() - p1.getY())*(p2.getY() - p1.getY()));
}

/**
@brief Calcula el punto que está entre dos puntos dados con distancia mínima a ambos
@param p1 primer punto
@param p2 segundo punto
@return un punto entre el punto @a p1 y el punto @a p2 con distancia mínima a ambos
*/
Punto puntoMedio(Punto p1, Punto p2){
    Punto p_medio;
    double x1, y1;

    x1= (p1.getX()+p2.getX())/2;
    y1= (p1.getY()+p2.getY())/2;
    p_medio.setX(x1);
    p_medio.setY(y1);

    return p_medio;
}

