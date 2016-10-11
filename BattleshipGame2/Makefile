all: battleship

CXXFLAGS=-g -Wall

Ship.o: Ship.cpp Ship.h 
Board.o: Board.cpp Board.h
battleship.o: battleship.cpp Board.h Ship.h 

battleship: battleship.o  Ship.o Board.o
	$(CXX) -o $@ $^  $(LDFLAGS)

clean:
	rm -f *.o battleship