all: main

main: filereader.cpp screentxt.cpp
	g++ -std=c++1z filereader.cpp screentxt.cpp word.cpp -lstdc++fs -o sp.exe  -lsfml-graphics -lsfml-window -lsfml-system
	./sp.exe