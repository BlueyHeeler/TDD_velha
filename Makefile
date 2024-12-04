all: testa_velha.cpp   velha.cpp velha.hpp velha.o
	g++ -std=c++11 -Wall velha.o testa_velha.cpp -o testa_velha
	./testa_velha
	#use comentario se necessario

compile: testa_velha.cpp   velha.cpp velha.hpp velha.o
	g++ -std=c++11 -Wall velha.o testa_velha.cpp -o testa_velha

velha.o : velha.cpp velha.hpp
	g++ -std=c++11 -Wall -c velha.cpp
	
testa_velha: 	testa_velha.cpp   velha.cpp velha.hpp velha.o
	g++ -std=c++11 -Wall velha.o testa_velha.cpp -o testa_velha
	
test: testa_velha	
	./testa_velha
	
cpplint: testa_velha.cpp   velha.cpp velha.hpp
	cpplint --filter=-whitespace/tab testa_velha.cpp velha.cpp

	
gcov: testa_velha.cpp   velha.cpp velha.hpp
	mkdir coverage
	g++ -std=c++11 -Wall -fprofile-arcs -ftest-coverage -o coverage/velha.o -c velha.cpp
	g++ -std=c++11 -Wall -fprofile-arcs -ftest-coverage -o coverage/testa_velha coverage/velha.o testa_velha.cpp
	./coverage/testa_velha
	gcov -o coverage/ *.cpp

	 
debug: testa_velha.cpp   velha.cpp velha.hpp 
	g++ -std=c++11 -Wall -g -c velha.cpp
	g++ -std=c++11 -Wall  -g velha.o testa_velha.cpp -o testa_velha
	gdb testa_velha
	
	
cppcheck: testa_velha.cpp   velha.cpp velha.hpp
	cppcheck  --enable=warning .

valgrind: testa_velha
	valgrind --leak-check=yes --log-file=valgrind.rpt testa_velha


clean:
	del /f /q *.o *.exe *.gc* 2>nul || exit 0

	
	
