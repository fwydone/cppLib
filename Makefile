EXE=thread
SRC=main.cpp
CC=g++ -g 
LIB=-lpthread
$(EXE):$(SRC)
	$(CC) -o $(EXE) $(SRC) $(LIB)
