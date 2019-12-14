%{
   /* definition */
#include "indentation.h"
#define YYSTYPE statement*
#include "lex.yy.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <cstdio>
char* filename=".command";
char **character_name_completion(const char *, int, int);
char *character_name_generator(const char *, int);
int yaccerror;
char *names[99] = {
    "for",
    "while",
    "if",
    "else",
0
};
int name_num=4;
   varmap varm;
   indentation ind;

void yyerror(char*);
%}
%token ID INT REAL STRING_LITERAL FOR IN SPACE IF ELSE WHILE True False AND_OP OR_OP NOT_OP LE_OP GE_OP NE_OP EQ_OP IS ASSERT


%%
Start : Line  {ind.addline($1);} 
	  |error {cout<<">>>";}
	;	
Line  :SPACE state{$$=$2;$$->space=$1->space;}
	  |state{$$=$1;$$->space=0;}
	  |SPACE{$$=new statement(S_TYPE_NOP,0,0);$$->space=$1->space;}
	  |{$$=new statement(S_TYPE_NOP,0,0);$$->space=0;
	    $$->varm=&varm;
	  }
	  ;


state:ID '=' add_expr{
				statement *s=new statement(S_TYPE_INSERT,$1);
				s->varm=&varm;
				$$= new statement(S_TYPE_ASSIGN,s,$3);
				}
           |left_expr '=' add_expr{ //add method assign combining insert and change
				$$= new statement(S_TYPE_ASSIGN,$1,$3);
				}
				 |ASSERT condition{$$=new statement(S_TYPE_ASSERT,$2);}
                   |conditional_expr{
			$$=new statement(S_TYPE_PRINT,$1);
				}
		   | FOR ID IN add_expr ':'{
				statement *s=new statement(S_TYPE_INSERT,$2);
				s->varm=&varm;
				statement** l=new statement*[99];
				statement *s1=new statement(S_TYPE_LIST_OF_S,0,l);
				$$= new statement(S_TYPE_FOR,s,$4,s1);
				}
			   |FOR left_expr IN add_expr ':'{
				statement** l=new statement*[99];
				statement *s1=new statement(S_TYPE_LIST_OF_S,0,l);
				$$= new statement(S_TYPE_FOR,$2,$4,s1);
				}
                  | WHILE condition ':'{
	statement** l=new statement*[99];
	statement *s1=new statement(S_TYPE_LIST_OF_S,0,l);
	$$= new statement(S_TYPE_WHILE,$2,s1);
}
|IF condition ':'{
statement ** l = new statement*[99];
statement *s1 = new statement(S_TYPE_LIST_OF_S,0,l);
$$=new statement(S_TYPE_IF,$2,s1);
}
|ELSE  ':'{
statement ** l = new statement*[99];
statement *s1 = new statement(S_TYPE_LIST_OF_S,0,l);
$$=new statement(S_TYPE_ELSE,s1);
}
;
condition:conditional_expr{
                statement *s=new statement(S_TYPE_BOOLOP,$1);
                s->varm=&varm;
		$$=new statement(S_TYPE_ASBOOL,s);}
;
	  
left_expr:atom_expr  '[' sub_expr  ':' sub_expr  slice_op ']'{
	  $$=new statement(S_TYPE_LEFTSLICE,$1,$3,$5,$6);

}
        |  atom_expr '[' add_expr ']'{
	  $$=new statement(S_TYPE_LEFTAT,$1,$3);
		} 
		;
number : INT{
    $$=$1;
}
       | REAL{
	   $$=$1;
	   }
       ;
factor : '+' factor{
	  $$=new statement(S_TYPE_POSOP,$2);
}
       | '-' factor{
	  $$=new statement(S_TYPE_NEGOP,$2);
	   }
       | atom_expr{$$=$1;}
       ; 
atom  : ID  {
	  $$=new statement(S_TYPE_LOAD,$1);
          $$->varm=&varm;
}
      | STRING_LITERAL {$$=$1;
		}

      | List {$$=$1;}
      | number {$$=$1;}
      | True{$$=$1;}
      | False{$$=$1;}
      ;


slice_op :  /*  empty production */{$$=new statement(new variable(1));}
		|':'{$$=new statement(new variable(1));}
        | ':' add_expr {$$=$2;}
        ;
sub_expr:  /*  empty production */{$$=new statement(new variable());}
        | add_expr{$$=$1;}
        ;        
atom_expr : atom  {$$=$1;}
        | atom_expr  '[' sub_expr  ':' sub_expr  slice_op ']'{
		$$=new statement(S_TYPE_SLICE,$1,$3,$5,$6);
		}
        | atom_expr  '[' add_expr ']'{
		$$=new statement(S_TYPE_AT,$1,$3);
		}
		|func_exper{$$=$1;}
|'(' atom_expr')' {$$=$1;}
        ;

func_exper: func_name  '(' List_items ')'{
			$$=new statement(S_TYPE_FUNC,$1,$3);
}
        | func_name   '('  ')'{
				statement *s=new statement(S_TYPE_CREATE_LIST,0,0);
				$$=new statement(S_TYPE_FUNC,$1,s);
		}
        | atom_expr'.'func_name  '(' List_items ')'{
			$$=new statement(S_TYPE_OBJFUNC,$1,$3,$5);
		}
        | atom_expr'.'func_name   '('  ')'{
			statement *s=new statement(S_TYPE_CREATE_LIST,0,0);
			$$=new statement(S_TYPE_OBJFUNC,$1,$3,s);
		}
		;

func_name:ID{$$=$1;}
;
List  : '[' ']' {
			$$=new statement(S_TYPE_CREATE_LIST,0,0);
				}
      | '[' List_items opt_comma ']'{
			$$=$2;
	  }
      | '['add_expr list_for ']'{
	$$=new statement(S_TYPE_LISTFOR,$2,$3);

}	 
;
list_for:list_for FOR ID IN add_expr{
	$$=$1;
	statement *s=new statement(S_TYPE_INSERT,$3);
	s->varm=&varm;
	statement **l=new statement*[99];
	$$->append(new statement(S_TYPE_FOR,s,$5,0));
}
       |list_for FOR left_expr IN add_expr{
	$$=$1;
	statement **l=new statement*[99];
	$$->append(new statement(S_TYPE_FOR,$3,$5,0));
	
}
	|FOR ID IN add_expr{
	statement *s=new statement(S_TYPE_INSERT,$2);
	s->varm=&varm;
	statement **l=new statement*[99];
	$$=new statement(S_TYPE_LIST_OF_S,0,l);
	$$->append(new statement(S_TYPE_FOR,s,$4,0));
}
	|FOR left_expr IN add_expr{
	statement **l=new statement*[99];
	$$=new statement(S_TYPE_LIST_OF_S,0,l);
	$$->append(new statement(S_TYPE_FOR,$2,$4,0));
}	

      ;
opt_comma : /*  empty production */{}
          | ','{}
          ;
List_items  
      : add_expr  {
		statement*s=new statement(S_TYPE_CREATE_LIST,0,0);
		$$=new statement(S_TYPE_LISTAPPEND,s,$1);
	
	  }
      | List_items ',' add_expr{
			$$=new statement(S_TYPE_LISTAPPEND,$1,$3);
	  } 
      ;
add_expr : add_expr '+' mul_expr  {//Ìí¼Óadd
			$$=new statement(S_TYPE_ADD,$1,$3);
			}
	      |  add_expr '-' mul_expr {//Ìí¼Ósub
			$$=new statement(S_TYPE_SUB,$1,$3);
		  }
	      |  mul_expr {
		    $$=$1;
		  }

		
;
mul_expr : mul_expr '*' factor{ //add method mul
			$$=new statement(S_TYPE_MUL,$1,$3);
		}
        |  mul_expr '/' factor{//add method div
			$$=new statement(S_TYPE_DIV,$1,$3);
		}
	      |  mul_expr '%' factor{//add method mod
			$$=new statement(S_TYPE_MOD,$1,$3);
		  }
        |  factor{
		$$=$1;
		}
        ;

object_expr:add_expr{$$=$1;}
           |atom IS atom{$$=new statement(S_TYPE_OBJIS,$1,$3);}
           |atom IS NOT_OP atom{$$=new statement(S_TYPE_OBJNOT,$1,$4);}
           |atom IN atom{$$=new statement(S_TYPE_OBJIN,$1,$3);}
           |atom NOT_OP IN atom{$$=new statement(S_TYPE_OBJNOTIN,$1,$4);}
           ;
relational_expr:object_expr{$$=$1;}
         | relational_expr '>' add_expr{
			$$=new statement(S_TYPE_G,$1,$3);
		}
         | relational_expr '<' add_expr{
			$$=new statement(S_TYPE_L,$1,$3);
		}
         | relational_expr LE_OP add_expr{
			$$=new statement(S_TYPE_LE,$1,$3);
		}
         | relational_expr GE_OP add_expr{
			$$=new statement(S_TYPE_GE,$1,$3);
		}
         ;
equality_expr : relational_expr{$$=$1;}
         | equality_expr EQ_OP relational_expr{
			$$=new statement(S_TYPE_EQ,$1,$3);
		}
         | equality_expr NE_OP relational_expr{
			$$=new statement(S_TYPE_NE,$1,$3);
		}
         ;
logical_not_expr:equality_expr{$$=$1;}
                | NOT_OP logical_not_expr{$$=new statement(S_TYPE_NOT,$2);}
                ;
logical_and_expr:logical_not_expr{$$=$1;}
                |logical_and_expr AND_OP logical_not_expr{
			$$=new statement(S_TYPE_AND,$1,$3);
		}
                ;
logical_or_expr:logical_and_expr{$$=$1;}
               |logical_or_expr OR_OP logical_and_expr{
			$$=new statement(S_TYPE_OR,$1,$3);
		}
               ;
conditional_expr:logical_or_expr{$$=$1;}
                ;

%%

int main()
{
cout<<"Minipy_v2 [Copyright:gy991007,alicemare,ling0-cell@github.com]"<<endl;
ind.init();
rl_attempted_completion_function = character_name_completion;
varm.pname_num=&name_num;
varm.names=names;
while(1){
	yaccerror=0;
	char *buffer;
	if (ind.stk.empty())
	buffer = readline(">>>");
	else buffer=readline("...");
	remove(filename);
	FILE* f=fopen(filename,"w");
	fputs(buffer,f);
	fclose(f);
	f=fopen(filename,"r");
	yyin=f;
	yyparse();
	fclose(f);
	if (!yaccerror)
	add_history(strdup(buffer));
}
}

char ** character_name_completion(const char *text, int start, int end)
{
int count;
char* p;
int len;
rl_attempted_completion_over = 1; 
len=strlen(text);
if (len==0) {
char** re=new char*[2];
re[0]=new char[2];
re[0][0]='\t';
re[0][1]=0;
re[1]=NULL;
return re;
}
count=0;
    for (int i=0;i<name_num;i++){
	if (strncmp(names[i],text,len)==0){
	p=strdup(names[i]);
	count++;
	}
}
if (count==1){
char** re=new char*[2];
re[0]=p;
re[1]=NULL;
return re;
}
    return NULL;
}

void yyerror(char *s)
{
cout<<s<<endl;
ind.init();
return;
}

int yywrap()
{
return 1; }        		    
