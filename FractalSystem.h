// 分形系统类FractalSystem.h
#pragma once
#include "Grammar.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <math.h>
#include <corecrt_math_defines.h>
using namespace glm;

class State      // 当前探索状态
{
public:
	vec2 pos;
	vec2 dir;    // 当前乌龟方向,一个单位向量
	double length; // 当前长度
	int level; 
};

class Trunk     // 枝干
{
public:
	vec2 pos1;
	vec2 pos2;
};

class FractalSystem
{
private:
	double dx, dy, dz;    // 围绕三个坐标轴的偏转角度

	double length;     // 初始步长
	double lengthFactor; // 步长比率
	double radius;   // 初始半径
	double radiusFactor;  // 半径比率

	State curState;  // 当前的位置和旋转信息

	double leafRadius;  // 叶片半径

	Grammar grammar;    // 一个文法分析器

public:

	vector<Trunk> trunks; //  所有分支

	FractalSystem();

	void clearAll();
	void initGrammar();
	void generateFractal();
};

