OFILES = button.o clockface.o file.o filereader.o menu.o MenuButton.o MyKeyboard.o screentxt.o sysbutton.o word.o

compileall:$(OFILES)

tie:compileall
	g++  $(OFILES) -o KbHokage -lsfml-graphics -lsfml-window -lsfml-system
launch:tie
	./KbHokage
	
button.o: button.cpp
	g++ -c button.cpp

clockface.o: clockface.cpp
	g++ -c clockface.cpp

file.o: file.cpp
	g++ -c file.cpp

filereader.o: filereader.cpp
	g++ -c filereader.cpp

menu.o: menu.cpp
	g++ -c menu.cpp

MenuButton.o: MenuButton.cpp
	g++ -c MenuButton.cpp

MyKeyboard.o: MyKeyboard.cpp
	g++ -c MyKeyboard.cpp

screentxt.o: screentxt.cpp
	g++ -c screentxt.cpp

sysbutton.o: sysbutton.cpp
	g++ -c sysbutton.cpp

word.o: word.cpp
	g++ -c word.cpp

