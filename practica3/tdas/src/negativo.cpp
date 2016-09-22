#include <iostream>
#include "transformar.h"
using namespace std;

int main(){
   Imagen file;
   const int MAXNOMBRE=100;
   char nombre_imagen[MAXNOMBRE];
   char nombre_imagen2[MAXNOMBRE];

   cout << "Introduzca la imagen de entrada: ";
   cin >> nombre_imagen;
   cout << "Introduzca la imagen de salida: ";
   cin >> nombre_imagen2;

   file.leerImagen(nombre_imagen);
   Negativo(file);
   file.escribirImagen(nombre_imagen2);
}
