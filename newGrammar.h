#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <cstdlib>
#include <ctime>
#include "Generations.h"
using namespace std;

class newGrammar {
private:
	string initialGrammar;
	int level;
public:
	vector<Generations> generations;
	void setInitialGrammar(string s);
	void addGeneration();
	void iterateFor(int i);
	int getLevel();
};