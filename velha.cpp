#include "velha.hpp"
#include <bits/stdc++.h>
using namespace std;

int VerificaDiagonal(int row, int column,
					 vector<vector<int>> velha, int jogador) {
	return (row == column && velha[row][column] == jogador);
}

int VerificaFileira(int row, int column,
					vector<vector<int>> velha, int jogador) {
	return velha[row][column] == jogador;
}

int VerificaColuna(int column, int row,
				   vector<vector<int>> velha, int jogador) {
	return velha[column][row] == jogador;
}

int VerificaVelha(vector<vector<int>> velha) {
	int diagonal = 0;
	int coluna = 0;
	int fileira = 0;

	for (int jogador = 1; jogador <= 2; jogador++) {
		for (int row = 0; row < 3; row++) {
			for (int column = 0; column < 3; column++) {
				if (VerificaDiagonal(row, column, velha, jogador))
					diagonal++;

				if (VerificaFileira(row, column, velha, jogador))
					fileira++;

				if (VerificaColuna(column, row, velha, jogador))
					coluna++;
			}

			if (fileira == 3 || coluna == 3)
				return jogador;

			coluna = 0;
			fileira = 0;
		}

		if (diagonal == 3)
			return jogador;

		diagonal = 0;
	}

	return 0;
}



