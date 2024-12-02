#include "velha.hpp"
#include <bits/stdc++.h>
using namespace std;

int VerificaDiagonal(int row, int column,
					 vector<vector<int>> velha, int jogador) {
	return (row == column && velha[row][column] == jogador);
}

int VerificaDiagonalSec(int row, int column,
							   vector<vector<int>> velha, int jogador) {
	return (row + column == 2) && velha[row][column] == jogador;
}

int VerificaFileira(int row, int column,
					vector<vector<int>> velha, int jogador) {
	return velha[row][column] == jogador;
}

int VerificaColuna(int column, int row,
				   vector<vector<int>> velha, int jogador) {
	return velha[column][row] == jogador;
}

int Vitoria(int coluna, int fileira, int diagonal1, int diagonal2) {
	if(coluna == 3 || fileira == 3 || diagonal1 == 3 || diagonal2 == 3)
		return 1;
	return 0;
}

int JogoInvalido(int contJogador1, int contJogador2) {
	return abs(contJogador1 - contJogador2) >= 2;
}

int JogoIndefinido(int contJogador1, int contJogador2) {
	return contJogador1 + contJogador2 <= 8;
}

void ContadorDeJogadores(const vector<vector<int>> velha,
						int &contJogador1, int &contJogador2) {
	for (vector<int> rowVelha: velha) {
		for (int tipoJogado: rowVelha) {

			if(tipoJogado == 1)
				contJogador1 += 1;
			if(tipoJogado == 2)
				contJogador2 += 1;
		}
	}
}

int VerificaVelha(const vector<vector<int>> velha) {
	int diagonal1 = 0;
	int diagonal2 = 0;
	int coluna = 0;
	int fileira = 0;
	int contJogador1 = 0;
	int contJogador2 = 0;
	bool jogador1_ganhou = false;
	bool jogador2_ganhou = false;

	ContadorDeJogadores(velha, contJogador1, contJogador2);
	if(JogoInvalido(contJogador1, contJogador2))
		return -2;
	contJogador1 = 0;
	contJogador2 = 0;

	for (int jogador = 1; jogador <= 2; jogador++) {
		for (int row = 0; row < 3; row++) {
			for (int column = 0; column < 3; column++) {
				if (VerificaDiagonal(row, column, velha, jogador))
					diagonal1++;

				if (VerificaDiagonalSec(row, column, velha, jogador))
					diagonal2++;

				if (VerificaFileira(row, column, velha, jogador))
					fileira++;

				if (VerificaColuna(column, row, velha, jogador))
					coluna++;
			}

			if (Vitoria(coluna, fileira, diagonal1, diagonal2))
				return jogador;

			coluna = 0;
			fileira = 0;
		}

		if (Vitoria(coluna, fileira, diagonal1, diagonal2))
			return jogador;

		diagonal1 = 0;
		diagonal2 = 0;
	}

	ContadorDeJogadores(velha, contJogador1, contJogador2);

	if(JogoIndefinido(contJogador1, contJogador2))

	if((contJogador1 + contJogador2) <= 8)
		return -1;

	return 0;
}



