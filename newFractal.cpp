#include "newFractal.h"

void newFractal::Init(string IGrammar) {
	this->grammar.setInitialGrammar(IGrammar);
	length = 100;
	x = 0;
	y = 0;
}

void newFractal::Test() {
	curState.pos = vec2(0, 0);
	curState.dir = vec2(0, 1);
	curState.curLength = length;
	vector<Trunk> tmpTrunks = trunks;
	grammar.iterateFor(1);
	vector<string> temp = grammar.generations.back().getResult;
	int i = grammar.getLevel;

	for (; i > 0; i--) {
		while (temp.size() > 0) {
			string s = temp.back();
			Trunk tmp = trunks.at(temp.size() - 1);
			char ch;
			for (int g = 0; g < s.size(); g++) {
				ch = s.at(g);
				switch (ch) {
				case 'F':
					trunks.push_back(tmp); 
				}
			}
		}
		length /= 2;
	}
}