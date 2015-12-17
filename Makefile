CC=g++
FLAGS=-std=c++11

.DEFAULT_GOAL := clean_build

clean_build: clean build
clean:
	@rm -f src/*.o bin/poly
build: src/polynomial.o src/split.o
	@$(CC) $(FLAGS) -o bin/poly src/polynomial.o src/split.o src/main.cpp
%.o: %.cpp
	@$(CC) $(FLAGS) -c -o $@ $<
