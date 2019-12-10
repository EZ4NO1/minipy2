%{
#include "statement.h"
#define YYSTYPE statement*
#include "y.tab.h"

/*  any C declaration  */
%}

letter    [a-zA-Z]

digit     [0-9]

number   {digit}+

id       {letter}({letter}|{digit})*

real     {number}"."{number}

%%
[ \t]+      {/*do nothing , just skip */}
{number}    { 
				int n;
				n=0;
				for(int i=0;i<yyleng;i++){
				n=n*10+(yytext[i]-'0');
				}
				variable* t=new variable(n);
				yylval=new statement(t);
//cout<<"int";
				return INT;
				

            }

{real}      {
				float n;
				float fl;
				int sig;
				n=0;
				fl=0.1;
//cout<<yytext<<endl;
				for (int i=0;i<yyleng;i++){
				if (yytext[i]=='.'){
					sig=i;
					break;
				}
				}
//cout<<sig<<endl;
				for(int i=0;i<sig;i++){
					n=n*10+(yytext[i]-'0');
				}
//cout<<n<<endl;
				for(int i=sig+1;i<yyleng;i++){
					n=n+fl*(yytext[i]-'0');
					fl=fl/10;
				}
				//cout<<"real"<<n;
				variable* t=new variable(n);
				yylval=new statement(t)
                		return REAL;
            }
for  {
return FOR;
}
in {
return IN;
}
{id}        {
			    variable* t=new variable(string(yytext));
				yylval=new statement(t)
               return ID; 
            }
\"(\\.|[^\\"])*\"	{
					char  chs[99];
					string str1;
				    for	( int i=1;i<yyleng-1;i++){
						chs[i-1]=yytext[i];
					}
					chs[yyleng-2]=0;
					str1=chs;
					variable* t=new variable(str1);
				yylval=new statement(t)
					return(STRING_LITERAL); /*comments */
					}
'(\\.|[^\\'])*'	{
					char  chs[99];
					string str1;
				    for	( int i=1;i<yyleng-1;i++){
						chs[i-1]=yytext[i];
					}
					chs[yyleng-2]=0;
					str1=chs;
					variable* t=new variable(str1);
				   yylval=new statement(t)
					return(STRING_LITERAL); /*comments */
					}
.|\n        {return (yytext[0]); }
%%
