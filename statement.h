#ifndef STATEMENT_H
#define STATEMENT_H
#include "varmap.h"
#define S_TYPE_FOR -3
#define S_TYPE_LIST_OF_S -2
#define S_TYPE_ASVAR -1
#define S_TYPE_ASSIGN 0
#define S_TYPE_ADD 1
#define S_TYPE_SUB 2
#define S_TYPE_MUL 3
#define S_TYPE_DIV 4
#define S_TYPE_MOD 5
#define S_TYPE_AT 6
#define S_TYPE_SLICE 7
#define S_TYPE_LEFTAT 8
#define S_TYPE_LEFTSLICE 9 
#define S_TYPE_POSOP 10
#define S_TYPE_NEGOP 11
#define S_TYPE_FUNC 12
#define S_TYPE_OBJFUNC 13 
#define S_TYPE_CREATE_LIST 14
#define S_TYPE_PRINT 15
#define S_TYPE_APPEND 16
#define S_TYPE_LOAD 17
#define S_TYPE_INSERT 18
#define S_TYPE_LISTAPPEND 19
#define S_TYPE_LISTFOR 20
#define S_TYPE_NOP 21
#define S_TYPE_SPACE 22
class statement {
public:
	statement** src;
	variable* srcvar;
	varmap* varm;
	int op;
	int srcnum;
	int space=-1;
	int subspace=-1;
	statement(int,int,statement**);
	statement(int,statement*);
	statement(int,statement*,statement*);
	statement(int,statement*,statement*,statement*);
	statement(int,statement*,statement*,statement*,statement*);
	statement(variable*);
	variable* emit();
	void append(statement*);
	
};

#endif
