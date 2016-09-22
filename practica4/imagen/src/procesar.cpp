#include <iostream>
#include <cstring>
#include "procesar.h"
using namespace std;

void LeeLinea(char c[], int tamanio){
   do{
     cin.getline(c,tamanio);
   }while(c[0]=='\0');
}
//n_pixel= fil*col;
bool Ocultar(Imagen imag, int n_pixel, const char mensaje[]){
    int lon= strlen(mensaje)+1;
    if(n_pixel<(lon*8))
	return false;
    else{
	unsigned char bit;
	for(int i=0; i<lon; i++){
	  for(int j=0; j<8; j++){
	     bit=(mensaje[i]<<j)>>7;
	     imag.set(i, j, (imag.get(i, j)&0xFE)|bit);
	  }
 	}
        cout << " Ocultando...." << endl;
	return true;
    }
}

bool Revelar(Imagen imag, int n_pixel, char mensaje[])
{
   bool encontrado= false;
   int fil=0, col=0;
   int i=0;

   while(!encontrado && i<n_pixel){
	mensaje[i]=0;
       	for(int j=0; j<8; j++){
 	   if(col<imag.columnas()){
	        unsigned char bit= imag.get(fil,col)&0x1;
	        mensaje[i]=(mensaje[i])|(bit<<(7-j));
		col++;
	   }
	   else if(fil<imag.filas()){
		fil++;
 		col=0;
		j--;
	   }
	}
	if(mensaje[i]=='\0')
	   encontrado=true;
	else 
	   i++;
   }
   cout << "Revelando...." << endl;
   return encontrado;
}
