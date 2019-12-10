#include "indentation.h"
indentation::indentation(){
	this->init();
}
indentation::init(){
	while(!stk.empty()){
		stk.pop()
	}
}
indentation::error(){
	init();
	cout<<"indentation error"<<endl;
	prompt();
}
void indentation::addline(statement* s){
	if (stk.top()->subspace==-1){
		if (s.space<=stk.top()->space){
			error();
		}
		else {
			stk.top().subspace=s.space;
			merge(s);
		}
		return;
	}
	if (s.space==0){
		statement *st=0;
		if (stk.empty()) {
			s->emit();
			return;
		}
		while(true){
				st=this->stk.pop();
				if (stk.empty()) break;
				merge(st);
			}
		st->emit();
		s->emit();
		return;
	}
	statement *st=0;
	while(!s.empty()){
			if (s.top()->subspace=s->space){
				merge(s);
				return;
			}
			st=stk.pop();
			merge(st);
		}
	if (s.empty()){
		error();
	}
}

void indentation::prompt(){
	if (stk.empty())
		cout<<">>>"<<endl;
	else cout<<"..."<<endl;
}

void indentation::merge(statement* s){
	if (s->op==S_TYPE_FOR){
		stk.push(s);
		return;
	}
	if (stk.top()->op==S_TYPE_FOR){
		stk.top()->src[2]->append(s);
		return;
	}
	error();
}