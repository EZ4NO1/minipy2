%{
   /* definition */
#include "statement.h"
 #define YYSTYPE statement*
   #include "lex.yy.c"
   varmap varm;
void yyerror(char*);
%}
%token ID INT REAL STRING_LITERAL


%%
Start : prompt Lines
      ;
Lines : Lines  stat '\n' prompt
      | Lines  '\n' prompt 
	  | Lines loop prompt
      |
      | error '\n'
      ;
loop:FOR ID IN add_expr ':' '\n' loopprompt loopbody{
		statement** l=new statement*[1];
		l[0]=$2;
		statement *s=new statement(S_TYPE_INSERT,1,l);
		statement** l2=new statement*[3];
		l2[0]=s;
		l2[1]=$4;
		l2[2]=$8;
		$$= new statement(S_TYPE_ASSIGN,3,l2);
}
|FOR left_expr IN add_expr ':' '\n' loopprompt loopbody{
		statement** l2=new statement*[3];
		l2[0]=$2;
		l2[1]=$4;
		l2[2]=$8;
		$$= new statement(S_TYPE_ASSIGN,3,l2);
}
;
loopprompt:{cout<<"...";}
;
loopbody:statements loopprompt '\n'{$$=$1}
;
statements:{
l=new statement*[99];
$$=new statement(S_TYPE_LIST_OF_S,0,l);}
|statements assignExpr loopprompt '\n'{
$1->append($2);
$$=$1;
}
;
prompt : {cout << ">>> ";}
       ;
stat  : assignExpr
      |
      ;
assignExpr:
		ID '=' add_expr{
		statement** l=new statement*[1];
		l[0]=$1;
		statement *s=new statement(S_TYPE_INSERT,1,l);
		statement** l2=new statement*[2];
		l2[0]=s;
		l2[1]=$2;
		$$= new statement(S_TYPE_ASSIGN,2,l2);
		}
        |left_expr '=' add_expr{ //add method assign combining insert and change
		statement** l=new statement*[2];
		l[0]=$1;
		l[1]=$2;
		$$= new statement(S_TYPE_ASSIGN,2,l);
		}
      | add_expr {//打包成print(add_expr)
	  statement** l=new statement*[1];
	  l[0]=$1;
	  $$=new statement(S_TYPE_PRINT,1,l);
	  }
      ;
	  
left_expr:atom_expr  '[' sub_expr  ':' sub_expr  slice_op ']'{
	statement** l=new statement*[4];
	  l[0]=$1;
	  l[1]=$3;
	  l[2]=$5;
	  l[3]=$6;
	  $$=new statement(S_TYPE_LEFTSLICE,4,l);
	  $$->varm=varm;

}
        |  atom_expr '[' add_expr ']'{
		statement** l=new statement*[2];
	  l[0]=$1;
	  l[1]=$3;
	  $$=new statement(S_TYPE_LEFTAT,2,l);
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
		statement** l=new statement*[1];
	  l[0]=$2;
	  $$=new statement(S_TYPE_POSOP,1,l);
}
       | '-' factor{
	   	statement** l=new statement*[1];
	  l[0]=$2;
	  $$=new statement(S_TYPE_NEGOP,1,l);
	   }
       | atom_expr{$$=$1;}
       ; 
atom  : ID  {
	statement** l=new statement*[1];
	  l[0]=$1;
	  $$=new statement(S_TYPE_LOAD,1,l);
}
      | STRING_LITERAL {$$=$1;
		}

      | List {$$=$1;}
      | number {$$=$1;}
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
		statement** l=new statement*[4];
		l[0]=$1;
		l[1]=$3;
		l[2]=$5;
		l[3]=$6;
		$$=new statement(S_TYPE_SLICE,4,l);
		}
        | atom_expr  '[' add_expr ']'{
		statement** l=new statement*[2];
		l[0]=$1;
		l[1]=$3;
		$$=new statement(S_TYPE_AT,2,l);
		}
		|func_exper{$$=$1;}
        ;

func_exper: func_name  '(' List_items ')'{
			statement** l=new statement*[2];
			l[0]=$1;
			l[1]=$3;
			$$=new statement(S_TYPE_FUNC,2,l);
}
        | func_name   '('  ')'{
				variable* t=new variable();
				t->type=TYPE_LIST;
				t->size=0;
				t->value=0;
				statement *s=new statement(t);
				statement** l=new statement*[2];
				l[0]=$1;
				l[1]=s;
				$$=new statement(S_TYPE_FUNC,2,l);
		}
        | atom_expr'.'func_name  '(' List_items ')'{
			statement** l=new statement*[3];
			l[0]=$1;
			l[1]=$3;
			l[2]=$5;
			$$=new statement(S_TYPE_FUNC,3,l);
		}
        | atom_expr'.'func_name   '('  ')'{
			variable* t=new variable();
				t->type=TYPE_LIST;
				t->size=0;
				t->value=0;
				statement *s=new statement(t);
			statement** l=new statement*[3];
			l[0]=$1;
			l[1]=$3;
			l[2]=s;
			$$=new statement(S_TYPE_FUNC,3,l);
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
      ;
opt_comma : /*  empty production */{}
          | ','{}
          ;
List_items  
      : add_expr  {
		statement** l=new statement*[2];
		l[0]=new statement(S_TYPE_CREATE_LIST,0,0);
		l[1]=$1;
		$$=new statement(S_TYPE_APPEND,2,l);
	
	  }
      | List_items ',' add_expr{
	        statement** l=new statement*[2];
			l[0]=$1;
			l[1]=$3;
			$$=new statement(S_TYPE_APPEND,2,l);
	  } 
      ;
add_expr : add_expr '+' mul_expr  {//添加add
			statement** l=new statement*[2];
			l[0]=$1;
			l[1]=$3;
			$$=new statement(S_TYPE_ADD,2,l);
			}
	      |  add_expr '-' mul_expr {//添加sub
			statement** l=new statement*[2];
			l[0]=$1;
			l[1]=$3;
			$$=new statement(S_TYPE_SUB,2,l);
		  }
	      |  mul_expr {
		    $$=$1;
		  }
        ;
mul_expr : mul_expr '*' factor{ //add method mul
           statement** l=new statement*[2];
			l[0]=$1;
			l[1]=$3;
			$$=new statement(S_TYPE_MUL,2,l);
		}
        |  mul_expr '/' factor{//add method div
			statement** l=new statement*[2];
			l[0]=$1;
			l[1]=$3;
			$$=new statement(S_TYPE_DIV,2,l);
		}
	      |  mul_expr '%' factor{//add method mod
		  statement** l=new statement*[2];
			l[0]=$1;
			l[1]=$3;
			$$=new statement(S_TYPE_MOD,2,l);
		  }
        |  factor{
		$$=$1;
		}
        ;

%%

int main()
{
   return yyparse();
}

void yyerror(char *s)
{
   cout << s << endl<<"miniPy> "; 
}

int yywrap()
{ return 1; }        		    
