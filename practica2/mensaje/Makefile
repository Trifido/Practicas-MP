#Nombre del archivo : makefile.
# Uso: make
# Descripcion : Mantiene todas las dependencias entre los modulos y las bibliotecas que utiliza el #	programa central


HOMEDIR = .
BIN = $(HOMEDIR)/bin
OBJ = $(HOMEDIR)/obj
INCLUDE = $(HOMEDIR)/include
LIB = $(HOMEDIR)/lib
SRC = $(HOMEDIR)/src

all:$(BIN)/ocultar $(BIN)/revelar 

CXX = g++
CPPFLAGS = -Wall -g -c

# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile

# ************ Compilación de módulos ************
$(BIN)/ocultar : $(OBJ)/ocultar.o $(LIB)/libformas.a
	g++ -o $(BIN)/ocultar $(OBJ)/ocultar.o -L$(LIB)/ -lformas

$(BIN)/revelar : $(OBJ)/revelar.o $(LIB)/libformas.a
	g++ -o $(BIN)/revelar $(OBJ)/revelar.o -L$(LIB)/ -lformas

$(LIB)/libformas.a : $(OBJ)/imagenES.o $(OBJ)/codificar.o
	ar rvs $(LIB)/libformas.a $(OBJ)/imagenES.o $(OBJ)/codificar.o 

$(OBJ)/imagenES.o : $(SRC)/imagenES.cpp $(INCLUDE)/imagenES.h
	$(CXX) $(CPPFLAGS) $(SRC)/imagenES.cpp -o $(OBJ)/imagenES.o -I$(INCLUDE)/

$(OBJ)/codificar.o : $(SRC)/codificar.cpp $(INCLUDE)/codificar.h $(INCLUDE)/imagenES.h
	$(CXX) $(CPPFLAGS) $(SRC)/codificar.cpp -o $(OBJ)/codificar.o -I$(INCLUDE)/

$(OBJ)/ocultar.o : $(SRC)/ocultar.cpp $(INCLUDE)/codificar.h $(INCLUDE)/imagenES.h
	$(CXX) $(CPPFLAGS) $(SRC)/ocultar.cpp -o $(OBJ)/ocultar.o -I$(INCLUDE)/

$(OBJ)/revelar.o : $(SRC)/revelar.cpp $(INCLUDE)/codificar.h $(INCLUDE)/imagenES.h
	$(CXX) $(CPPFLAGS) $(SRC)/revelar.cpp -o $(OBJ)/revelar.o -I$(INCLUDE)/

# ************ Limpieza ************
clean :
	-rm $(LIB)/* $(OBJ)/* $(SRC)/*~ $(INCLUDE)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*

