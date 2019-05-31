#pragma once
#include "Generations.h"
#include "newGrammar.h"
#include <corecrt_math_defines.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <math.h>
using namespace glm;

class State {
	vec2 pos;
	vec2 dir;    // ��ǰ�ڹ귽��,һ����λ����
	double curLength; // ��ǰ����
};

class Trunk {
public:
	vec2 begin;
	vec2 end;
};

class newFractal {
public:
	double x, y;
	double length;
	State curState;
	vector<Trunk> trunks;
	newGrammar grammar;

	void Init(string IGrammar);
	void Test();
};