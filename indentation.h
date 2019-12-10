#include <stack>
#inlcude "statement.h"
class indentation{
	public:
	stack<statement*> stk;
	void addline(statement*);
	void init();
	void prompt();
	void error();
	void merge(statement*);
}
