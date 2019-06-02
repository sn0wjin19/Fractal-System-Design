// Grammar.h �ķ���������ͷ�ļ�
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <cstdlib>
#include <ctime>

using namespace std;
class Grammar
{
private:
	string Gname;  // �ķ���

	int level;        // �������
	string start;    // �ķ���ʼ��   ���������ķ�
	string result;   // �洢����level�κ�Ľ��

	vector<tuple<char, vector<string> > > generations;  // ���в���ʽ��ʹ��STL�µ�Tupleģ��
	// char -> һ����������  ÿ������������(search)
public:

	Grammar() {}

	void clear();   // �����������

	int find(char ch);  // ����ch��generations�����
	string search(const char& ch);  // ch��Ӧ������ʽ�����ڣ�����ch, ch��Ӧ����ʽ���ڣ��������

	void addGeneration(const char& ch, const string& ref); // ���һ������ʽ
	void iterateFor(int num);  // setlevel(num),����num�Σ� ��start��ʼ,�����ĸ����(search) ,���������result

	void setGrammarName(const string& ref);
	void setStart(const string& ref);
	void setLevel(int num);

	string getGrammarName();
	int getLevel();
	string getResult();

};
