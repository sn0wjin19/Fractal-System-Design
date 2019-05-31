#pragma once
#include <iostream>
#include <vector>
#include <tuple>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;
class Generations{
private:
	int atLevel;
	string grammar;
	vector<string> result;

public:
	int getLevel();
	string getGrammar();
	vector<string> getResult();
	void setLevel(int i);
	void setGrammar(string gr);
	void setResult(vector<string> re);
};

