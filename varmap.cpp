#include "varmap.h"
varmap::varmap(){
}
varmap::~varmap(){
}
variable* varmap::crevar( string name,variable v){
	this->vmap[name]=v;
	return &(this->vmap[name]);
}
int varmap::delvar(string){
	return 0;
}
variable* varmap::get(string str){
	return &(this->vmap[str]);
}
int varmap::print(string str){
	this->vmap[str].print(true);
	return 0;
}

