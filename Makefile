.PHONY: all clean install uninstall 

CC = g++ -std=c++11
CFLAGS = -Wall -Werror -Wextra -MP -MMD -c
SFMLFLAGS = -lsfml-graphics -lsfml-window -lsfml-system
PROG = kbh.exe
DIR = build
DIR2 = bin
FILESCPP = $(wildcard src/*.cpp)
OBJECTS = $(subst .cpp,.o,$(FILESCPP))

all: $(FILESCPP) $(PROG)


run:
	export LD_LIBRARY_PATH=lib && ./bin/kbh.exe

$(PROG): $(subst src/,build/,$(OBJECTS))
	$(CC) $(subst src/,build/,$^) -o bin/$@ -Llib $(SFMLFLAGS)

build/%.o: src/%.cpp
	$(CC) $(CFLAGS) $< -Isrc/include -o $@

-include build/*.d

#tests
T_EXEC = test.exe
#меняет мейн на тестовый мейн
T_SRC = $(SRC:src/main.cpp=test/main.cpp)
TEST_SRC = test/filereader_test.cpp
TO_PATH = build/test/
T_OBJ = $(TO_PATH)main.o $(TO_PATH)filereader_test.o 

test: $(T_SRC) $(TEST_SRC) $(T_EXEC)

$(T_EXEC): $(T_OBJ) $(OBJ)
	$(CC) $(T_OBJ) $(OBJ:build/src/main.o=) -o $@ -lsfml-graphics -lsfml-window -lsfml-system
	

build/test/%.o: test/%.cpp	
	$(CC) $(CFLAGS) $< -o $@

-include build/test/*.d

clean:  
	rm -rf build/*.o build/*.d