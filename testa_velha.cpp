// Copyright 2024 <Erick>
#include "velha.hpp"
#include<bits/stdc++.h>
using namespace std;

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

TEST_CASE( "Testa velha", "[single-file]" ) {
	vector< vector<int> > teste1= {
	{ 2, 0, 1 },
	{ 2, 0, 1 },
	{ 0, 2, 1 }
	};
	REQUIRE( VerificaVelha(teste1) == 1 );
}
