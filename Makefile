CC=g++
CLIB=. lib src
HEADERS=. ./include/
CFLAG=-std=c++2a -Wall -Wextra -pedantic -O3 -g $(foreach D,$(HEADERS), -I$(D))

CFILES=$(foreach D,$(CLIB),$(wildcard $(D)/*.cpp))
OBJECT=$(patsubst %.cpp,%.o,$(CFILES))
BIN=$(foreach D,build,$(D)/main)

all: $(BIN)

$(BIN): $(OBJECT)
	$(CC) $(^) -o $(@)

%.o: %.cpp
	$(CC)  $(CFLAG) -c $(^) -o $(@)

.PHONY: run
run:
	./$(BIN)

.PHONY: clean
clean:
	rm $(OBJECT) $(BIN)
