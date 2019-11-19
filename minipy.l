%{
#include "variable.h"
#define YYSTYPE variable*
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
				yylval=new variable(n);
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
				yylval=new variable(n);
                		return REAL;
            }
{id}        {
			    yylval=new variable(string(yytext));
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
					yylval=new variable(str1);

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
					yylval=new variable(str1);

					return(STRING_LITERAL); /*comments */
					}
.|\n        {return (yytext[0]); }
%%
