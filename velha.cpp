// Copyright 2024 <Erick>
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

int JogoInvalidoPorQuantDeMov(int &contJogador1, int &contJogador2) {
	return abs(contJogador1 - contJogador2) >= 2;
}

int JogoInvalidoAmbosVenc(int vitoriaJogador1, int vitoriaJogador2){
	return (vitoriaJogador1 && vitoriaJogador2);
}

int JogoIndefinido(int contJogador1, int contJogador2) {
	return contJogador1 + contJogador2 <= 8;
}

int Empate(int contJogador1, int contJogador2, int vitoriaJogador1, int vitoriaJogador2){
	return (contJogador1 + contJogador2 == 9) && !(vitoriaJogador1 || vitoriaJogador2);
}

void ContadorDeJogadas(const vector<vector<int>> velha,
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

void VerificaVencedor(vector<vector<int>> velha, int &diagonal1,
					  int &diagonal2, int &fileira, int &coluna,
					  int &vitoriaJogador1, int &vitoriaJogador2) {
	for(int jogador = 1; jogador <= 2; jogador++){
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

			if (Vitoria(coluna, fileira, diagonal1, diagonal2)){
				if(jogador == 1) vitoriaJogador1 = 1;
				else vitoriaJogador2 = 1;
			}

			coluna = 0;
			fileira = 0;
		}
		diagonal1 = 0;
		diagonal2 = 0;
	}
}

int VerificaVelha(const vector<vector<int>> velha) {
	int diagonal1 = 0;
	int diagonal2 = 0;
	int coluna = 0;
	int fileira = 0;
	int contJogador1 = 0;
	int contJogador2 = 0;
	int vitoriaJogador1 = 0;
	int vitoriaJogador2 = 0;

	ContadorDeJogadas(velha, contJogador1, contJogador2);

	if(JogoInvalidoPorQuantDeMov(contJogador1, contJogador2))
		return -2;

	VerificaVencedor(velha, diagonal1, diagonal2, fileira,
						coluna, vitoriaJogador1, vitoriaJogador2);

	if (JogoInvalidoAmbosVenc(vitoriaJogador1, vitoriaJogador2))
		return -2;
	else if (vitoriaJogador1)
		return 1;
	else if (vitoriaJogador2)
		return 2;

	if (JogoIndefinido(contJogador1, contJogador2))
		return -1;

	if (Empate(contJogador1, contJogador2, vitoriaJogador1, vitoriaJogador2))
		return 0;

	return -99;
}



