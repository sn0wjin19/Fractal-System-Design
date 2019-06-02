// FractalSystem.cpp
#include "Fractalsystem.h"

FractalSystem::FractalSystem()
{
}


void FractalSystem::clearAll()
{
	grammar.clear();
	trunks.clear();
}

void FractalSystem::initGrammar()   // 加载一个文法
{
	srand(time(NULL));
	grammar.setGrammarName("Test1");

	    // 2维
	    grammar.setStart("F");
		//grammar.addGeneration('F', "F*F//F*F");
	    //grammar.addGeneration('F',"F[*F]F[/F]F");
	    /*grammar.addGeneration('F',"F[*F]F[/F[*F]]");
	    grammar.addGeneration('F',"FF*[*F*F]/[*F]");*/
		grammar.addGeneration('F', "F");
		grammar.addGeneration('F', "F[*F]F[/F]F");
	    grammar.iterateFor(6);
}

void FractalSystem::generateFractal()   // 利用加载过的文法，创建分形树
{
	trunks.clear();
	length = 100;
	// 乌龟初始状态: 坐标(0,0,0),方向y轴正方向
	curState.pos = vec2(0, -1);
	curState.dir = vec2(0, 1);
	curState.length = length / grammar.getLevel();
	curState.level = 1;
	lengthFactor = 0.75;
	int angle = 25;

	glm::mat4 Model;
	glm::vec4 a, b;
	vector<State> stacks; // 状态栈
	stacks.push_back(curState);
	float val = M_PI / 180;
	for (int i = 0; i < grammar.getResult().size(); i++)
	{
		char ch = grammar.getResult().at(i);  // 当前字符

		Trunk tmp; // 临时树干
		
		switch (ch)
		{
		case 'F':
			// 画一条直线
			tmp.pos1 = curState.pos;

			//修改curState的pos;
			curState.pos.x += curState.length * curState.dir.x;
			curState.pos.y += curState.length * curState.dir.y;
			tmp.pos2 = curState.pos;

			trunks.push_back(tmp);
			break;
		case '*':
			glm::mat2 rotate1 = glm::mat2(cos(val * (360-angle)), -sin(val * (360-angle)), sin(val * (360-angle)), cos(val * (360-angle)));
			curState.dir = rotate1 * curState.dir;
			break;
		case '/':
			glm::mat2 rotate2 = glm::mat2(cos(val * angle), -sin(val * angle), sin(val * angle), cos(val * angle));
			curState.dir = rotate2 * curState.dir;
			break;
		case '[':
			// 将curState进一次栈
			stacks.push_back(curState);
			curState.length *= lengthFactor;
			curState.level += 1;
			break;
		case ']':
			// 将curState取栈顶,出栈
			curState = stacks.at(stacks.size() - 1);
			stacks.pop_back();
			break;
		default:
			break;
		}
	}
}
