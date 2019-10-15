#ifndef VARIABLE_H
#define VARIABLE_H
#include <iostream>
#include <string>
#include <vector>
#define TYPE_NUMBER 0 //按Python的数据类型划分
#define TYPE_STR 1
#define TYPE_LIST 2
#define TYPE_FUN 3
#define TYPE_NONE 4
using namespace std;
class variable{
	private:
	int type;
	void* value;
	bool naint;//not a int
	public :
	variable();	
	variable(float);
	variable(string);
	variable(vector<variable>);
	int print(bool b=true);
	~variable();
};
#endif

