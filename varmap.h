#ifndef VARMAP_H
#define VARMAP_H
#include <map>
#include "variable.h"
//#endif
class varmap{
	public:
	map<string,variable> vmap;
	public:
	varmap();
	~varmap();
	variable* get(string);
	variable* crevar(string,variable);
	int delvar(string);
	int print(string);
};
#endif
