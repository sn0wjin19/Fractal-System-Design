// Grammar.cpp

#include "Grammar.h"

void Grammar::clear()
{
	generations.clear();
}

int Grammar::find(char ch)
{
	for (int i = 0; i < generations.size(); i++)
	{
		if (get<0>(generations[i]) == ch)
			return i;   // Find it!
	}
	return -1;   // Can't Find, return -1
}


string Grammar::search(const char& ch)    // 随机返回一个产生式右部
{
	srand(time(0));
	int id = find(ch);

	if (id == -1)   // 不是产生式
		return "";  //"" + ch 出错

	int num = get<1>(generations[id]).size();

	int index = rand() % num; // 随机生成一个产生式index

	return get<1>(generations[id])[index];
}


void Grammar::addGeneration(const char& ch, const string& ref)  // 添加一个产生式
{
	int id = find(ch);

	if (id == -1)    // 检查ch是否已经存在: 不存在,新建一个
	{
		tuple<char, vector<string> > temp = { ch, {ref} };
		generations.push_back(temp);
		return;
	}
	get<1>(generations[id]).push_back(ref); // 存在,直接后面补上一个
}

void Grammar::iterateFor(int num)
{
	setLevel(num);

	result = start;
	for (int i = 0; i < num; i++)
	{
		string tmp = "";
		for (int i = 0; i < result.size(); i++)
		{
			string a = search(result.at(i));
			if (a == "")
				a = result.at(i);
			tmp += a;
		}
		result = tmp;
	}
}

void Grammar::setGrammarName(const string& ref)
{
	Gname = ref;
}

void Grammar::setStart(const string& ref)
{
	start = ref;
}

void Grammar::setLevel(int num)
{
	level = num;
}

string Grammar::getGrammarName()
{
	return Gname;
}

int Grammar::getLevel()
{
	return level;
}

string Grammar::getResult()
{
	return result;
}
