/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "yacc.y" /* yacc.c:339  */

	#include <stdio.h>
	#include <string.h>

	#include "sefasgen.h"

	//extern int yylex();
	//extern int yyparse();
	//extern FILE* yyin;

	//void yyerror(const char* msg);

	tDato tempTipoDato, tipoTemp, tipoAux;
	int estado;
	unsigned int flag = 0;

	char *etqTemp;

	int nParam = 0;
	int contParam;
	int totalParam;
	unsigned char tipoOK;
	int tamCadena;

	int linea_actual = 1;


#line 94 "y.tab.c" /* yacc.c:339  */

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
# define YYERROR_VERBOSE 1
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
    INICIOVARS = 258,
    FINVARS = 259,
    PUNTOCOMA = 260,
    MAIN = 261,
    PROCED = 262,
    ABRIRCORCH = 263,
    CERRARCORCH = 264,
    ABRIRPARENT = 265,
    CERRARPARENT = 266,
    ABRIRLLAVES = 267,
    CERRARLLAVES = 268,
    DEFLIST = 269,
    ASIG = 270,
    CONDSI = 271,
    CONDMIENTRAS = 272,
    CONDSINO = 273,
    LEE = 274,
    ESCRIBE = 275,
    COMA = 276,
    MASMAS = 277,
    MASMENOS = 278,
    DURANTE = 279,
    DOSPUNTOSIGUAL = 280,
    HASTA = 281,
    HACER = 282,
    TIPO = 283,
    VERDFALS = 284,
    T_CARACTER = 285,
    T_CADENA = 286,
    IDENTIFICADOR = 287,
    T_ENTERO = 288,
    T_REAL = 289,
    LOGOR = 290,
    LOGAND = 291,
    ORBIT = 292,
    EXOR = 293,
    ANDBIT = 294,
    IGUALDAD = 295,
    REL = 296,
    MULTIDIV = 297,
    PORCENTAJE = 298,
    UNARIOSLISTA = 299,
    EXCLAMACION = 300,
    MENOSMENOS = 301,
    MULMUL = 302,
    AVANRETRO = 303,
    ARROBA = 304
  };
#endif
/* Tokens.  */
#define INICIOVARS 258
#define FINVARS 259
#define PUNTOCOMA 260
#define MAIN 261
#define PROCED 262
#define ABRIRCORCH 263
#define CERRARCORCH 264
#define ABRIRPARENT 265
#define CERRARPARENT 266
#define ABRIRLLAVES 267
#define CERRARLLAVES 268
#define DEFLIST 269
#define ASIG 270
#define CONDSI 271
#define CONDMIENTRAS 272
#define CONDSINO 273
#define LEE 274
#define ESCRIBE 275
#define COMA 276
#define MASMAS 277
#define MASMENOS 278
#define DURANTE 279
#define DOSPUNTOSIGUAL 280
#define HASTA 281
#define HACER 282
#define TIPO 283
#define VERDFALS 284
#define T_CARACTER 285
#define T_CADENA 286
#define IDENTIFICADOR 287
#define T_ENTERO 288
#define T_REAL 289
#define LOGOR 290
#define LOGAND 291
#define ORBIT 292
#define EXOR 293
#define ANDBIT 294
#define IGUALDAD 295
#define REL 296
#define MULTIDIV 297
#define PORCENTAJE 298
#define UNARIOSLISTA 299
#define EXCLAMACION 300
#define MENOSMENOS 301
#define MULMUL 302
#define AVANRETRO 303
#define ARROBA 304

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

#line 243 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   437

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  50
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  51
/* YYNRULES -- Number of rules.  */
#define YYNRULES  106
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  184

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   304

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    87,    87,    87,    91,    90,   110,   113,   116,   117,
     119,   120,   123,   129,   139,   138,   150,   151,   153,   154,
     156,   160,   170,   171,   173,   174,   176,   176,   177,   178,
     180,   189,   200,   200,   201,   203,   204,   208,   209,   210,
     211,   212,   213,   214,   215,   218,   250,   251,   253,   256,
     260,   255,   266,   268,   269,   272,   273,   275,   275,   303,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   391,   392,
     393,   394,   395,   396,   397,   398,   399,   400,   402,   432,
     449,   455,   456,   457,   458,   461,   463,   464,   467,   469,
     470,   474,   476,   477,   480,   482,   483
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INICIOVARS", "FINVARS", "PUNTOCOMA",
  "MAIN", "PROCED", "ABRIRCORCH", "CERRARCORCH", "ABRIRPARENT",
  "CERRARPARENT", "ABRIRLLAVES", "CERRARLLAVES", "DEFLIST", "ASIG",
  "CONDSI", "CONDMIENTRAS", "CONDSINO", "LEE", "ESCRIBE", "COMA", "MASMAS",
  "MASMENOS", "DURANTE", "DOSPUNTOSIGUAL", "HASTA", "HACER", "TIPO",
  "VERDFALS", "T_CARACTER", "T_CADENA", "IDENTIFICADOR", "T_ENTERO",
  "T_REAL", "LOGOR", "LOGAND", "ORBIT", "EXOR", "ANDBIT", "IGUALDAD",
  "REL", "MULTIDIV", "PORCENTAJE", "UNARIOSLISTA", "EXCLAMACION",
  "MENOSMENOS", "MULMUL", "AVANRETRO", "ARROBA", "$accept", "Programa",
  "$@1", "bloque", "$@2", "Declar_de_variables_locales",
  "Marca_ini_declar_variables", "Marca_fin_declar_variables",
  "Declar_de_subprogs", "Declar_subprog", "Cabecera_programa",
  "Cabecera_subprograma", "$@3", "error_subprog", "parametros",
  "parametro", "Inicio_de_bloque", "Fin_de_bloque", "Variables_locales",
  "Cuerpo_declar_variables", "$@4", "error_decl_variables",
  "Identificadores", "tipo", "tipo_lista", "Sentencias", "Sentencia",
  "sentencia_asignacion", "sentencia_if", "sentencia_while",
  "sentencia_entrada", "$@5", "$@6", "sentencia_salida", "expcad",
  "lista_expresiones_o_cadena", "llamada_proced", "$@7", "sentencia_for",
  "expresion", "error_expresion", "lista_expresiones", "lista",
  "lista_enteros", "Enteros", "lista_reales", "Reales", "lista_booleanos",
  "Booleanos", "lista_caracteres", "Caracteres", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304
};
# endif

#define YYPACT_NINF -125

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-125)))

#define YYTABLE_NINF -91

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      50,    72,    80,  -125,    71,  -125,    70,    78,  -125,  -125,
    -125,  -125,   108,  -125,  -125,    23,   387,  -125,    88,  -125,
       8,  -125,  -125,  -125,  -125,     3,   102,   109,  -125,    69,
      58,   114,  -125,  -125,    70,   396,  -125,  -125,  -125,  -125,
    -125,  -125,  -125,  -125,  -125,   129,  -125,  -125,   101,  -125,
    -125,  -125,   120,   120,   101,  -125,   128,   120,   120,   120,
    -125,  -125,     9,  -125,  -125,  -125,   120,   120,   120,  -125,
      24,   294,  -125,  -125,  -125,  -125,  -125,  -125,   110,   120,
     126,  -125,  -125,  -125,  -125,  -125,  -125,    67,   127,  -125,
     156,   178,   118,  -125,  -125,  -125,  -125,    25,    65,    74,
      87,   200,    28,    28,    28,    28,    28,  -125,    69,   120,
     120,   120,   120,   120,   120,   120,   120,   120,   120,   120,
     120,  -125,   120,   133,    10,  -125,   112,    -9,   405,   405,
     136,  -125,   113,  -125,   111,  -125,   119,  -125,   130,  -125,
    -125,   222,     5,   316,   328,    84,   338,   350,   186,    62,
      28,    28,   -22,   250,  -125,   294,     2,  -125,    76,  -125,
     131,   141,  -125,  -125,  -125,  -125,  -125,  -125,   120,   120,
     172,   120,  -125,    -9,  -125,   405,  -125,   272,  -125,   294,
    -125,  -125,   405,  -125
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     2,     0,     1,     0,     0,    22,     3,
       4,    13,     7,     8,    11,     0,     0,    29,     0,    32,
       0,    25,    28,    26,    33,     0,     0,     0,    49,     0,
       0,    57,    37,    10,     0,     0,    36,    38,    39,    40,
      41,    42,    43,    44,    34,     0,     6,    24,     0,    17,
      14,    16,     0,     0,     0,    87,     0,     0,     0,     0,
      84,    83,    82,    79,    80,    81,     0,     0,     0,    55,
       0,    53,    86,    85,    91,    92,    93,    94,     0,     0,
       0,    12,    23,     5,    35,     9,    30,     0,     0,    82,
       0,     0,    50,   102,   105,    96,    99,     0,     0,     0,
       0,     0,    63,    61,    62,    65,    64,    52,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    66,     0,     0,     0,    27,     0,    20,     0,     0,
       0,    95,     0,    98,     0,   101,     0,   104,     0,    60,
      56,     0,    77,    72,    69,    71,    70,    76,    74,    73,
      68,    75,    67,     0,    45,    89,     0,    31,     0,    18,
       0,    46,    48,    51,    97,   100,   103,   106,     0,     0,
       0,     0,    15,     0,    21,     0,    78,     0,    58,    88,
      19,    47,     0,    59
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -125,  -125,  -125,     4,  -125,  -125,  -125,  -125,  -125,  -125,
    -125,  -125,  -125,  -125,  -125,    11,  -125,  -125,  -125,   162,
    -125,  -125,   132,  -124,  -125,  -125,   -35,  -125,  -125,  -125,
    -125,  -125,  -125,  -125,    75,  -125,  -125,  -125,  -125,   -51,
    -125,  -125,  -125,  -125,  -125,  -125,  -125,  -125,  -125,  -125,
    -125
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     6,    32,    12,    14,    15,    46,    16,    33,
       3,    34,    88,    51,   158,   159,    10,    83,    20,    21,
      48,    22,    87,    23,    24,    35,    36,    37,    38,    39,
      40,    54,   130,    41,    69,    70,    42,    80,    43,    71,
      72,   156,    73,    74,    97,    75,    98,    76,    99,    77,
     100
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      84,    90,    91,   160,    49,    18,   101,   102,   103,    17,
       9,    55,    45,   170,   -54,   104,   105,   106,    56,    19,
      57,   -90,    18,   171,    17,   120,   121,   109,   123,   107,
     -54,   -90,    58,    59,   131,    50,    19,    18,    81,    60,
      61,    89,    63,    64,    65,   108,   132,   118,   119,   160,
     109,    19,   120,   121,    66,    67,    68,     1,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
      55,   153,   125,   155,   133,   120,   121,    56,     4,    57,
       5,     7,     8,   135,   109,   110,   134,   172,   126,    11,
      78,    58,    59,   161,   162,   136,   137,   173,    60,    61,
      62,    63,    64,    65,   118,   119,   109,   110,   138,   120,
     121,    13,    52,    66,    67,    68,    44,   176,   177,    53,
     179,    55,   114,   115,   116,   117,   118,   119,    56,    79,
      57,   120,   121,    86,    85,   122,   124,   127,   154,   126,
     181,   163,    58,    59,   157,   165,   164,   183,   166,    60,
      61,    89,    63,    64,    65,   109,   110,    93,    94,   175,
     167,    95,    96,   174,    66,    67,    68,   128,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   178,   109,   110,
     120,   121,    47,   140,   180,     0,    92,     0,     0,   129,
       0,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     109,   110,     0,   120,   121,     0,     0,     0,   109,   110,
       0,   139,     0,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   109,   110,     0,   120,   121,   117,   118,   119,
       0,     0,     0,   120,   121,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   109,   110,     0,   120,   121,     0,
       0,     0,     0,     0,     0,     0,     0,   111,   112,   113,
     114,   115,   116,   117,   118,   119,     0,     0,     0,   120,
     121,   168,   109,   110,     0,     0,   169,     0,     0,     0,
       0,     0,     0,     0,     0,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   109,   110,     0,   120,   121,   182,
       0,     0,     0,     0,     0,     0,     0,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   109,   110,     0,   120,
     121,     0,     0,     0,     0,     0,     0,     0,     0,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   109,   110,
       0,   120,   121,     0,     0,     0,     0,     0,     0,     0,
     109,   110,   112,   113,   114,   115,   116,   117,   118,   119,
     109,   110,     0,   120,   121,   113,   114,   115,   116,   117,
     118,   119,   109,   110,     0,   120,   121,   115,   116,   117,
     118,   119,     0,     0,     0,   120,   121,     0,     0,     0,
     116,   117,   118,   119,    25,     0,     0,   120,   121,     8,
       0,     0,     0,    26,    27,     0,    28,    29,     8,    82,
       0,    30,    26,    27,     0,    28,    29,     8,     0,    31,
      30,    26,    27,     0,    28,    29,     0,     0,    31,    30,
       0,     0,     0,     0,     0,     0,     0,    31
};

static const yytype_int16 yycheck[] =
{
      35,    52,    53,   127,     1,    14,    57,    58,    59,     1,
       6,     1,     4,    11,     5,    66,    67,    68,     8,    28,
      10,    11,    14,    21,     1,    47,    48,    22,    79,     5,
      21,    21,    22,    23,     9,    32,    28,    14,    34,    29,
      30,    31,    32,    33,    34,    21,    21,    42,    43,   173,
      22,    28,    47,    48,    44,    45,    46,     7,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
       1,   122,     5,   124,     9,    47,    48,     8,     6,    10,
       0,    10,    12,     9,    22,    23,    21,    11,    21,    11,
      32,    22,    23,   128,   129,    21,     9,    21,    29,    30,
      31,    32,    33,    34,    42,    43,    22,    23,    21,    47,
      48,     3,    10,    44,    45,    46,    28,   168,   169,    10,
     171,     1,    38,    39,    40,    41,    42,    43,     8,    15,
      10,    47,    48,    32,     5,    25,    10,    10,     5,    21,
     175,     5,    22,    23,    32,    34,    33,   182,    29,    29,
      30,    31,    32,    33,    34,    22,    23,    29,    30,    18,
      30,    33,    34,    32,    44,    45,    46,    11,    35,    36,
      37,    38,    39,    40,    41,    42,    43,     5,    22,    23,
      47,    48,    20,   108,   173,    -1,    54,    -1,    -1,    11,
      -1,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      22,    23,    -1,    47,    48,    -1,    -1,    -1,    22,    23,
      -1,    11,    -1,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    22,    23,    -1,    47,    48,    41,    42,    43,
      -1,    -1,    -1,    47,    48,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    22,    23,    -1,    47,    48,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    -1,    -1,    -1,    47,
      48,    49,    22,    23,    -1,    -1,    26,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    22,    23,    -1,    47,    48,    27,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    22,    23,    -1,    47,
      48,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    22,    23,
      -1,    47,    48,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      22,    23,    36,    37,    38,    39,    40,    41,    42,    43,
      22,    23,    -1,    47,    48,    37,    38,    39,    40,    41,
      42,    43,    22,    23,    -1,    47,    48,    39,    40,    41,
      42,    43,    -1,    -1,    -1,    47,    48,    -1,    -1,    -1,
      40,    41,    42,    43,     7,    -1,    -1,    47,    48,    12,
      -1,    -1,    -1,    16,    17,    -1,    19,    20,    12,    13,
      -1,    24,    16,    17,    -1,    19,    20,    12,    -1,    32,
      24,    16,    17,    -1,    19,    20,    -1,    -1,    32,    24,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    32
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     7,    51,    60,     6,     0,    52,    10,    12,    53,
      66,    11,    54,     3,    55,    56,    58,     1,    14,    28,
      68,    69,    71,    73,    74,     7,    16,    17,    19,    20,
      24,    32,    53,    59,    61,    75,    76,    77,    78,    79,
      80,    83,    86,    88,    28,     4,    57,    69,    70,     1,
      32,    63,    10,    10,    81,     1,     8,    10,    22,    23,
      29,    30,    31,    32,    33,    34,    44,    45,    46,    84,
      85,    89,    90,    92,    93,    95,    97,    99,    32,    15,
      87,    53,    13,    67,    76,     5,    32,    72,    62,    31,
      89,    89,    72,    29,    30,    33,    34,    94,    96,    98,
     100,    89,    89,    89,    89,    89,    89,     5,    21,    22,
      23,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      47,    48,    25,    89,    10,     5,    21,    10,    11,    11,
      82,     9,    21,     9,    21,     9,    21,     9,    21,    11,
      84,    89,    89,    89,    89,    89,    89,    89,    89,    89,
      89,    89,    89,    89,     5,    89,    91,    32,    64,    65,
      73,    76,    76,     5,    33,    34,    29,    30,    49,    26,
      11,    21,    11,    21,    32,    18,    89,    89,     5,    89,
      65,    76,    27,    76
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    50,    52,    51,    54,    53,    55,    55,    56,    57,
      58,    58,    59,    60,    62,    61,    61,    63,    64,    64,
      64,    65,    66,    67,    68,    68,    70,    69,    69,    71,
      72,    72,    73,    73,    74,    75,    75,    76,    76,    76,
      76,    76,    76,    76,    76,    77,    78,    78,    79,    81,
      82,    80,    83,    84,    84,    85,    85,    87,    86,    88,
      89,    89,    89,    89,    89,    89,    89,    89,    89,    89,
      89,    89,    89,    89,    89,    89,    89,    89,    89,    89,
      89,    89,    89,    89,    89,    89,    89,    90,    91,    91,
      91,    92,    92,    92,    92,    93,    94,    94,    95,    96,
      96,    97,    98,    98,    99,   100,   100
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     3,     0,     6,     3,     0,     1,     2,
       2,     0,     2,     4,     0,     6,     2,     1,     1,     3,
       0,     2,     1,     1,     2,     1,     0,     4,     1,     1,
       1,     3,     1,     1,     2,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     4,     5,     7,     5,     0,
       0,     5,     3,     1,     1,     1,     3,     0,     6,     8,
       3,     2,     2,     2,     2,     2,     2,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     5,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     1,
       0,     1,     1,     1,     1,     3,     1,     3,     3,     1,
       3,     3,     1,     3,     3,     1,     3
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
#line 87 "yacc.y" /* yacc.c:1646  */
    { pet_GenIni(); }
#line 1517 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 91 "yacc.y" /* yacc.c:1646  */
    {
	yylval.lexema = strdup("INIBLOQUE");
	yylval.tipoDato = NO_ASIG;
	pet_introTS(yylval, MARCA);

	//pet_GenIniBlq(NULL, $1.colIni, $1.colFin);
	}
#line 1529 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 102 "yacc.y" /* yacc.c:1646  */
    {
	pet_SacarTS();

	//pet_GenFinBlq();
	}
#line 1539 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 124 "yacc.y" /* yacc.c:1646  */
    {
		pet_GenFinDecProc();
		}
#line 1547 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 130 "yacc.y" /* yacc.c:1646  */
    {
(yyvsp[-2]).tipoDato = NO_ASIG;
pet_introTS((yyvsp[-2]), PROC);
}
#line 1556 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 139 "yacc.y" /* yacc.c:1646  */
    {
	 (yyvsp[0]).tipoDato = NO_ASIG;

	 estado = pet_introTS((yyvsp[0]), PROC);
	if ( estado )
		pet_GenDecProc((yyvsp[0]).lexema, NO_ASIG);
	}
#line 1568 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 147 "yacc.y" /* yacc.c:1646  */
    {
 	pet_GenFinCabecera();
 }
#line 1576 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 156 "yacc.y" /* yacc.c:1646  */
    {
	pet_GenParam(NO_ASIG, NULL);
	}
#line 1584 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 161 "yacc.y" /* yacc.c:1646  */
    {
	(yyvsp[0]).tipoDato = (yyvsp[-1]).tipoDato;
	estado = pet_introTS((yyvsp[0]), PAR_FORMAL);

	if ( estado )
		pet_GenParam((yyvsp[-1]).tipoDato, (yyvsp[0]).lexema);
	}
#line 1596 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 176 "yacc.y" /* yacc.c:1646  */
    {tempTipoDato = (yyvsp[0]).tipoDato;}
#line 1602 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 181 "yacc.y" /* yacc.c:1646  */
    {
			(yyvsp[0]).tipoDato = tempTipoDato;
			estado = pet_introTS((yyvsp[0]), VARIABLE);

		if ( estado ) {
			pet_GenDecVar((yyvsp[0]).tipoDato, (yyvsp[0]).lexema);
			}
		}
#line 1615 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 190 "yacc.y" /* yacc.c:1646  */
    {
		(yyvsp[0]).tipoDato = tempTipoDato;
		estado = pet_introTS((yyvsp[0]), VARIABLE);

		if ( estado ) {
			pet_GenDecVar((yyvsp[0]).tipoDato, (yyvsp[0]).lexema);
			}
		}
#line 1628 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 219 "yacc.y" /* yacc.c:1646  */
    {

tipoTemp = pet_BuscarTS((yyvsp[-3]));
(yyvsp[-3]).tipoDato = tipoTemp;
estado = pet_VerifTIPO((yyvsp[-3]), (yyvsp[-1]));


if ( tipoTemp != (yyvsp[-1]).tipoDato ) {
	fprintf(stderr, "[ERR] Error linea: %d ASIGNACION "
		, yylineno);
	fprintf(stderr, "tipos no coinciden\n");
	// impTipo(tipoTemp);
	// printf(" y ");
	// impTipo($4.tipoDato);
	// printf("\n");
	}


fprintf(stderr, "[COMP] Misma comprobacion tipo ");
fprintf(stderr, "segun PADRE: %s\n", (estado == 1)?"OK":"ERR");

pet_GenIniBlq("/** Asignacion **/\n", (yyvsp[-3]).colIni, (yyvsp[-1]).colFin);

// Peticion de ASIGNACION

pet_GenAsig(2, (yyvsp[-3]).lexema, (yyvsp[-1]).nomTemp, NULL, NULL);

pet_GenFinBlq();
}
#line 1662 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 256 "yacc.y" /* yacc.c:1646  */
    {
pet_GenIniBlq("/** Sent ENTRADA **/\n", (yyvsp[0]).colIni, (yyvsp[0]).colFin);
}
#line 1670 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 260 "yacc.y" /* yacc.c:1646  */
    {
pet_GenENTRADA((yyvsp[0]).formato, (yyvsp[0]).variables);

pet_GenFinBlq();
}
#line 1680 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 275 "yacc.y" /* yacc.c:1646  */
    {
(yyvsp[0]).nParam = pet_BuscarPROC((yyvsp[0]));
contParam = 0;
if ( (yyvsp[0]).nParam < 0 )
	fprintf(stderr, "[ERR] Proc no declarado: %s\n", (yyvsp[0]).lexema);
else {
	// Usamos
	(yyvsp[0]).tipoDato = NO_ASIG;
	pet_GenIniBlq("/** Llamada a PROC **/\n"
		, (yyvsp[0]).colIni, (yyvsp[0]).colFin);
	}
}
#line 1697 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 287 "yacc.y" /* yacc.c:1646  */
    {
if ( contParam != (yyvsp[-5]).nParam && (yyvsp[-5]).nParam >= 0 ) {
	fprintf(stderr, "[ERR] Linea %d Num parametros no concuerda\n", yylineno);
	fprintf(stderr, "[ERR] Declarados: %d  Usados: %d\n",(yyvsp[-5]).nParam, contParam);
} else if ( (yyvsp[-2]).tipoDato != NO_ASIG ) {
	fprintf(stderr, "[ERR] Linea %d Llamada a PROC incorrecta\n", yylineno);
} else {
	// Llamada CORRECTA
	pet_GenLlamada((yyvsp[-5]).lexema, (yyvsp[-2]).variables);
	// TODO: Liberar MEMORIA
	free((yyvsp[-2]).variables);
	}
pet_GenFinBlq();
}
#line 1716 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 323 "yacc.y" /* yacc.c:1646  */
    {
	/**********************************************
	  COMPROBACION DE TIPOS

	  NO SE PIDE LA ASIGNACION DE VALORES !!!!!!!
	  OP_ARIT12 = "+", "-"
	 **********************************************/

	if ( (yyvsp[-2]).tipoDato == (yyvsp[0]).tipoDato ) {
		/**************************************************
		  La suma/resta se puede hacer para cualquier tipo
		  EXCEPTO para booleanos
		 **************************************************/

		if ( ((yyvsp[-2]).tipoDato != BOOLEANO)
			&& ((yyvsp[-2]).tipoDato != LISTA_BOOLEANO) ) {

			(yyval).tipoDato = (yyvsp[-2]).tipoDato;

			/* Hay que definir las operaciones para listas 	*/
			/* $2.nParam define la operacion		*/
			/* 1 = Suma, 2 = Resta				*/

			//  operar(&($$), $1, $3, $2.nParam);

		} else {

			fprintf(stderr, "ERROR linea: %d ", yylineno);
			fprintf(stderr, "Op +/- con tipo de dato");
			fprintf(stderr, "incorrecto");

			(yyval).tipoDato = DESC;
			}
	} else {

		fprintf(stderr, "ERROR linea: %d OP_A12 ", yylineno);
		fprintf(stderr, "Tipos no coinciden ");
		(yyval).tipoDato = DESC;
		}

	/******************************************
	  Asignacion variables de localizacion
	  TODO: Verificacion TIPO por OPERADOR !!!
	 ******************************************/

	estado = pet_VerifTIPO((yyvsp[-2]), (yyvsp[0]));

	(yyval).linIni = (yyvsp[-2]).linIni;
	(yyval).colIni = (yyvsp[-2]).colIni;
	(yyval).linFin = (yyvsp[0]).linFin;
	(yyval).colFin = (yyvsp[0]).colFin;

	(yyval).nomTemp = pet_GenTemp();

	if ( estado ) {
		(yyval).tipoDato = (yyvsp[-2]).tipoDato;
		pet_GenDecVar((yyval).tipoDato, (yyval).nomTemp);

		fprintf(stderr, "ASIG %s = %s %s %s\n"
			, (yyval).nomTemp, (yyvsp[-2]).nomTemp
			, (yyvsp[-1]).lexema, (yyvsp[0]).nomTemp);

		pet_GenAsig(4, (yyval).nomTemp, (yyvsp[-2]).nomTemp
			, (yyvsp[-1]).lexema, (yyvsp[0]).nomTemp);
	} else {
		(yyval).tipoDato = DESC;
		}
	}
#line 1789 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 403 "yacc.y" /* yacc.c:1646  */
    {
fprintf(stderr, "[COMP] Argumentos R1\n");
tipoOK = pet_BuscarPARAM((yyvsp[0]));
contParam++;

if ( tipoOK && (yyvsp[-2]).tipoDato == NO_ASIG ) {
	(yyval).tipoDato = NO_ASIG;
	tamCadena = strlen((yyvsp[-2]).variables)
		+ 2 + strlen((yyvsp[0]).nomTemp) + 1;

	(yyval).variables = (char *) malloc(tamCadena * sizeof(char));
	if ( (yyval).variables == NULL ) {
		perror("LISTA_EXP");
		(yyval).tipoDato = DESC;
	} else {
		strcpy((yyval).variables, (yyvsp[-2]).variables);
		strcat((yyval).variables, ", ");
		strcat((yyval).variables, (yyvsp[0]).nomTemp);
		fprintf(stderr, "DEBUG ListaEXP %s\n"
			, (yyval).variables);

		// Deberiamos poder liberar memoria !!!
		free((yyvsp[0]).nomTemp);
		free((yyvsp[-2]).variables);
		}
} else {
	(yyval).tipoDato = DESC;
	}
}
#line 1823 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 433 "yacc.y" /* yacc.c:1646  */
    {
 fprintf(stderr, "[COMP] Argumentos R2\n");
 tipoOK = pet_BuscarPARAM((yyvsp[0]));
 contParam++;
 if ( tipoOK ) {
 	(yyval).tipoDato = NO_ASIG;
 	// Crear la lista de expresiones...
 	(yyval).variables = strdup((yyvsp[0]).nomTemp);
 	fprintf(stderr, "DEBUG ListaExp %s\n", (yyvsp[0]).nomTemp);
 	// Deberiamos poder liberar la memoria
 	// de nomTemp ???? y toda la demas...
 	free((yyvsp[0]).nomTemp);
 } else
 	(yyval).tipoDato = DESC;
 }
#line 1843 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 449 "yacc.y" /* yacc.c:1646  */
    {
 (yyval).tipoDato = NO_ASIG;
 (yyval).variables = strdup("<< SIN_ARGUMENTOS >>");
 }
#line 1852 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1856 "y.tab.c" /* yacc.c:1646  */
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
#line 487 "yacc.y" /* yacc.c:1906  */

#include "lex.yy.c"
#include "sefasgen.h"


void yyerror(const char *msg)
{
	fprintf(stderr,"[Linea %d]: %s\n", linea_actual,msg);
}

#include "main.c"
