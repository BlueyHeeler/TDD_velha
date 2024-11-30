#include "velha.hpp"
#include <bits/stdc++.h>
using namespace std;

int VerificaVelha( vector<vector<int>> velha )
{
	int diagonal;
	int coluna;
	int fileira;
	for(int jogador = 1; jogador<=2; jogador++){
		for(int i = 0; i<3; i++){
			for(int j = 0; j<3; j++){
				//Verifica Diagonal
				if(i == j && velha[i][j] == jogador)
					diagonal += 1;
				//Verifica Fileira
				if(velha[i][j] == jogador)
					fileira += 1;
				//Verifica Coluna
				if(velha[j][i] == jogador)
					coluna += 1;
			}
			if(fileira == 3 || coluna == 3)
				return jogador;
			coluna = 0;
			fileira = 0;
		}
	}
	return 0; /*!< retorna zero para teste */
}


