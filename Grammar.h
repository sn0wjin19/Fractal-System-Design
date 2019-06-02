// Grammar.h 文法分析器类头文件
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
	string Gname;  // 文法名

	int level;        // 迭代层次
	string start;    // 文法开始符   待迭代的文法
	string result;   // 存储迭代level次后的结果

	vector<tuple<char, vector<string> > > generations;  // 所有产生式，使用STL下的Tuple模板
	// char -> 一个或多个规则  每个规则概率输出(search)
public:

	Grammar() {}

	void clear();   // 清除所有数据

	int find(char ch);  // 查找ch在generations的序号
	string search(const char& ch);  // ch对应的生成式不存在，返回ch, ch对应生成式存在，随机返回

	void addGeneration(const char& ch, const string& ref); // 添加一个产生式
	void iterateFor(int num);  // setlevel(num),迭代num次， 从start开始,逐个字母迭代(search) ,结果保存在result

	void setGrammarName(const string& ref);
	void setStart(const string& ref);
	void setLevel(int num);

	string getGrammarName();
	int getLevel();
	string getResult();

};
