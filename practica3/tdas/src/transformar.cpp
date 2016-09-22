#include <iostream>
#include <cstring>
#include "transformar.h"
using namespace std;

bool Negativo(Imagen file){
   if(file.filas()*file.columnas()>0){
      for(int f=0; f<file.filas(); f++){
      	 for(int c=0; c<file.columnas(); c++){
      	    unsigned char pixel=0;
            pixel=255 - file.get(f,c);
 	    file.set(f,c,pixel);
	 }
      }
      return true;
   }
   else{
      cout << "Tamaño erroneo." << endl;
      return false;
   }
}

bool Desplazar(int n, Imagen file){
   if(file.filas()*file.columnas()>0 && n>0){
      for(int f=0; f<file.filas(); f++){
         for(int c=0; c<file.columnas(); c++){
 	    unsigned char pixel=0;
            pixel=file.get(f,c)<<n;
 	    file.set(f,c,pixel);
         }
      }
      return true;
   }
   else{
      cout << "Error en la entrada de datos." << endl;
      return false;
   }
}
