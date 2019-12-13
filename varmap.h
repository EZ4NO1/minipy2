#ifndef VARMAP_H
#define VARMAP_H
#include "variable.h"
#define VARMAP_MAX_LENGTH 99

extern string type_str[8];


class varmap{
public:
	string key[VARMAP_MAX_LENGTH];
	variable* pointer[VARMAP_MAX_LENGTH] ;
	int size=0;
	int* pname_num;
	char** names;
	varmap();
	variable* insert(variable*);
	variable* at(variable*);
	variable* leftat(variable*);
	bool exsit(variable*);
	static variable* func(variable*, variable*);
	static variable* objfunc(variable*, variable*,variable*);
	static void assign(variable*,variable*);
	~varmap();
};
#endif
