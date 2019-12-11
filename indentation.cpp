#include "indentation.h"
indentation::indentation(){
	this->init();
}
void indentation::init(){
	while(!stk.empty()){
		stk.pop();
	}
}
void indentation::error(){
	init();
	cout<<"indentation error"<<endl;
}
void indentation::addline(statement* s){
	if (stk.empty()){
		if (s->space==0){
			merge(s);
			return;	
		}
		else{
			error();
			return;
		}
	}

	if (stk.top()->subspace==-1){
		if (s->space<=stk.top()->space){
			error();
		}
		else {
			stk.top()->subspace=s->space;
			merge(s);
		}
		return;
	}
	if (s->space==0){
		statement* st=0;
		while(true){
				st=stk.top();
				stk.pop();
				if (stk.empty()) break;
			}
		st->emit();
		
		s->emit();
		return;
	}
	statement *st=0;
	while(!stk.empty()){
			if (stk.top()->subspace==s->space){
				merge(s);
				return;
			}
			stk.pop();
		}
	if (stk.empty()){
		error();
	}
}

void indentation::prompt(){
	if (stk.empty())
		cout<<">>>";
	else cout<<"...";
}

void indentation::merge(statement* s){
	if (!stk.empty()){	
	if (stk.top()->op==S_TYPE_FOR){
		stk.top()->src[2]->append(s);
	}
	if (stk.top()->op==S_TYPE_WHILE){
		stk.top()->src[1]->append(s);
	}
	}

	if ((s->op==S_TYPE_FOR)||(s->op==S_TYPE_WHILE)){
		stk.push(s);
		return;
	}
	if (stk.empty()){
		s->emit();
		return;
	}
}
