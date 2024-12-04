#include<bits/stdc++.h>
using namespace std;
int VerificaVelha( vector<vector<int>> velha );

void VerificaVencedor(vector<vector<int>> velha, int &diagonal1,
                      int &diagonal2, int &fileira, int &coluna,
                      int &vitoriaJogador1, int &vitoriaJogador2);

void ContadorDeJogadas(const vector<vector<int>> velha,
                       int &contJogador1, int &contJogador2);

int Empate(int contJogador1, int contJogador2, int vitoriaJogador1, int vitoriaJogador2);

int JogoIndefinido(int contJogador1, int contJogador2);

int JogoInvalidoAmbosVenc(int vitoriaJogador1, int vitoriaJogador2);

int JogoInvalidoPorQuantDeMov(int &contJogador1, int &contJogador2);

int Vitoria(int coluna, int fileira, int diagonal1, int diagonal2);
 
int VerificaColuna(int column, int row,
                   vector<vector<int>> velha, int jogador);

int VerificaFileira(int row, int column,
                    vector<vector<int>> velha, int jogador);

int VerificaDiagonalSec(int row, int column,
                        vector<vector<int>> velha, int jogador);

int VerificaDiagonal(int row, int column,
                     vector<vector<int>> velha, int jogador);
