CC := g++
CFLAGS := -g -Wall

INCLUDE := ./include
SRC := ./src
BIN := ./bin

compile: $(BIN)/*.o
	$(CC) $^ -o a.out

$(BIN)/%.o: $(SRC)/%.cpp
	$(CC) $(CFLAGS) -I$(INCLUDE) -c -o $@ $<

run: compile
	./a.out


.PHONY: clean

clean:
	-rm *.out
	-rm $(BIN)/*.o
