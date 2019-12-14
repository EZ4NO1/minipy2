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
		if (s->op==S_TYPE_ELSE){
			error();
			return;
		}
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
		if (s->op==S_TYPE_ELSE){
			error();
			return;
		}
		if (s->space<=stk.top()->space){
			error();
		}
		else {
			stk.top()->subspace=s->space;
			merge(s);
		}
		return;
	}
	if (s->op==S_TYPE_ELSE){
		while(!stk.empty()){
		if (stk.top()->space==s->space){
			break;
		}
		stk.pop();
		}
		if (stk.empty()) {error(); return;} 
		if (stk.top()->op!=S_TYPE_IF) {error(); return;}
		statement* state=stk.top();
		stk.pop();
		statement* ife=new statement(S_TYPE_IF_ELSE,state->src[0],state->src[1],s->src[0]);
		if (!stk.empty()){
			if ((stk.top()->op==S_TYPE_FOR)||(stk.top()->op==S_TYPE_IF_ELSE)){
				stk.top()->src[2]->src[stk.top()->src[2]->srcnum-1]=ife;
			}
			if (stk.top()->op==S_TYPE_WHILE||stk.top()->op==S_TYPE_IF){
				stk.top()->src[1]->src[stk.top()->src[1]->srcnum-1]=ife;
			}
		}
		stk.push(ife);
		return;
	}

	if (s->space==0){
		if ((s->op==S_TYPE_FOR)||(s->op==S_TYPE_WHILE)||(s->op==S_TYPE_IF)){
			error();
			return;}
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
	if ((stk.top()->op==S_TYPE_FOR)||(stk.top()->op==S_TYPE_IF_ELSE)){
		//cout<<"here"<<endl;
		stk.top()->src[2]->append(s);
	}
	if (stk.top()->op==S_TYPE_WHILE||stk.top()->op==S_TYPE_IF){
		stk.top()->src[1]->append(s);
	}
	}

	if ((s->op==S_TYPE_FOR)||(s->op==S_TYPE_WHILE)||(s->op==S_TYPE_IF)){
		stk.push(s);
		return;
	}
	if (stk.empty()){
		s->emit();
		return;
	}
}
