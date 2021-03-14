CC=g++
CFLAGS=-std=c++11
LDFLAGS=`pkg-config --cflags --libs opencv4`
EXEC=output
SRC=$(wildcard *.cpp)

OBJ=$(SRC:.cpp=.o)

all: $(EXEC)

$(EXEC): $(SRC)
	$(CC) -o $(EXEC) $(SRC) $(CFLAGS) $(LDFLAGS)

clean:
	$(RM) $(OBJ) $(EXEC)

#g++ test.cpp -o exec `pkg-config --cflags --libs opencv`
