
SRC = src
INC = include
OBJ = obj
BIN = bin
LIB = lib

CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -c

all : $(BIN)/negativo $(BIN)/desplazar

# ************ Generacion de documentacion ******************
documentacion:
	doxygen doc/doxys/Doxyfile

# ************ Compilacion de modulos ************

$(BIN)/negativo : $(OBJ)/negativo.o $(LIB)/libimagen.a
	g++ -o $(BIN)/negativo $(OBJ)/negativo.o -L$(LIB) -limagen

$(BIN)/desplazar : $(OBJ)/desplazar.o $(LIB)/libimagen.a
	g++ -o $(BIN)/desplazar $(OBJ)/desplazar.o -L$(LIB) -limagen

$(LIB)/libimagen.a : $(OBJ)/imagenES.o $(OBJ)/transformar.o $(OBJ)/imagen.o
	ar rvs $(LIB)/libimagen.a $(OBJ)/imagenES.o $(OBJ)/imagen.o $(OBJ)/transformar.o

$(OBJ)/transformar.o : $(SRC)/transformar.cpp $(INC)/transformar.h
	$(CXX) $(CPPFLAGS) $(SRC)/transformar.cpp -o $(OBJ)/transformar.o

$(OBJ)/negativo.o : $(SRC)/negativo.cpp
	$(CXX) $(CPPFLAGS) $(SRC)/negativo.cpp -o $(OBJ)/negativo.o

$(OBJ)/desplazar.o : $(SRC)/desplazar.cpp
	$(CXX) $(CPPFLAGS) $(SRC)/desplazar.cpp -o $(OBJ)/desplazar.o

$(OBJ)/imagenES.o : $(SRC)/imagenES.cpp $(INC)/imagenES.h
	$(CXX) $(CPPFLAGS) $(SRC)/imagenES.cpp -o $(OBJ)/imagenES.o

$(OBJ)/imagen.o: $(SRC)/imagen.cpp $(SRC)/imagen1.cpp $(SRC)/imagen2.cpp $(SRC)/imagen3.cpp $(SRC)/imagen4.cpp $(INC)/imagen.h $(INC)/imagenES.h $(INC)/imagen1.h $(INC)/imagen2.h $(INC)/imagen3.h $(INC)/imagen4.h   
	$(CXX) $(CPPFLAGS) $(SRC)/imagen.cpp -o $(OBJ)/imagen.o
	
# ************ Limpieza ************
clean :
	-rm $(OBJ)/* ./$(LIB)/* ./$(INC)/*~ ./$(SRC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/*

