#include "imagen1.h"
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
     imagen= new unsigned char[f*c];
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
   if(f>0 && c>0)
      imagen[f*col+c]=v;
}

unsigned char Imagen::get (int f, int c) const{
      return imagen[f*col+c];
}

void Imagen::destruir(){
   if(imagen!=0){
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
      LeerImagenPGM(file,nf, nc,imagen);
      return true; 
   }
   else{
      cout << "Tipo de imagen desconocido" << endl;
      return false;
   }
}

bool Imagen::escribirImagen(const char file[]) const{
   if(imagen){
      EscribirImagenPGM(file,imagen,fil,col);
      return true;
   }
   else{
      cout << "Fallo en la imagen." << endl;
      return false;
   }
}
