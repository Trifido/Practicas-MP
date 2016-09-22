#include "imagen2.h"
#include "imagenES.h"
#include <iostream>
using namespace std;

Imagen::Imagen(){
   fil= col= 0;
   imagen= 0;
}

void Imagen::crear(int f, int c){
   destruir();
   if(f>0 && c>0){
     fil= f;
     col= c;
     imagen= new unsigned char*[fil];
     for(int i=0; i<fil; i++)
        imagen[i]= new unsigned char[col];
   }
   else
     cout << "Error filas o columnas negativas." << endl;
}

int Imagen::filas() const{
   return fil;
}

int Imagen::columnas() const{
   return col;
}

void Imagen::set(int f, int c, unsigned char v){
   if(f>=0 && c>=0)
      imagen[f][c]=v;
}

unsigned char Imagen::get (int f, int c) const{
   return imagen[f][c];
}

void Imagen::destruir(){
   if(imagen!=0){
     for(int i=0; i<fil; i++){
        delete[] imagen[i];
        imagen[i]=0;
     }
     delete[] imagen;
     imagen=0;
     fil= col= 0;
   }
}

bool Imagen::leerImagen(const char file[]){
   int nf, nc;

   TipoImagen tipo=LeerTipoImagen(file,nf,nc);
   if(tipo==IMG_PGM){
      crear(nf,nc);
      unsigned char *datos;
      datos= new unsigned char[nf*nc];

      LeerImagenPGM(file,nf, nc,datos);

      for(int i=0; i<fil; i++)
         for(int j=0; j<col; j++)
            set(i, j, datos[i*col+j]);

      delete[] datos;
      datos=0;
      return true; 
   }
   else{
      cout << "Tipo de imagen desconocido" << endl;
      return false;
   }
}

bool Imagen::escribirImagen(const char file[]) const{
   if(imagen){
      unsigned char *datos;
      datos= new unsigned char[fil*col];

      for(int i=0; i<fil; i++)
         for(int j=0; j<col; j++)
            datos[i*col+j]= get(i, j);

      EscribirImagenPGM(file,datos,fil,col);

      delete[] datos;
      datos=0;

      return true;
   }
   else{
      cout << "Fallo en la imagen." << endl;
      return false;
   }
}
