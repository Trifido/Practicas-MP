
class Signal {
   private :
// Implementación. Tener en cuenta que el tipo de cada elemento es double ....
   public:
      int Filas () const; // Devuelve el número de filas de m
      int Columnas () const; // Devuelve el número de columnas de m
      void Set (int f, int c, double v); // Hace m[i][j]=v
      double Get (int f, int c) const ; // Devuelve m[i][j]
      bool LeerSignal(const char file[]); // Carga una señal de disco
      bool EscribirSignal(const char file[]) const; //Salva una señal en disco
// otros métodos...
};

