/*Revelar mensaje en imagen*/
#include <iostream>
#include "imagenES.h"
#include "codificar.h"
using namespace std;

int main(){
   TipoImagen tipo;
   int filas, columnas;
   const int MAXBUFFER= 1000000;
   const int MAXNOMBRE= 100;
   char nombre[MAXNOMBRE];
   unsigned char buffer[MAXBUFFER];
   
   cout << "Introduzca la imagen de entrada: ";
   cin >> nombre;

   tipo= LeerTipoImagen(nombre, filas, columnas);

   if(tipo==IMG_PGM){
	LeerImagenPGM(nombre, filas, columnas, buffer);
	char mensaje[125000];
        Revelar(buffer, filas*columnas, mensaje);
        cout << "El mensaje obtenido es: " << endl;
        cout << mensaje << endl;
   }
   else if(tipo==IMG_PPM){
	LeerImagenPPM(nombre, filas, columnas, buffer);
	char mensaje[125000];
	Revelar(buffer, filas*columnas, mensaje);
        cout << "El mensaje obtenido es: " << endl;
        cout << mensaje << endl;
   }
   else{
	cout << "Formato de imagen incorrecto." << endl;
   }
}

