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


string Grammar::search(const char& ch)    // �������һ������ʽ�Ҳ�
{
	srand(time(0));
	int id = find(ch);

	if (id == -1)   // ���ǲ���ʽ
		return "";  //"" + ch ����

	int num = get<1>(generations[id]).size();

	int index = rand() % num; // �������һ������ʽindex

	return get<1>(generations[id])[index];
}


void Grammar::addGeneration(const char& ch, const string& ref)  // ���һ������ʽ
{
	int id = find(ch);

	if (id == -1)    // ���ch�Ƿ��Ѿ�����: ������,�½�һ��
	{
		tuple<char, vector<string> > temp = { ch, {ref} };
		generations.push_back(temp);
		return;
	}
	get<1>(generations[id]).push_back(ref); // ����,ֱ�Ӻ��油��һ��
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
