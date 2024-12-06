# Definindo o compilador e as flags
CC = g++
CXXFLAGS = -std=c++11 -Wall
OBJ_DIR = coverage

# Alvo default
all: testa_velha

# Compilar e rodar o programa
testa_velha: velha.o testa_velha.cpp velha.hpp
	$(CC) $(CXXFLAGS) velha.o testa_velha.cpp -o testa_velha
	./testa_velha

# Gerar o objeto da velha
velha.o: velha.cpp velha.hpp
	$(CC) $(CXXFLAGS) -c velha.cpp

# Rodar os testes
test: testa_velha
	./testa_velha

# Verificar o código com cpplint
cpplint: testa_velha.cpp velha.cpp velha.hpp
	cpplint --filter=-whitespace/tab testa_velha.cpp velha.cpp

# Cobertura de código com gcov
gcov: velha.cpp testa_velha.cpp velha.hpp
	mkdir -p $(OBJ_DIR)
	$(CC) $(CXXFLAGS) -fprofile-arcs -ftest-coverage -o $(OBJ_DIR)/velha.o -c velha.cpp
	$(CC) $(CXXFLAGS) -fprofile-arcs -ftest-coverage -o $(OBJ_DIR)/testa_velha $(OBJ_DIR)/velha.o testa_velha.cpp
	./$(OBJ_DIR)/testa_velha
	gcov -o $(OBJ_DIR) *.cpp

# Depuração com gdb
debug: testa_velha.cpp velha.cpp velha.hpp
	$(CC) $(CXXFLAGS) -g -c velha.cpp
	$(CC) $(CXXFLAGS) -g velha.o testa_velha.cpp -o testa_velha
	gdb testa_velha

# Verificar com cppcheck
cppcheck: testa_velha.cpp velha.cpp velha.hpp
	cppcheck --enable=warning .

# Verificar com Valgrind
valgrind: testa_velha
	valgrind --leak-check=yes --log-file=valgrind.rpt ./testa_velha

# Limpar arquivos temporários
clean:
	@if [ "$(OS)" = "Windows_NT" ]; then \
		del /f /q *.o *.exe *.gc* 2>nul || exit 0; \
	else \
		rm -f *.o *.exe *.gc*; \
	fi

	
	
