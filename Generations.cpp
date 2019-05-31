#include "Generations.h"

int Generations::getLevel() {
	return this->atLevel;
}

string Generations::getGrammar() {
	return this->grammar;
}

vector<string> Generations::getResult() {
	return this->result;
}

void Generations::setLevel(int i) {
	this->atLevel = i;
}

void Generations::setGrammar(string gr) {
	this->grammar = gr;
}

void Generations::setResult(vector<string> re) {
	this->result = re;
}