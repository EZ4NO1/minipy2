/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    ID = 258,
    INT = 259,
    REAL = 260,
    STRING_LITERAL = 261,
    FOR = 262,
    IN = 263,
    SPACE = 264,
    IF = 265,
    ELSE = 266,
    WHILE = 267,
    True = 268,
    False = 269,
    AND_OP = 270,
    OR_OP = 271,
    NOT_OP = 272,
    LE_OP = 273,
    GE_OP = 274,
    NE_OP = 275,
    EQ_OP = 276,
    IS = 277,
    ASSERT = 278
  };
#endif
/* Tokens.  */
#define ID 258
#define INT 259
#define REAL 260
#define STRING_LITERAL 261
#define FOR 262
#define IN 263
#define SPACE 264
#define IF 265
#define ELSE 266
#define WHILE 267
#define True 268
#define False 269
#define AND_OP 270
#define OR_OP 271
#define NOT_OP 272
#define LE_OP 273
#define GE_OP 274
#define NE_OP 275
#define EQ_OP 276
#define IS 277
#define ASSERT 278

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
