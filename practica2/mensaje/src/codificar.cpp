#include <iostream>
#include <cstring>
using namespace std;

void LeeLinea(char c[], int tamanio){
   do{
     cin.getline(c,tamanio);
   }while(c[0]=='\0');
}

bool Ocultar(unsigned char imagen[],int n_pixel, const char mensaje[]){
    int lon= strlen(mensaje)+1;
    if(n_pixel<(lon*8))
	return false;
    else{
	unsigned char bit;
	int k=0;
	for(int i=0; i<lon; i++){
	  for(int j=0; j<8; j++){
	     bit=(mensaje[i]<<j)>>7;
	     imagen[k]=(imagen[k]&0xFE)|bit;
	     k++;
	  }
 	}
        cout << " Ocultando...." << endl;
	return true;
    }
}

bool Revelar(const unsigned char imagen[], int n_pixel, char mensaje[])
{
   bool encontrado= false;
   int pixel=0;
   int i=0;

   while(!encontrado && i<n_pixel){
	mensaje[i]=0;
       	for(int j=0; j<8; j++){
		unsigned char bit= imagen[pixel]&0x1;
		mensaje[i]=(mensaje[i])|(bit<<(7-j));
		pixel++;
	}
	if(mensaje[i]=='\0')
		encontrado=true;
	else 
		i++;
   }
   cout << "Revelando...." << endl;
   return encontrado;
}
