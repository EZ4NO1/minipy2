%{
   /* definition */
#include "indentation.h"
 #define YYSTYPE statement*
   #include "lex.yy.c"
   varmap varm;
   indentation ind;
void yyerror(char*);
%}
%token ID INT REAL STRING_LITERAL FOR IN SPACE


%%
Start :startprompt Lines
      ;
startprompt:{cout<<">>>";}
	   ;
Lines : Lines Line '\n'{ind.addline($2);ind.prompt();}
	  |
	  |error '\n'{cout<<">>>";}
		
Line  :SPACE state{$$=$2;$$->space=$1->space;}
	  |state{$$=$1;$$->space=0;}
	  |SPACE{$$=new statement(S_TYPE_NOP,0,0);$$->space=$1->space;}
	  |{$$=new statement(S_TYPE_NOP,0,0);$$->space=0;}
	  ;


state:ID '=' add_expr{
				statement *s=new statement(S_TYPE_INSERT,$1);
				s->varm=&varm;
				$$= new statement(S_TYPE_ASSIGN,s,$3);
				}
           |left_expr '=' add_expr{ //add method assign combining insert and change
				$$= new statement(S_TYPE_ASSIGN,$1,$3);
				}
		   | add_expr {//打包成print(add_expr)
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
      | '['add_expr FOR ID IN add_expr ']'{
	statement *s=new statement(S_TYPE_INSERT,$4);
	s->varm=&varm;
	$$=new statement(S_TYPE_LISTFOR,$2,s,$6);

}	 
      | '['add_expr FOR left_expr IN add_expr ']'{
	$$=new statement(S_TYPE_LISTFOR,$2,$4,$6);

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
add_expr : add_expr '+' mul_expr  {//添加add
			$$=new statement(S_TYPE_ADD,$1,$3);
			}
	      |  add_expr '-' mul_expr {//添加sub
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
