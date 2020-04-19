all:test

test: button.cpp MyKeyboard.cpp
	g++ MyKeyboard.cpp button.cpp sysbutton.cpp -o test.exe -lsfml-graphics -lsfml-window -lsfml-system
	./test.exe