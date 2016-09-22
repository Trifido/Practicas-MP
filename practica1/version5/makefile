HOMEDIR = .
BIN = $(HOMEDIR)/bin
OBJ = $(HOMEDIR)/obj
LIB = $(HOMEDIR)/lib
INC = $(HOMEDIR)/include
SRC = $(HOMEDIR)/src

all: $(BIN)/central

$(OBJ)/central.o : $(SRC)/central.cpp $(INC)/punto.h $(INC)/circulo.h
	g++ -c $(SRC)/central.cpp -o $(OBJ)/central.o -I$(INC)/

$(OBJ)/punto.o : $(SRC)/punto.cpp $(INC)/punto.h
	g++ -c $(SRC)/punto.cpp -o $(OBJ)/punto.o -I$(INC)/

$(OBJ)/circulo.o : $(SRC)/circulo.cpp $(INC)/punto.h $(INC)/circulo.h
	g++ -c $(SRC)/circulo.cpp -o $(OBJ)/circulo.o -I$(INC)/

$(LIB)/libformas.a : $(OBJ)/punto.o $(OBJ)/circulo.o
	ar rvs $(LIB)/libformas.a $(OBJ)/punto.o $(OBJ)/circulo.o

$(BIN)/central : $(OBJ)/central.o $(LIB)/libformas.a
	g++ -o $(BIN)/central $(OBJ)/central.o -L$(LIB)/ -lformas

clean : 
	echo "Limpiando..."
	rm $(OBJ)/*.o $(LIB)/lib*.a

mrproper: clean
	rm bin/central


