#include "variable.h"
int main() {
	variable a(1.0);
	variable b((float)(2.2));
	variable c("string");
	variable v[3] = { a, b, c };
	variable l(v, 3);
	a.print();
	b.print();
	c.print();
	l.print();
	/*variable v2[4] = { a, b, c ,l};
	variable l2(v2,4);
	l2.print();
	varmap vm;
	vm.insert("a", 1.0);
	vm.insert("b", 2.2);
	vm.insert("c", "string");
	vm.print("a");
	*/
	//while (1);
	//v[0]=*pl;
	//v[1]=*pln;
	//v[2]=*pc;
	//variable *pll=new variable(v);
	//pll->print();
	//pln->print();
	//variable *pn=new variable();
	//pn->print();
	//return 0;

}
