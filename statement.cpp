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
	if(this->op== S_TYPE_IF_ELSE){
		variable *v=src[0]->emit();
		if(!v) return 0;
		if(*((bool*)v->value)){
			v=src[1]->emit();
			if(!v) return 0;
		}else{
			v=src[2]->emit();
			if(!v) return 0;
		}
		
		return new variable();
	}
	if(this->op == S_TYPE_IF){
		variable *v=src[0]->emit();
		if(!v) return 0;
		if(*((bool*)v->value)){
			v=src[1]->emit();
			if(!v) return 0;
		}
		return new variable();
	}
	else if (this->op==S_TYPE_WHILE){
		//cout<<"here";
		variable *v=src[0]->emit();
		if (!v) return 0;
		while(*((bool*)v->value)){
			v=src[1]->emit();
			if (!v) return 0;
		}
		return new variable();
	}
	if (this->op==S_TYPE_ASBOOL){
		variable *v=src[0]->emit();
		if (!v){
			return 0;
		}
		if (v->type=TYPE_BOOL){
			return v;
		}
		if (v->type==TYPE_NONE){
			return new variable(true);
				}
		return new variable(false);
	}
	if (this->op==S_TYPE_NOP){
		return new variable();
	}
	if (this->op==S_TYPE_LISTFOR){
	 statement* s1=new statement(S_TYPE_CREATE_LIST,(int)0,0);
	variable *v=s1->emit();
	if (!v) return 0;
	statement* list_loop=src[1];
	for (int i=0;i<list_loop->srcnum-1;i++){
		list_loop->src[i]->src[2]=list_loop->src[i+1];
	}
	statement *s=new statement(v);
        statement *s2=new statement(S_TYPE_LISTAPPEND,s,src[0]);
	list_loop->src[list_loop->srcnum-1]->src[2]=s2;
	variable *v1=list_loop->src[0]->emit();
	if (!v1) return 0;
	return v;
	}
	if (this->op == S_TYPE_FOR) {
		variable*list=this->src[1]->emit();
		if (!list) return 0;
		if (list->type == TYPE_LIST) {
			for (int i = 0; i < list->size; i++) {
				variable* t = variable::at(list, new variable(i));
				statement** l = new statement * [2];
				l[0] = src[0];
				l[1] = new statement(t);
				variable *v=(new statement(S_TYPE_ASSIGN, 2,l))->emit();
				if (!v){
					return 0;
				}
				variable *v1=this->src[2]->emit();
				if (!v1){
					return 0;
				}
			}
		}
		else return 0;
		return new variable();
	}
	if (this->op == S_TYPE_ASVAR) {
		return this->srcvar;
	}
	variable** srcvars = new variable * [this->srcnum];
	for (int i = 0; i < this->srcnum; i++) {
		srcvars[i]=this->src[i]->emit();
		if (!srcvars[i]) return 0;
	}
	if (this->op==S_TYPE_ASBOOL){
                if(srcvars[0]==0)return new variable(false);
		if (srcvars[0]->type=TYPE_BOOL){
			return srcvars[0];
		}
		if (srcvars[0]->type==TYPE_NONE){
			return new variable(true);
				}
		return new variable(false);
	}
	if (this->op == S_TYPE_LIST_OF_S) {
		return new variable();
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
	
	if (this->op == S_TYPE_BOOLOP) {
            return variable::boolop(srcvars[0]);
	}

	if (this->op == S_TYPE_L) {
            return variable::lop(srcvars[0], srcvars[1]);
	}
	if (this->op ==S_TYPE_G) {
		return variable::gop(srcvars[0], srcvars[1]);
	}
	if (this->op == S_TYPE_LE) {
		return variable::leop(srcvars[0], srcvars[1]);
	}
	if (this->op == S_TYPE_GE) {
		return variable::geop(srcvars[0], srcvars[1]);
	}
	if (this->op == S_TYPE_EQ) {
		return variable::eqop(srcvars[0], srcvars[1]);
	}
	if (this->op == S_TYPE_NE) {
		return variable::neop(srcvars[0], srcvars[1]);
	}
	if (this->op == S_TYPE_NOT) {
		return variable::notop(srcvars[0]);
	}
	if (this->op == S_TYPE_AND) {
		return variable::andop(srcvars[0], srcvars[1]);
	}
	if (this->op == S_TYPE_OR) {
		return variable::orop(srcvars[0], srcvars[1]);
	}
	if (this->op == S_TYPE_OBJIS) {
		return variable::objis(srcvars[0], srcvars[1]);
	}
	if (this->op == S_TYPE_OBJNOT) {
		return variable::objnot(srcvars[0], srcvars[1]);
	}
	if (this->op == S_TYPE_OBJIN) {
		return variable::objin(srcvars[0], srcvars[1]);
	}
	if (this->op == S_TYPE_OBJNOTIN) {
		return variable::objnotin(srcvars[0], srcvars[1]);
	}
	if (this->op == S_TYPE_ASSERT) {
		if(srcvars[0]==0)cout<<"AssertionError"<<endl;
                if((*(bool*)srcvars[0]->value)==false)cout<<"AssertionError"<<endl;
                return 0;
	}
}

void statement::append(statement* s){
	this->src[srcnum] = s;
	this->srcnum++;
}



