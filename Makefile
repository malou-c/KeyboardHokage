.PHONY: all clean install uninstall 

CC = g++
CFLAGS = -c -MP -MMD -Wall -Werror
SRC = src/main.cpp  src/button.cpp src/clockface.cpp src/file.cpp src/filereader.cpp src/MenuButton.cpp src/MyKeyboard.cpp src/screentxt.cpp src/sysbutton.cpp src/word.cpp src/text_dubler.cpp
OBJ_PATH = build/src/
OBJ = $(OBJ_PATH)main.o $(OBJ_PATH)button.o $(OBJ_PATH)clockface.o $(OBJ_PATH)file.o $(OBJ_PATH)filereader.o $(OBJ_PATH)MenuButton.o $(OBJ_PATH)MyKeyboard.o $(OBJ_PATH)screentxt.o $(OBJ_PATH)sysbutton.o $(OBJ_PATH)word.o $(OBJ_PATH)text_dubler.o
EXEC = sp.exe

all: $(SRC) $(EXEC) 

$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $@ -lsfml-graphics -lsfml-window -lsfml-system

build/src/%.o: src/%.cpp	
	$(CC) $(CFLAGS) $< -o $@
	
-include build/src/*.d



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
	rm -rf build/src/*.o build/src/*.d build/test/*.o build/test/*.d