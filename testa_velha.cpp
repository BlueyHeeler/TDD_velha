// Copyright 2024 <Erick>
#include "velha.hpp"
#include<bits/stdc++.h>
using namespace std;

#define CATCH_CONFIG_MAIN
#include "catch.hpp"


class Jogo {

private:
	vector<vector<int>> velha;

public:
	Jogo() : velha(3, vector<int>(3, 0)) {}

	Jogo(vector<vector<int>> velha) : velha(velha) {}

	void setJogo(vector<vector<int>> velha) {
		this->velha = velha;
	}

	vector<vector<int>> getJogo() const {
		return velha;
	}
};

TEST_CASE("Testa velha", "[single-file]" ) {
	Jogo teste1({
	{ 2, 0, 1 },
	{ 2, 0, 1 },
	{ 0, 2, 1 }
	});
	REQUIRE(VerificaVelha(teste1.getJogo()) == 1 );

	Jogo teste2({
	{2, 2, 2},
	{0, 1, 1},
	{0, 0, 0}
	});
	REQUIRE(VerificaVelha(teste2.getJogo()) == 2);

	Jogo teste3({
	{1, 0, 2},
	{0, 1, 2},
	{2, 0, 1}
	});
	REQUIRE(VerificaVelha(teste3.getJogo()) == 1);

	Jogo teste4({
	{0, 2, 1},
	{2, 1, 2},
	{1, 0, 0}
	});
	REQUIRE(VerificaVelha(teste4.getJogo()) == 1);

	Jogo teste5({
	{2, 1, 1},
	{2, 0, 1},
	{2, 0, 0}
	});
	REQUIRE(VerificaVelha(teste5.getJogo()) == 2);

	Jogo teste6({
	{2, 1, 2},
	{1, 2, 1},
	{2, 0, 0}
	});
	REQUIRE(VerificaVelha(teste6.getJogo()) == 2);

	Jogo teste7({
	{2, 1, 2},
	{1, 1, 2},
	{1, 2, 1}
	});
	REQUIRE(VerificaVelha(teste7.getJogo()) == 0);

	Jogo teste8({
	{1, 0, 0},
	{0, 0, 0},
	{0, 0, 0}
	});
	REQUIRE(VerificaVelha(teste8.getJogo()) == -1);

	Jogo teste9({
	{1, 1, 1},
	{2, 0, 0},
	{0, 0, 0}
	});
	REQUIRE(VerificaVelha(teste9.getJogo()) == -2);

}
