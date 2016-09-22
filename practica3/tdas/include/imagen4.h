#ifndef _IMAGEN4_H_
#define _IMAGEN4_H_

struct Fila{
   unsigned char *pfila;
   Fila *sig;
};

class Imagen {
private:
   int ncol;
   Fila *pfilas;
public:
   Imagen(); // Constructor que crea una imagen vacía (0 filas, 0 columnas)
   void crear(int f, int c); // Reserva recursos en memoria dinámica
   int filas() const; // Devuelve el número filas de esta imagen
   int columnas() const; // Devuelve el número columnas de esta imagen
   void set(int f, int c, unsigned char v); // Asigna v en fila f, columna c
   unsigned char get (int f, int c) const;//Devuelve pixel de fila f, columna c
   void destruir(); // Libera recursos de esta imagen
   bool leerImagen(const char file[]);//Carga imagen file en este objeto imagen
   bool escribirImagen(const char file[]) const; //Salva esta imagen en file
};

#endif
