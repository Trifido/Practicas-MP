#include <iostream>
#include "transformar.h"
using namespace std;

int main(){
   Imagen file;
   const int MAXNOMBRE=100;
   char nombre_imagen[MAXNOMBRE];
   char nombre_imagen2[MAXNOMBRE];
   int n;
   
   cout << "Introduzca el numero de desplazamientos: ";
   cin >> n;
   cout << "Introduzca la imagen de entrada: ";
   cin >> nombre_imagen;
   cout << "Introduzca la imagen de salida: ";
   cin >> nombre_imagen2;

   file.leerImagen(nombre_imagen);
   Desplazar(n,file);
   file.escribirImagen(nombre_imagen2);
}
