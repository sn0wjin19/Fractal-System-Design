#include "newGrammar.h"

void newGrammar::setInitialGrammar(string s) {
	this->initialGrammar = s;
}

void newGrammar::addGeneration() {
	Generations tmp;
	vector<string> tempString;
	if (this->level == 0) {
		tmp.setLevel(0);
		tmp.setGrammar(initialGrammar);
		tempString.push_back("F");
		tmp.setResult(tempString);
		this->generations.push_back(tmp);
	}
	else {
		vector<string> last = generations.back().getResult();
		tmp.setLevel(this->level);
		tmp.setGrammar(initialGrammar);
		for (int x = 0; x < last.size(); x++) {
			for (int j = 0; j < last.at(x).size(); j++) {
				if (last.at(x).at(j) == 'F')
					tempString.push_back(initialGrammar);
			}
		}
	}
	this->level++;
}

void newGrammar::iterateFor(int i) {
	if (i > 1) {
		this->addGeneration();
		for (; i > 0; i--) {
			this->addGeneration();
		}
	}
}

int newGrammar::getLevel() {
	return this->level;
}