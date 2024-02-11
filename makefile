CC := g++
CFLAGS := -g -Wall

INCLUDE := ./include
SRC := ./src
BIN := ./bin

compile: *.o
	$(CC) $^ -o a.out
	mv *.o $(BIN)

%.o: $(SRC)/%.cpp
	$(CC) $(CFLAGS) -I$(INCLUDE) -c $^

run: compile
	./a.out


.PHONY: clean

clean:
	-rm *.out
	-rm $(BIN)/*.o
