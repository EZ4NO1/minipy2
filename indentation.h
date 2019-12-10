#include <stack>
#include "statement.h"
class indentation{
	public:
	stack<statement*> stk;
	indentation();
	void addline(statement*);
	void init();
	void prompt();
	void error();
	void merge(statement*);
};
