all: main

main: filereader.cpp screentxt.cpp
	g++ -std=c++1z filereader.cpp screentxt.cpp word.cpp MyKeyboard.cpp sysbutton.cpp button.cpp -lstdc++fs -o sp.exe  -lsfml-graphics -lsfml-window -lsfml-system
	./sp.exe