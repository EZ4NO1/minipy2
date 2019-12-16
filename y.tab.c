/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "minipy.y" /* yacc.c:339  */

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

#line 95 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
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

/* Copy the second part of user declarations.  */

#line 192 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  59
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   323

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  39
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  83
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  160

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   278

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    36,     2,     2,
      30,    31,    34,    28,    33,    29,    32,    35,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    25,     2,
      38,    24,    37,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    26,     2,    27,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    33,    33,    34,    36,    37,    38,    39,    45,    50,
      53,    54,    57,    64,    69,    74,    79,    85,    91,    95,
      99,   102,   106,   109,   112,   114,   118,   121,   122,   123,
     124,   125,   129,   130,   131,   133,   134,   136,   138,   141,
     144,   147,   150,   154,   157,   163,   165,   168,   171,   176,
     183,   189,   196,   203,   204,   207,   212,   216,   219,   222,
     228,   231,   234,   237,   242,   243,   244,   245,   246,   248,
     249,   252,   255,   258,   262,   263,   266,   270,   271,   273,
     274,   278,   279,   283
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ID", "INT", "REAL", "STRING_LITERAL",
  "FOR", "IN", "SPACE", "IF", "ELSE", "WHILE", "True", "False", "AND_OP",
  "OR_OP", "NOT_OP", "LE_OP", "GE_OP", "NE_OP", "EQ_OP", "IS", "ASSERT",
  "'='", "':'", "'['", "']'", "'+'", "'-'", "'('", "')'", "'.'", "','",
  "'*'", "'/'", "'%'", "'>'", "'<'", "$accept", "Start", "Line", "state",
  "condition", "left_expr", "number", "factor", "atom", "slice_op",
  "sub_expr", "atom_expr", "func_exper", "func_name", "List", "list_for",
  "opt_comma", "List_items", "add_expr", "mul_expr", "object_expr",
  "relational_expr", "equality_expr", "logical_not_expr",
  "logical_and_expr", "logical_or_expr", "conditional_expr", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,    61,    58,    91,    93,    43,    45,
      40,    41,    46,    44,    42,    47,    37,    62,    60
};
# endif

#define YYPACT_NINF -62

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-62)))

#define YYTABLE_NINF -46

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     137,   -62,    -7,   -62,   -62,   -62,   260,   194,   222,   -11,
     222,   -62,   -62,   222,   222,   227,   255,   255,   222,    19,
     -62,   -62,    53,   -62,   -62,    93,    12,   -62,    -8,   -62,
      44,    73,   -62,    37,    79,   -62,    32,    21,   -62,   255,
      10,   103,   -62,    12,   -62,    31,    69,    66,   -62,   -62,
      95,   -62,   -62,   -62,   106,    14,   -62,   -62,   114,   -62,
     255,   274,   145,    22,   255,   161,    99,   255,   255,   255,
     255,   255,   255,   255,   255,   255,   255,   255,   222,   222,
      44,   255,   255,   -62,   255,   -62,   255,   147,   288,     6,
     -62,    44,   -62,   -62,   274,   274,   -62,   150,   104,   -62,
     146,   -62,   -27,    44,    73,    73,   -62,   -62,   -62,    44,
      44,    44,    44,    37,    37,   -62,    32,    62,   127,   152,
     130,    44,   -62,    23,   172,   293,   -62,   -62,   -62,   255,
      26,   165,   -62,   255,   -62,   -62,   255,   -62,   255,   255,
      24,   173,   157,    44,   -62,    86,   157,    44,    44,   255,
     255,   255,   156,   -62,   158,    44,    44,    44,    38,   -62
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     3,    25,    20,    21,    26,     0,     6,     0,     0,
       0,    29,    30,     0,     0,     0,     0,     0,     0,     0,
       2,     5,     0,    28,    63,    37,    24,    40,     0,    27,
      64,    59,    69,    74,    77,    79,    81,    83,    11,     0,
      25,     0,    37,     0,     4,    25,     0,    24,    17,    16,
       0,    78,    10,    46,    53,    55,    22,    23,     0,     1,
       0,     0,     0,     0,    35,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       8,     0,     0,    15,    35,    14,    54,     0,     0,     0,
      31,     9,    25,    67,     0,     0,    65,     0,    36,    45,
       0,    42,     0,    55,    57,    58,    60,    61,    62,    72,
      73,    70,    71,    76,    75,    80,    82,     0,     0,     0,
      36,    56,    47,    25,     0,     0,    48,    68,    66,    35,
      39,     0,    41,     0,    12,    13,    35,    39,     0,     0,
      25,     0,    32,    36,    44,     0,    32,    51,    52,     0,
       0,    33,     0,    43,     0,    49,    50,    34,    38,    38
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -62,   -62,   -62,   177,    54,    -3,   -62,    13,     2,    40,
     -43,     1,   -62,   122,   -62,   -62,   -62,   -61,   -15,    94,
     -62,    96,   -62,    -2,   109,   -62,    88
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    19,    20,    21,    46,    22,    23,    24,    42,   152,
      97,    47,    27,    28,    29,    89,    87,    54,    30,    31,
      32,    33,    34,    35,    36,    37,    48
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      55,    26,    25,    41,   132,   102,   133,    43,    26,    25,
      25,    51,    25,   125,    49,    25,    25,    39,    81,    59,
      25,    88,    66,   -45,    80,    92,     3,     4,     5,    56,
      57,   138,   149,   126,   -19,    11,    12,    79,    64,    95,
     -45,   119,    67,    68,    65,    91,   -18,    78,    15,    98,
     -19,   103,    18,   -45,   -45,    72,    73,   109,   110,   111,
     112,   -45,   -18,    93,    50,    96,   117,   118,    52,   120,
     145,   121,    67,    68,    74,    75,   115,    60,    25,    25,
      25,    25,   106,   107,   108,   124,   142,   134,    38,    43,
      67,    68,    84,   146,    83,    38,   127,   128,    65,    76,
      77,    61,    45,     3,     4,     5,    58,    69,    70,    71,
      62,    82,    11,    12,   143,    63,   103,   153,   121,   133,
      85,   143,   141,   147,   148,    15,    43,    16,    17,    18,
     101,   130,    67,    68,   155,   156,   157,    -7,     1,    86,
       2,     3,     4,     5,     6,    90,     7,     8,     9,    10,
      11,    12,   135,    94,    13,    67,    68,   137,    67,    68,
      14,   104,   105,    15,    99,    16,    17,    18,    45,     3,
       4,     5,   113,   114,   122,   129,   131,   136,    11,    12,
     139,   150,   151,   158,    44,   159,   154,   100,   116,     0,
       0,    15,     0,    16,    17,    18,   144,     2,     3,     4,
       5,     6,     0,     0,     8,     9,    10,    11,    12,     0,
       0,    13,     0,     0,     0,     0,     0,    14,     0,     0,
      15,     0,    16,    17,    18,    45,     3,     4,     5,     0,
      45,     3,     4,     5,     0,    11,    12,     0,     0,    13,
      11,    12,     0,     0,     0,     0,     0,     0,    15,     0,
      16,    17,    18,    15,    53,    16,    17,    18,    45,     3,
       4,     5,     0,    40,     3,     4,     5,     0,    11,    12,
       0,     0,     0,    11,    12,     0,     0,    92,     3,     4,
       5,    15,     0,    16,    17,    18,    15,    11,    12,     0,
      18,   123,     3,     4,     5,     0,   140,     3,     4,     5,
      15,    11,    12,     0,    18,     0,    11,    12,     0,     0,
       0,     0,     0,     0,    15,     0,     0,     0,    18,    15,
       0,     0,     0,    18
};

static const yytype_int16 yycheck[] =
{
      15,     0,     0,     6,    31,    66,    33,     6,     7,     7,
       8,    13,    10,     7,    25,    13,    14,    24,     8,     0,
      18,     7,    30,    30,    39,     3,     4,     5,     6,    16,
      17,     8,     8,    27,     8,    13,    14,    16,    26,    17,
      30,    84,    28,    29,    32,    60,     8,    15,    26,    64,
      24,    66,    30,    30,    30,    18,    19,    72,    73,    74,
      75,    30,    24,    61,    10,    63,    81,    82,    14,    84,
     131,    86,    28,    29,    37,    38,    78,    24,    76,    77,
      78,    79,    69,    70,    71,    88,   129,    25,     0,    88,
      28,    29,    26,   136,    25,     7,    94,    95,    32,    20,
      21,     8,     3,     4,     5,     6,    18,    34,    35,    36,
      17,     8,    13,    14,   129,    22,   131,    31,   133,    33,
      25,   136,   125,   138,   139,    26,   125,    28,    29,    30,
      31,    27,    28,    29,   149,   150,   151,     0,     1,    33,
       3,     4,     5,     6,     7,    31,     9,    10,    11,    12,
      13,    14,    25,     8,    17,    28,    29,    27,    28,    29,
      23,    67,    68,    26,     3,    28,    29,    30,     3,     4,
       5,     6,    76,    77,    27,    25,    30,    25,    13,    14,
       8,     8,    25,    27,     7,    27,   146,    65,    79,    -1,
      -1,    26,    -1,    28,    29,    30,    31,     3,     4,     5,
       6,     7,    -1,    -1,    10,    11,    12,    13,    14,    -1,
      -1,    17,    -1,    -1,    -1,    -1,    -1,    23,    -1,    -1,
      26,    -1,    28,    29,    30,     3,     4,     5,     6,    -1,
       3,     4,     5,     6,    -1,    13,    14,    -1,    -1,    17,
      13,    14,    -1,    -1,    -1,    -1,    -1,    -1,    26,    -1,
      28,    29,    30,    26,    27,    28,    29,    30,     3,     4,
       5,     6,    -1,     3,     4,     5,     6,    -1,    13,    14,
      -1,    -1,    -1,    13,    14,    -1,    -1,     3,     4,     5,
       6,    26,    -1,    28,    29,    30,    26,    13,    14,    -1,
      30,     3,     4,     5,     6,    -1,     3,     4,     5,     6,
      26,    13,    14,    -1,    30,    -1,    13,    14,    -1,    -1,
      -1,    -1,    -1,    -1,    26,    -1,    -1,    -1,    30,    26,
      -1,    -1,    -1,    30
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     3,     4,     5,     6,     7,     9,    10,    11,
      12,    13,    14,    17,    23,    26,    28,    29,    30,    40,
      41,    42,    44,    45,    46,    47,    50,    51,    52,    53,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    24,
       3,    44,    47,    50,    42,     3,    43,    50,    65,    25,
      43,    62,    43,    27,    56,    57,    46,    46,    65,     0,
      24,     8,    17,    22,    26,    32,    30,    28,    29,    34,
      35,    36,    18,    19,    37,    38,    20,    21,    15,    16,
      57,     8,     8,    25,    26,    25,    33,    55,     7,    54,
      31,    57,     3,    47,     8,    17,    47,    49,    57,     3,
      52,    31,    56,    57,    58,    58,    46,    46,    46,    57,
      57,    57,    57,    60,    60,    62,    63,    57,    57,    49,
      57,    57,    27,     3,    44,     7,    27,    47,    47,    25,
      27,    30,    31,    33,    25,    25,    25,    27,     8,     8,
       3,    44,    49,    57,    31,    56,    49,    57,    57,     8,
       8,    25,    48,    31,    48,    57,    57,    57,    27,    27
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    39,    40,    40,    41,    41,    41,    41,    42,    42,
      42,    42,    42,    42,    42,    42,    42,    43,    44,    44,
      45,    45,    46,    46,    46,    47,    47,    47,    47,    47,
      47,    47,    48,    48,    48,    49,    49,    50,    50,    50,
      50,    51,    51,    51,    51,    52,    53,    53,    53,    54,
      54,    54,    54,    55,    55,    56,    56,    57,    57,    57,
      58,    58,    58,    58,    59,    59,    59,    59,    59,    60,
      60,    60,    60,    60,    61,    61,    61,    62,    62,    63,
      63,    64,    64,    65
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     0,     3,     3,
       2,     1,     5,     5,     3,     3,     2,     1,     7,     4,
       1,     1,     2,     2,     1,     1,     1,     1,     1,     1,
       1,     3,     0,     1,     2,     0,     1,     1,     7,     4,
       1,     4,     3,     6,     5,     1,     2,     4,     4,     5,
       5,     4,     4,     0,     1,     1,     3,     3,     3,     1,
       3,     3,     3,     1,     1,     3,     4,     3,     4,     1,
       3,     3,     3,     3,     1,     3,     3,     1,     2,     1,
       3,     1,     3,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 33 "minipy.y" /* yacc.c:1646  */
    {ind.addline((yyvsp[0]));}
#line 1407 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 34 "minipy.y" /* yacc.c:1646  */
    {}
#line 1413 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 36 "minipy.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);(yyval)->space=(yyvsp[-1])->space;}
#line 1419 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 37 "minipy.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);(yyval)->space=0;}
#line 1425 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 38 "minipy.y" /* yacc.c:1646  */
    {(yyval)=new statement(S_TYPE_NOP,0,0);(yyval)->space=(yyvsp[0])->space;}
#line 1431 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 39 "minipy.y" /* yacc.c:1646  */
    {(yyval)=new statement(S_TYPE_NOP,0,0);(yyval)->space=0;
	    (yyval)->varm=&varm;
	  }
#line 1439 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 45 "minipy.y" /* yacc.c:1646  */
    {
				statement *s=new statement(S_TYPE_INSERT,(yyvsp[-2]));
				s->varm=&varm;
				(yyval)= new statement(S_TYPE_ASSIGN,s,(yyvsp[0]));
				}
#line 1449 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 50 "minipy.y" /* yacc.c:1646  */
    { //add method assign combining insert and change
				(yyval)= new statement(S_TYPE_ASSIGN,(yyvsp[-2]),(yyvsp[0]));
				}
#line 1457 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 53 "minipy.y" /* yacc.c:1646  */
    {(yyval)=new statement(S_TYPE_ASSERT,(yyvsp[0]));}
#line 1463 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 54 "minipy.y" /* yacc.c:1646  */
    {
			(yyval)=new statement(S_TYPE_PRINT,(yyvsp[0]));
				}
#line 1471 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 57 "minipy.y" /* yacc.c:1646  */
    {
				statement *s=new statement(S_TYPE_INSERT,(yyvsp[-3]));
				s->varm=&varm;
				statement** l=new statement*[99];
				statement *s1=new statement(S_TYPE_LIST_OF_S,0,l);
				(yyval)= new statement(S_TYPE_FOR,s,(yyvsp[-1]),s1);
				}
#line 1483 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 64 "minipy.y" /* yacc.c:1646  */
    {
				statement** l=new statement*[99];
				statement *s1=new statement(S_TYPE_LIST_OF_S,0,l);
				(yyval)= new statement(S_TYPE_FOR,(yyvsp[-3]),(yyvsp[-1]),s1);
				}
#line 1493 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 69 "minipy.y" /* yacc.c:1646  */
    {
	statement** l=new statement*[99];
	statement *s1=new statement(S_TYPE_LIST_OF_S,0,l);
	(yyval)= new statement(S_TYPE_WHILE,(yyvsp[-1]),s1);
}
#line 1503 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 74 "minipy.y" /* yacc.c:1646  */
    {
statement ** l = new statement*[99];
statement *s1 = new statement(S_TYPE_LIST_OF_S,0,l);
(yyval)=new statement(S_TYPE_IF,(yyvsp[-1]),s1);
}
#line 1513 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 79 "minipy.y" /* yacc.c:1646  */
    {
statement ** l = new statement*[99];
statement *s1 = new statement(S_TYPE_LIST_OF_S,0,l);
(yyval)=new statement(S_TYPE_ELSE,s1);
}
#line 1523 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 85 "minipy.y" /* yacc.c:1646  */
    {
                statement *s=new statement(S_TYPE_BOOLOP,(yyvsp[0]));
                s->varm=&varm;
		(yyval)=new statement(S_TYPE_ASBOOL,s);}
#line 1532 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 91 "minipy.y" /* yacc.c:1646  */
    {
	  (yyval)=new statement(S_TYPE_LEFTSLICE,(yyvsp[-6]),(yyvsp[-4]),(yyvsp[-2]),(yyvsp[-1]));

}
#line 1541 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 95 "minipy.y" /* yacc.c:1646  */
    {
	  (yyval)=new statement(S_TYPE_LEFTAT,(yyvsp[-3]),(yyvsp[-1]));
		}
#line 1549 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 99 "minipy.y" /* yacc.c:1646  */
    {
    (yyval)=(yyvsp[0]);
}
#line 1557 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 102 "minipy.y" /* yacc.c:1646  */
    {
	   (yyval)=(yyvsp[0]);
	   }
#line 1565 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 106 "minipy.y" /* yacc.c:1646  */
    {
	  (yyval)=new statement(S_TYPE_POSOP,(yyvsp[0]));
}
#line 1573 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 109 "minipy.y" /* yacc.c:1646  */
    {
	  (yyval)=new statement(S_TYPE_NEGOP,(yyvsp[0]));
	   }
#line 1581 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 112 "minipy.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1587 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 114 "minipy.y" /* yacc.c:1646  */
    {
	  (yyval)=new statement(S_TYPE_LOAD,(yyvsp[0]));
          (yyval)->varm=&varm;
}
#line 1596 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 118 "minipy.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);
		}
#line 1603 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 121 "minipy.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1609 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 122 "minipy.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1615 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 123 "minipy.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1621 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 124 "minipy.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1627 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 125 "minipy.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[-1]);}
#line 1633 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 129 "minipy.y" /* yacc.c:1646  */
    {(yyval)=new statement(new variable(1));}
#line 1639 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 130 "minipy.y" /* yacc.c:1646  */
    {(yyval)=new statement(new variable(1));}
#line 1645 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 131 "minipy.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1651 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 133 "minipy.y" /* yacc.c:1646  */
    {(yyval)=new statement(new variable());}
#line 1657 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 134 "minipy.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1663 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 136 "minipy.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1669 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 138 "minipy.y" /* yacc.c:1646  */
    {
		(yyval)=new statement(S_TYPE_SLICE,(yyvsp[-6]),(yyvsp[-4]),(yyvsp[-2]),(yyvsp[-1]));
		}
#line 1677 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 141 "minipy.y" /* yacc.c:1646  */
    {
		(yyval)=new statement(S_TYPE_AT,(yyvsp[-3]),(yyvsp[-1]));
		}
#line 1685 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 144 "minipy.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1691 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 147 "minipy.y" /* yacc.c:1646  */
    {
			(yyval)=new statement(S_TYPE_FUNC,(yyvsp[-3]),(yyvsp[-1]));
}
#line 1699 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 150 "minipy.y" /* yacc.c:1646  */
    {
				statement *s=new statement(S_TYPE_CREATE_LIST,0,0);
				(yyval)=new statement(S_TYPE_FUNC,(yyvsp[-2]),s);
		}
#line 1708 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 154 "minipy.y" /* yacc.c:1646  */
    {
			(yyval)=new statement(S_TYPE_OBJFUNC,(yyvsp[-5]),(yyvsp[-3]),(yyvsp[-1]));
		}
#line 1716 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 157 "minipy.y" /* yacc.c:1646  */
    {
			statement *s=new statement(S_TYPE_CREATE_LIST,0,0);
			(yyval)=new statement(S_TYPE_OBJFUNC,(yyvsp[-4]),(yyvsp[-2]),s);
		}
#line 1725 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 163 "minipy.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1731 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 165 "minipy.y" /* yacc.c:1646  */
    {
			(yyval)=new statement(S_TYPE_CREATE_LIST,0,0);
				}
#line 1739 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 168 "minipy.y" /* yacc.c:1646  */
    {
			(yyval)=(yyvsp[-2]);
	  }
#line 1747 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 171 "minipy.y" /* yacc.c:1646  */
    {
	(yyval)=new statement(S_TYPE_LISTFOR,(yyvsp[-2]),(yyvsp[-1]));

}
#line 1756 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 176 "minipy.y" /* yacc.c:1646  */
    {
	(yyval)=(yyvsp[-4]);
	statement *s=new statement(S_TYPE_INSERT,(yyvsp[-2]));
	s->varm=&varm;
	statement **l=new statement*[99];
	(yyval)->append(new statement(S_TYPE_FOR,s,(yyvsp[0]),0));
}
#line 1768 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 183 "minipy.y" /* yacc.c:1646  */
    {
	(yyval)=(yyvsp[-4]);
	statement **l=new statement*[99];
	(yyval)->append(new statement(S_TYPE_FOR,(yyvsp[-2]),(yyvsp[0]),0));
	
}
#line 1779 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 189 "minipy.y" /* yacc.c:1646  */
    {
	statement *s=new statement(S_TYPE_INSERT,(yyvsp[-2]));
	s->varm=&varm;
	statement **l=new statement*[99];
	(yyval)=new statement(S_TYPE_LIST_OF_S,0,l);
	(yyval)->append(new statement(S_TYPE_FOR,s,(yyvsp[0]),0));
}
#line 1791 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 196 "minipy.y" /* yacc.c:1646  */
    {
	statement **l=new statement*[99];
	(yyval)=new statement(S_TYPE_LIST_OF_S,0,l);
	(yyval)->append(new statement(S_TYPE_FOR,(yyvsp[-2]),(yyvsp[0]),0));
}
#line 1801 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 203 "minipy.y" /* yacc.c:1646  */
    {}
#line 1807 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 204 "minipy.y" /* yacc.c:1646  */
    {}
#line 1813 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 207 "minipy.y" /* yacc.c:1646  */
    {
		statement*s=new statement(S_TYPE_CREATE_LIST,0,0);
		(yyval)=new statement(S_TYPE_LISTAPPEND,s,(yyvsp[0]));
	
	  }
#line 1823 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 212 "minipy.y" /* yacc.c:1646  */
    {
			(yyval)=new statement(S_TYPE_LISTAPPEND,(yyvsp[-2]),(yyvsp[0]));
	  }
#line 1831 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 216 "minipy.y" /* yacc.c:1646  */
    {//Ìí¼Óadd
			(yyval)=new statement(S_TYPE_ADD,(yyvsp[-2]),(yyvsp[0]));
			}
#line 1839 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 219 "minipy.y" /* yacc.c:1646  */
    {//Ìí¼Ósub
			(yyval)=new statement(S_TYPE_SUB,(yyvsp[-2]),(yyvsp[0]));
		  }
#line 1847 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 222 "minipy.y" /* yacc.c:1646  */
    {
		    (yyval)=(yyvsp[0]);
		  }
#line 1855 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 228 "minipy.y" /* yacc.c:1646  */
    { //add method mul
			(yyval)=new statement(S_TYPE_MUL,(yyvsp[-2]),(yyvsp[0]));
		}
#line 1863 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 231 "minipy.y" /* yacc.c:1646  */
    {//add method div
			(yyval)=new statement(S_TYPE_DIV,(yyvsp[-2]),(yyvsp[0]));
		}
#line 1871 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 234 "minipy.y" /* yacc.c:1646  */
    {//add method mod
			(yyval)=new statement(S_TYPE_MOD,(yyvsp[-2]),(yyvsp[0]));
		  }
#line 1879 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 237 "minipy.y" /* yacc.c:1646  */
    {
		(yyval)=(yyvsp[0]);
		}
#line 1887 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 242 "minipy.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1893 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 243 "minipy.y" /* yacc.c:1646  */
    {(yyval)=new statement(S_TYPE_OBJIS,(yyvsp[-2]),(yyvsp[0]));}
#line 1899 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 244 "minipy.y" /* yacc.c:1646  */
    {(yyval)=new statement(S_TYPE_OBJNOT,(yyvsp[-3]),(yyvsp[0]));}
#line 1905 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 245 "minipy.y" /* yacc.c:1646  */
    {(yyval)=new statement(S_TYPE_OBJIN,(yyvsp[-2]),(yyvsp[0]));}
#line 1911 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 246 "minipy.y" /* yacc.c:1646  */
    {(yyval)=new statement(S_TYPE_OBJNOTIN,(yyvsp[-3]),(yyvsp[0]));}
#line 1917 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 248 "minipy.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1923 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 249 "minipy.y" /* yacc.c:1646  */
    {
			(yyval)=new statement(S_TYPE_G,(yyvsp[-2]),(yyvsp[0]));
		}
#line 1931 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 252 "minipy.y" /* yacc.c:1646  */
    {
			(yyval)=new statement(S_TYPE_L,(yyvsp[-2]),(yyvsp[0]));
		}
#line 1939 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 255 "minipy.y" /* yacc.c:1646  */
    {
			(yyval)=new statement(S_TYPE_LE,(yyvsp[-2]),(yyvsp[0]));
		}
#line 1947 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 258 "minipy.y" /* yacc.c:1646  */
    {
			(yyval)=new statement(S_TYPE_GE,(yyvsp[-2]),(yyvsp[0]));
		}
#line 1955 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 262 "minipy.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1961 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 263 "minipy.y" /* yacc.c:1646  */
    {
			(yyval)=new statement(S_TYPE_EQ,(yyvsp[-2]),(yyvsp[0]));
		}
#line 1969 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 266 "minipy.y" /* yacc.c:1646  */
    {
			(yyval)=new statement(S_TYPE_NE,(yyvsp[-2]),(yyvsp[0]));
		}
#line 1977 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 270 "minipy.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1983 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 271 "minipy.y" /* yacc.c:1646  */
    {(yyval)=new statement(S_TYPE_NOT,(yyvsp[0]));}
#line 1989 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 273 "minipy.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1995 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 274 "minipy.y" /* yacc.c:1646  */
    {
			(yyval)=new statement(S_TYPE_AND,(yyvsp[-2]),(yyvsp[0]));
		}
#line 2003 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 278 "minipy.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 2009 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 279 "minipy.y" /* yacc.c:1646  */
    {
			(yyval)=new statement(S_TYPE_OR,(yyvsp[-2]),(yyvsp[0]));
		}
#line 2017 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 283 "minipy.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 2023 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2027 "y.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 286 "minipy.y" /* yacc.c:1906  */


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
