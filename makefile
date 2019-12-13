
LEX=lex
YACC=yacc
CC=g++
CFLAGS = -I/usr/local/opt/readline/include
LDFLAGS = -L/usr/local/opt/readline/lib
LIBS = -lreadline
OBJECT=main.out #生成的目标文件
 
$(OBJECT): y.tab.c  y.tab.h variable.cpp variable.h varmap.cpp varmap.h statement.h statement.cpp indentation.h indentation.cpp
	$(CC)  y.tab.c variable.cpp varmap.cpp statement.cpp indentation.cpp -o $(OBJECT) $(CFLAGS) $(LDFLAGS) $(LIBS) 
	./$(OBJECT) #编译后立刻运行
 
y.tab.c y.tab.h: minipy.y lex.yy.c
# bison使用-d参数编译.y文件
	$(YACC) -d  minipy.y
 
lex.yy.c: minipy.l
	$(LEX) minipy.l
clean:
	rm lex.yy.c y.tab.c y.tab.h $(OBJECT)
