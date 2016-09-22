#include "imagen4.h"
#include "imagenES.h"
#include <iostream>
using namespace std;

Imagen::Imagen(){
   ncol= 0;
   pfilas= 0;
}

void Imagen::crear(int nf, int nc){
   destruir();
   if(nf>0 && nc>0){
     ncol= nc;
     Fila *paux;
     this->pfilas= new Fila;
     this->pfilas->pfila= new unsigned char [nc];
     this->pfilas->sig=0;
     paux=pfilas;
     for(int f=1; f<nf; f++){
 	paux->sig= new Fila;
	paux=paux->sig;
	paux->pfila= new unsigned char [nc];
	paux->sig=0;
     }
   }
   else
     cout << "Error filas o columnas negativas." << endl;
}
int Imagen::filas() const{
   Fila *paux= this->pfilas;
   int fil=0;
   while(paux){
      fil++;
      paux= paux->sig;
   }
   return fil;
}

int Imagen::columnas() const{
   return ncol;
}

void Imagen::set(int f, int c, unsigned char v){
   if(f>0 && c>0){
     Fila *paux= this->pfilas;
     for(int i=0; i<f; i++)
 	paux= paux->sig;
     paux->pfila[c]=v;
   }
}

unsigned char Imagen::get (int f, int c) const{
   Fila *paux= this->pfilas;
   for(int i=0; i<f; i++)
      paux= paux->sig;
   return paux->pfila[c];
}

void Imagen::destruir(){
   if(pfilas!=0){
     int f=filas();
     Fila *paux= this->pfilas;
     for(int i=0; i<f; i++){
     	delete[] paux->pfila;
  	pfilas= paux->sig;
	delete paux;
	paux= pfilas;
     }
   }
}

bool Imagen::leerImagen(const char file[]){
   int nc, nf;

   TipoImagen tipo=LeerTipoImagen(file,nf,nc);
   if(tipo==IMG_PGM){
      crear(nf,nc);
      unsigned char *datos;
      datos= new unsigned char[nf*nc];

      LeerImagenPGM(file,nf, nc,datos);

      for(int i=0; i<nf; i++)  
         for(int j=0; j<nc; j++)
            set(i, j, datos[i*nc+j]);

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
   if(pfilas){
      int fil=filas();
      unsigned char *datos;
      datos= new unsigned char[fil*ncol];

      for(int i=0; i<fil; i++)
         for(int j=0; j<ncol; j++)
            datos[i*ncol+j]= get(i, j);

      EscribirImagenPGM(file,datos,fil,ncol);

      delete[] datos;
      datos=0;

      return true;
   }
   else{
      cout << "Fallo en la imagen." << endl;
      return false;
   }
}
