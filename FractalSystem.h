// ����ϵͳ��FractalSystem.h
#pragma once
#include "Grammar.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <math.h>
#include <corecrt_math_defines.h>
using namespace glm;

class State      // ��ǰ̽��״̬
{
public:
	vec2 pos;
	vec2 dir;    // ��ǰ�ڹ귽��,һ����λ����
	double length; // ��ǰ����
	int level; 
};

class Trunk     // ֦��
{
public:
	vec2 pos1;
	vec2 pos2;
};

class FractalSystem
{
private:
	double dx, dy, dz;    // Χ�������������ƫת�Ƕ�

	double length;     // ��ʼ����
	double lengthFactor; // ��������
	double radius;   // ��ʼ�뾶
	double radiusFactor;  // �뾶����

	State curState;  // ��ǰ��λ�ú���ת��Ϣ

	double leafRadius;  // ҶƬ�뾶

	Grammar grammar;    // һ���ķ�������

public:

	vector<Trunk> trunks; //  ���з�֧

	FractalSystem();

	void clearAll();
	void initGrammar();
	void generateFractal();
};

