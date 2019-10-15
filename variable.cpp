#include "variable.h"
variable::variable(){
	type=TYPE_NONE;
	value=NULL;
	naint=1;
}
variable::variable(float n){
	this->type=TYPE_NUMBER;
	if ((n-int(n))<1e-5){
		naint=false;
		this->value=new int;
		*((int*)this->value)=int(n);
		}
	else{
		naint=true;
		this->value=new float;
		*((float*)this->value)=n;
		}
}
variable::variable(string str){
	this->type=TYPE_STR;
	this->value=new string(str);
	naint=true;
}
variable::variable(vector<variable> a){
	this->type=TYPE_LIST;
	this->value=&a;
	naint=true;
}
int variable::print(bool b) {

	if (this->type==TYPE_NUMBER)
		if (this->naint)
			cout<<*((float*)this->value);
		else 
			cout<<*((int*)this->value);
	else if (this->type==TYPE_STR)
		cout<<*((string*)this->value);
	else if (this->type==TYPE_LIST){
		cout<<"[";
		vector<variable> vec=*((vector<variable>*)this->value);
			if (vec.size()!=0){
				vec.at(0).print(false);
			for (int i = 1; i < vec.size() ; i++){
				cout<<",";
				vec.at(i).print(false);
			}
		}
		cout<<"]";
	}
	else if (this->type==TYPE_NONE){
		cout<<"None";
	}
	else return -1;
	if (b) cout<<endl;
	return 0;
}
variable::~variable(){
	if (type==TYPE_NUMBER)
		if (naint)
			delete((float*)value);
		else
			delete((int*)value);
	else if (type==TYPE_STR)
		delete((string*)value);
	else if (type==TYPE_LIST)
	delete((vector<variable>*)value);

}
