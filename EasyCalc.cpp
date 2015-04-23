// EasyCalc.cpp : 定义控制台应用程序的入口点。
//

///
///此简易计算器的编写参考c++ primer ch14.8.3 中可调用对象的内容，可调用对象由 函数（add） 标准函数库（minus） lambda 表达式（*） 
/// 重载的调用运算符（） （/）
///
#include "stdafx.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <functional>
#include <map>

using namespace std;

int add(int l, int r)
{
	return l + r;
}

//template<typename T>
//T minus(T l, T r)
//{
//	return l - r;
//}

struct Divide
{
	int operator()(int denominator, int divisor)
	{
		return denominator / divisor;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{

#pragma region 将输入的字符串转换为运算表达式
	string s;
	function<int(int, int)> f1 = add;
	function<int(int, int)> f2 = std::minus<int>();
	function<int(int, int)> f3 = [](int i, int j){return i*j; };
	function<int(int, int)> f4 = Divide();
	map<char, function<int(int, int)>> binops = { { '+', f1 }, { '-', f2 }, { '*', f3 }, { '/', f4 } };
	while (true)
	{
		getline(cin, s);
		int len = s.length();
		int indexOperator = 0;
		for (size_t i = 0; i < len; i++)
		{
			if (!isdigit(s[i]))
			{
				indexOperator = i;
				break;
			}

		}
		string	subStrL = s.substr(0, indexOperator);
		string subStrR = s.substr(indexOperator + 1);
		int lhs = atoi(subStrL.c_str());
		int rhs = atoi(subStrR.c_str());
		char operation = s[indexOperator];
		cout << s << "= " << binops[operation](lhs, rhs) << endl;
	}
	

#pragma endregion

	
	
	


	return 0;
}

