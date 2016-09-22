#ifndef _CODIFICAR_H_
#define _CODIFICAR_H_
#include "imagen.h"

void LeeLinea(char c[], int tamanio);
bool Ocultar(Imagen imag,int n_pixel, const char mensaje[]);
bool Revelar(Imagen imag, int n_pixel, char mensaje[]);
    
#endif
