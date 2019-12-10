#include "statement.h"
statement::statement(int op , int srcnum , statement** src){
	this->op = op;
	this->srcnum = srcnum;
	this->src = src;
}
statement::statement(variable* p){
	this->op = S_TYPE_ASVAR;
	this->srcvar = p;
}
statement::statement(int op,statement*s1){
	statement**l=new statement*[1];
	l[0]=s1;
	this->op = op;
	this->srcnum =1;
	this->src = l;
}
statement::statement(int op,statement*s1,statement*s2){
	statement**l=new statement*[2];
	l[0]=s1;
	l[1]=s2;
	this->op = op;
	this->srcnum = 2;
	this->src = l;
}
statement::statement(int op,statement*s1,statement*s2,statement*s3){
	statement**l=new statement*[3];
	l[0]=s1;
	l[1]=s2;
	l[2]=s3;
	this->op = op;
	this->srcnum = 3;
	this->src = l;
}
statement::statement(int op,statement*s1,statement*s2,statement*s3,statement*s4){
	statement**l=new statement*[4];
	l[0]=s1;
	l[1]=s2;
	l[2]=s3;
	l[3]=s4;
	this->op = op;
	this->srcnum = 4;
	this->src = l;
}


variable* statement::emit(){
	if (this->op == S_TYPE_FOR) {
		variable*list=this->src[1]->emit();
		if (list->type == TYPE_LIST) {
			for (int i = 0; i < list->size; i++) {
				variable* t = variable::at(list, new variable(i));
				statement** l = new statement * [2];
				l[0] = src[0];
				l[1] = new statement(t);
				(new statement(S_TYPE_ASSIGN, 2,l))->emit();
				this->src[2]->emit();
			}
		}
		return 0;
	}
	if (this->op == S_TYPE_ASVAR) {
		return this->srcvar;
	}
	variable** srcvars = new variable * [this->srcnum];
	for (int i = 0; i < this->srcnum; i++) {
		srcvars[i]=this->src[i]->emit();
		if (!srcvars[i]) return 0;
	}
	if (this->op == S_TYPE_LIST_OF_S) {
		return 0;
	}
	if (this->op == S_TYPE_ASSIGN) {
		varmap::assign(srcvars[0],srcvars[1]);
		return srcvars[1];//若要完成a=b=c需修改
	}
	if (this->op == S_TYPE_ADD) {
		return variable::add(srcvars[0], srcvars[1]);
	}
	if (this->op == S_TYPE_SUB) {
		return variable::sub(srcvars[0], srcvars[1]);
	}
	if (this->op == S_TYPE_MUL) {
		return variable::mul(srcvars[0], srcvars[1]);
	}
	if (this->op == S_TYPE_DIV) {
		return variable::div(srcvars[0], srcvars[1]);
	}
	if (this->op == S_TYPE_MOD) {
		return variable::mod(srcvars[0], srcvars[1]);
	}
	if (this->op == S_TYPE_AT) {
		return variable::at(srcvars[0], srcvars[1]);
	}
	if (this->op == S_TYPE_SLICE) {
		return variable::slice(srcvars[0], srcvars[1], srcvars[2], srcvars[3]);
	}
	if (this->op == S_TYPE_LEFTAT) {
		return variable::leftat(srcvars[0], srcvars[1]);
	}
	if (this->op == S_TYPE_LEFTSLICE) {
		return variable::leftslice(srcvars[0], srcvars[1], srcvars[2], srcvars[3]);
	}
	if (this->op == S_TYPE_POSOP) {
		return variable::posop(srcvars[0]);
	}
	if (this->op == S_TYPE_NEGOP) {
		return variable::negop(srcvars[0]);
	}
	if (this->op == S_TYPE_FUNC) {
		return varmap::func(srcvars[0], srcvars[1]);
	}
	if (this->op == S_TYPE_OBJFUNC) {
		return varmap::objfunc(srcvars[0], srcvars[1],srcvars[2]);
	}
	if (this->op == S_TYPE_CREATE_LIST) {
		variable** t = 0;
		return new variable(t,0) ;
	}
	if (this->op == S_TYPE_PRINT) {
		srcvars[0]->print();
		return srcvars[0];
	}
	if (this->op == S_TYPE_APPEND) {
		variable** l = new variable * [srcvars[0]->size + 1];
		for (int i = 0; i < srcvars[0]->size; i++) {
			l[i] = ((variable**)srcvars[0]->value)[i];
		}
		l[srcvars[0]->size] = srcvars[1];
		return srcvars[0];
	}
	if (this->op == S_TYPE_LOAD) {
		return this->varm->at(srcvars[0]);
	}
	if (this->op == S_TYPE_INSERT) {
		return this->varm->insert(srcvars[0]);
	}
	if (this->op==S_TYPE_LISTAPPEND){
		srcvars[0]->append(srcvars[1]);
		return srcvars[0];
	}	
}

void statement::append(statement* s){
	this->src[srcnum] = s;
	this->srcnum++;
}



