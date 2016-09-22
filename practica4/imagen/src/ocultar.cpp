/*Ocultar mensaje en imagen*/
#include <iostream>
#include "imagenES.h"
#include "procesar.h"
using namespace std;

int main(){

   const int MAXNOMBRE=100;
   char nombre_imagen[MAXNOMBRE];
   char nombre_imagen2[MAXNOMBRE];
   unsigned char buffer[MAXBUFFER];
   char mensaje[MAXBUFFER];
   TipoImagen tipo;
   int filas, columnas;

   cout << "Introduzca la imagen de entrada: ";
   cin >> nombre_imagen;
   cout << "Introduzca la imagen de salida: ";
   cin >> nombre_imagen2;

   tipo= LeerTipoImagen(nombre_imagen,filas,columnas);

   cout << "Introduzca el mensaje: ";
   LeeLinea(mensaje, MAXBUFFER-1);

   if(tipo==IMG_PGM){
      LeerImagenPGM(nombre_imagen, filas, columnas, buffer);
      Ocultar(buffer, filas*columnas, mensaje);
      EscribirImagenPGM(nombre_imagen2, buffer, filas, columnas);
   }
   else if(tipo==IMG_PPM){
      LeerImagenPPM(nombre_imagen, filas, columnas, buffer);
      Ocultar(buffer, filas*columnas, mensaje);
      EscribirImagenPPM(nombre_imagen2, buffer, filas, columnas);
   }
   else{
      cout << "Formato de imagen incorrecto." << endl;
   }
}
