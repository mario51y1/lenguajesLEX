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
#line 1 "yacc.y" /* yacc.c:339  */

	#include <stdio.h>
	#include <string.h>

	#include "ts.h"

	//extern int yylex();
	//extern int yyparse();
	//extern FILE* yyin;

	//void yyerror(const char* msg);

	dtipo tempTipoDato, tipoTemp, tipoAux;
	int estado;
	unsigned int flag = 0;

	char *etqTemp;

	int nParam = 0;
	int contParam;
	int totalParam;
	unsigned char tipoOK;
	int tamCadena;
	int posicion;
	int contExp = 0;

	int linea_actual = 1;


#line 96 "y.tab.c" /* yacc.c:339  */

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
    ARROBA = 290,
    LOGOR = 291,
    LOGAND = 292,
    ORBIT = 293,
    EXOR = 294,
    ANDBIT = 295,
    IGUALDAD = 296,
    REL = 297,
    MULTIDIV = 298,
    PORCENTAJE = 299,
    UNARIOSLISTA = 300,
    EXCLAMACION = 301,
    MENOSMENOS = 302,
    MULMUL = 303,
    AVANRETRO = 304
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
#define ARROBA 290
#define LOGOR 291
#define LOGAND 292
#define ORBIT 293
#define EXOR 294
#define ANDBIT 295
#define IGUALDAD 296
#define REL 297
#define MULTIDIV 298
#define PORCENTAJE 299
#define UNARIOSLISTA 300
#define EXCLAMACION 301
#define MENOSMENOS 302
#define MULMUL 303
#define AVANRETRO 304

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

#line 245 "y.tab.c" /* yacc.c:358  */

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
#define YYLAST   455

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  50
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  47
/* YYNRULES -- Number of rules.  */
#define YYNRULES  102
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  181

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
       0,    88,    88,    91,    90,   106,   109,   112,   113,   115,
     116,   119,   121,   130,   130,   139,   140,   145,   146,   147,
     149,   161,   162,   164,   165,   167,   168,   170,   174,   179,
     186,   186,   187,   213,   214,   218,   219,   220,   221,   222,
     223,   224,   225,   228,   250,   253,   257,   261,   265,   267,
     268,   271,   272,   274,   274,   296,   311,   314,   329,   354,
     368,   387,   401,   417,   436,   451,   501,   515,   529,   543,
     557,   580,   595,   609,   623,   672,   698,   707,   708,   709,
     710,   711,   712,   713,   715,   728,   739,   742,   743,   744,
     745,   748,   750,   751,   754,   756,   757,   761,   763,   764,
     767,   769,   770
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
  "T_REAL", "ARROBA", "LOGOR", "LOGAND", "ORBIT", "EXOR", "ANDBIT",
  "IGUALDAD", "REL", "MULTIDIV", "PORCENTAJE", "UNARIOSLISTA",
  "EXCLAMACION", "MENOSMENOS", "MULMUL", "AVANRETRO", "$accept",
  "Programa", "bloque", "$@1", "Declar_de_variables_locales",
  "Marca_ini_declar_variables", "Marca_fin_declar_variables",
  "Declar_de_subprogs", "Declar_subprog", "Cabecera_programa",
  "Cabecera_subprograma", "$@2", "error_subprog", "parametros",
  "parametro", "Inicio_de_bloque", "Fin_de_bloque", "Variables_locales",
  "Cuerpo_declar_variables", "error_decl_variables", "Identificadores",
  "tipo", "tipo_lista", "Sentencias", "Sentencia", "sentencia_asignacion",
  "sentencia_if", "sentencia_while", "sentencia_entrada",
  "sentencia_salida", "expcad", "lista_expresiones_o_cadena",
  "llamada_proced", "$@3", "sentencia_for", "expresion", "error_expresion",
  "lista_expresiones", "lista", "lista_enteros", "Enteros", "lista_reales",
  "Reales", "lista_booleanos", "Booleanos", "lista_caracteres",
  "Caracteres", YY_NULLPTR
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

#define YYPACT_NINF -122

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-122)))

#define YYTABLE_NINF -87

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      15,    37,    45,    34,    42,  -122,  -122,  -122,  -122,    43,
      77,  -122,  -122,  -122,    70,   405,  -122,    54,  -122,    25,
    -122,  -122,    41,  -122,     8,    76,    81,    41,    73,    62,
      82,  -122,  -122,    34,   414,  -122,  -122,  -122,  -122,  -122,
    -122,  -122,  -122,  -122,    96,  -122,  -122,  -122,     0,  -122,
    -122,  -122,   119,   119,    12,  -122,    92,   119,   119,   119,
    -122,  -122,  -122,  -122,  -122,  -122,   119,   119,  -122,    64,
     275,  -122,  -122,  -122,  -122,  -122,  -122,    83,   119,   101,
    -122,  -122,  -122,  -122,  -122,  -122,    80,   103,   155,   178,
    -122,  -122,  -122,  -122,  -122,     9,    69,    78,    79,   201,
     -11,    28,    28,    28,  -122,    73,   119,   119,   119,   119,
     119,   119,   119,   119,   119,   119,   119,   119,   119,   119,
    -122,   119,   132,     2,  -122,    14,   423,   423,  -122,    90,
    -122,    94,  -122,    95,  -122,    86,  -122,  -122,   298,   139,
     275,   321,   333,   344,   356,   367,   186,    87,    28,    28,
      28,   -29,   229,  -122,   275,    30,    68,  -122,   100,   115,
    -122,  -122,  -122,  -122,  -122,   119,   119,   134,   119,  -122,
      14,  -122,   423,   275,   252,  -122,   275,  -122,  -122,   423,
    -122
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     1,    21,     2,     3,     0,
       6,    12,     7,    10,     0,     0,    27,     0,    30,     0,
      24,    26,     0,    31,     0,     0,     0,     0,     0,     0,
      53,    35,     9,     0,     0,    34,    36,    37,    38,    39,
      40,    41,    42,    32,     0,     5,    23,    28,     0,    16,
      13,    15,     0,     0,     0,    83,     0,     0,     0,     0,
      80,    79,    50,    76,    78,    77,     0,     0,    51,     0,
      49,    82,    81,    87,    88,    89,    90,     0,     0,     0,
      11,    22,     4,    33,     8,    25,     0,     0,     0,     0,
      47,    98,   101,    92,    95,     0,     0,     0,     0,     0,
      59,    57,    58,    61,    48,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      62,     0,     0,     0,    29,    19,     0,     0,    91,     0,
      94,     0,    97,     0,   100,     0,    56,    52,     0,    74,
      63,    69,    66,    68,    67,    73,    71,    70,    65,    72,
      60,    64,     0,    43,    85,     0,     0,    17,     0,    44,
      46,    93,    96,    99,   102,     0,     0,     0,     0,    14,
       0,    20,     0,    75,     0,    54,    84,    18,    45,     0,
      55
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -122,  -122,    11,  -122,  -122,  -122,  -122,  -122,  -122,  -122,
    -122,  -122,  -122,  -122,   -30,  -122,  -122,  -122,   124,  -122,
     117,  -121,  -122,  -122,   -34,  -122,  -122,  -122,  -122,  -122,
      51,  -122,  -122,  -122,  -122,   -51,  -122,  -122,  -122,  -122,
    -122,  -122,  -122,  -122,  -122,  -122,  -122
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    31,    10,    13,    14,    45,    15,    32,     3,
      33,    87,    51,   156,   157,     8,    82,    19,    20,    21,
      48,    22,    23,    34,    35,    36,    37,    38,    39,    40,
      68,    69,    41,    79,    42,    70,    71,   155,    72,    73,
      95,    74,    96,    75,    97,    76,    98
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      83,    88,    89,    55,   158,    85,    99,   100,   101,    49,
      56,   106,    57,   -86,     7,   102,   103,    90,   128,   119,
     120,    86,     1,   -86,    58,    59,    16,   122,    17,    44,
     129,    60,    61,    86,    63,    64,    65,   119,   120,    17,
      50,   167,    18,     4,    80,     5,     6,    66,    67,   158,
     106,   168,     9,    18,    11,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   104,
     152,    16,   154,    47,    55,   118,   119,   120,   130,   169,
      12,    56,    43,    57,    17,   105,    52,   132,   134,   170,
     131,    53,   159,   160,    77,    58,    59,    78,    18,   133,
     135,    84,    60,    61,    62,    63,    64,    65,   121,   106,
     107,   123,   124,   125,   173,   174,   164,   176,    66,    67,
      55,    91,    92,   161,   163,    93,    94,    56,   162,    57,
     116,   117,   171,   172,   118,   119,   120,   153,   178,   175,
     177,    58,    59,    46,    54,   180,     0,     0,    60,    61,
       0,    63,    64,    65,   106,   107,   137,     0,     0,     0,
       0,   106,     0,     0,    66,    67,   126,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   106,   107,   118,
     119,   120,   116,   117,     0,     0,   118,   119,   120,   127,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     106,   107,   118,   119,   120,     0,     0,     0,   106,   107,
       0,     0,   136,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   106,   107,   118,   119,   120,   115,   116,
     117,     0,     0,   118,   119,   120,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,     0,     0,   118,   119,
     120,   106,   107,     0,     0,   166,     0,     0,     0,     0,
       0,     0,     0,     0,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   106,   107,   118,   119,   120,   179,
       0,     0,     0,     0,     0,     0,     0,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   106,   107,   118,
     119,   120,     0,     0,     0,     0,     0,     0,     0,     0,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     106,   107,   118,   119,   120,     0,     0,     0,     0,     0,
       0,     0,     0,   165,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   106,   107,   118,   119,   120,     0,     0,
       0,     0,     0,     0,     0,   106,   107,     0,   110,   111,
     112,   113,   114,   115,   116,   117,   106,   107,   118,   119,
     120,   111,   112,   113,   114,   115,   116,   117,   106,   107,
     118,   119,   120,   112,   113,   114,   115,   116,   117,   106,
     107,   118,   119,   120,     0,     0,   113,   114,   115,   116,
     117,     0,     0,   118,   119,   120,     0,     0,   114,   115,
     116,   117,    24,     0,   118,   119,   120,     6,     0,     0,
       0,    25,    26,     0,    27,    28,     6,    81,     0,    29,
      25,    26,     0,    27,    28,     6,     0,    30,    29,    25,
      26,     0,    27,    28,     0,     0,    30,    29,     0,     0,
       0,     0,     0,     0,     0,    30
};

static const yytype_int16 yycheck[] =
{
      34,    52,    53,     1,   125,     5,    57,    58,    59,     1,
       8,    22,    10,    11,     3,    66,    67,     5,     9,    48,
      49,    21,     7,    21,    22,    23,     1,    78,    14,     4,
      21,    29,    30,    21,    32,    33,    34,    48,    49,    14,
      32,    11,    28,     6,    33,     0,    12,    45,    46,   170,
      22,    21,    10,    28,    11,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,     5,
     121,     1,   123,    32,     1,    47,    48,    49,     9,    11,
       3,     8,    28,    10,    14,    21,    10,     9,     9,    21,
      21,    10,   126,   127,    32,    22,    23,    15,    28,    21,
      21,     5,    29,    30,    31,    32,    33,    34,    25,    22,
      23,    10,    32,    10,   165,   166,    30,   168,    45,    46,
       1,    29,    30,    33,    29,    33,    34,     8,    34,    10,
      43,    44,    32,    18,    47,    48,    49,     5,   172,     5,
     170,    22,    23,    19,    27,   179,    -1,    -1,    29,    30,
      -1,    32,    33,    34,    22,    23,   105,    -1,    -1,    -1,
      -1,    22,    -1,    -1,    45,    46,    11,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    22,    23,    47,
      48,    49,    43,    44,    -1,    -1,    47,    48,    49,    11,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      22,    23,    47,    48,    49,    -1,    -1,    -1,    22,    23,
      -1,    -1,    11,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    22,    23,    47,    48,    49,    42,    43,
      44,    -1,    -1,    47,    48,    49,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    -1,    -1,    47,    48,
      49,    22,    23,    -1,    -1,    26,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    22,    23,    47,    48,    49,    27,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    22,    23,    47,
      48,    49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      22,    23,    47,    48,    49,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    22,    23,    47,    48,    49,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    22,    23,    -1,    37,    38,
      39,    40,    41,    42,    43,    44,    22,    23,    47,    48,
      49,    38,    39,    40,    41,    42,    43,    44,    22,    23,
      47,    48,    49,    39,    40,    41,    42,    43,    44,    22,
      23,    47,    48,    49,    -1,    -1,    40,    41,    42,    43,
      44,    -1,    -1,    47,    48,    49,    -1,    -1,    41,    42,
      43,    44,     7,    -1,    47,    48,    49,    12,    -1,    -1,
      -1,    16,    17,    -1,    19,    20,    12,    13,    -1,    24,
      16,    17,    -1,    19,    20,    12,    -1,    32,    24,    16,
      17,    -1,    19,    20,    -1,    -1,    32,    24,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    32
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     7,    51,    59,     6,     0,    12,    52,    65,    10,
      53,    11,     3,    54,    55,    57,     1,    14,    28,    67,
      68,    69,    71,    72,     7,    16,    17,    19,    20,    24,
      32,    52,    58,    60,    73,    74,    75,    76,    77,    78,
      79,    82,    84,    28,     4,    56,    68,    32,    70,     1,
      32,    62,    10,    10,    70,     1,     8,    10,    22,    23,
      29,    30,    31,    32,    33,    34,    45,    46,    80,    81,
      85,    86,    88,    89,    91,    93,    95,    32,    15,    83,
      52,    13,    66,    74,     5,     5,    21,    61,    85,    85,
       5,    29,    30,    33,    34,    90,    92,    94,    96,    85,
      85,    85,    85,    85,     5,    21,    22,    23,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    47,    48,
      49,    25,    85,    10,    32,    10,    11,    11,     9,    21,
       9,    21,     9,    21,     9,    21,    11,    80,    85,    85,
      85,    85,    85,    85,    85,    85,    85,    85,    85,    85,
      85,    85,    85,     5,    85,    87,    63,    64,    71,    74,
      74,    33,    34,    29,    30,    35,    26,    11,    21,    11,
      21,    32,    18,    85,    85,     5,    85,    64,    74,    27,
      74
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    50,    51,    53,    52,    54,    54,    55,    56,    57,
      57,    58,    59,    61,    60,    60,    62,    63,    63,    63,
      64,    65,    66,    67,    67,    68,    68,    69,    70,    70,
      71,    71,    72,    73,    73,    74,    74,    74,    74,    74,
      74,    74,    74,    75,    76,    76,    77,    78,    79,    80,
      80,    81,    81,    83,    82,    84,    85,    85,    85,    85,
      85,    85,    85,    85,    85,    85,    85,    85,    85,    85,
      85,    85,    85,    85,    85,    85,    85,    85,    85,    85,
      85,    85,    85,    86,    87,    87,    87,    88,    88,    88,
      88,    89,    90,    90,    91,    92,    92,    93,    94,    94,
      95,    96,    96
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     0,     6,     3,     0,     1,     2,     2,
       0,     2,     4,     0,     6,     2,     1,     1,     3,     0,
       2,     1,     1,     2,     1,     3,     1,     1,     1,     3,
       1,     1,     2,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     4,     5,     7,     5,     3,     3,     1,
       1,     1,     3,     0,     6,     8,     3,     2,     2,     2,
       3,     2,     2,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     5,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     1,     0,     1,     1,     1,
       1,     3,     1,     3,     3,     1,     3,     3,     1,     3,
       3,     1,     3
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
#line 88 "yacc.y" /* yacc.c:1646  */
    {muestra();printf("Compilacion Terminada\n");}
#line 1521 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 91 "yacc.y" /* yacc.c:1646  */
    {
	yylval.tipoDato = NO_ASIG;
	yylval.nombre = strdup("INIBLOQUE");
	inserta(yylval, MARCA);
	}
#line 1531 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 100 "yacc.y" /* yacc.c:1646  */
    {
		eliminarHastaMarca();//muestra();
	}
#line 1539 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 122 "yacc.y" /* yacc.c:1646  */
    {
	(yyvsp[-2]).tipoDato = NO_ASIG;
	inserta((yyvsp[-2]), PROC);
}
#line 1548 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 130 "yacc.y" /* yacc.c:1646  */
    {
		contParam = 0;
	 (yyvsp[0]).tipoDato = NO_ASIG;
	 (yyvsp[0]).parametros = 0;
	 estado = inserta((yyvsp[0]), PROC);
	 posicion = ultimaPosicion();
 }
#line 1560 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 141 "yacc.y" /* yacc.c:1646  */
    { 	printf("[Error SÍNTÁCTICO: linea %d] Error creación de subprograma ", linea_actual);

	}
#line 1568 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 150 "yacc.y" /* yacc.c:1646  */
    {
	contParam++;
	entradaTS temp = devuelveEntrada(posicion);
	temp.parametros++;
	actualiza(posicion,temp);
	(yyval).tipoDato = (yyvsp[-1]).tipoDato;
	(yyvsp[0]).tipoDato = (yyvsp[-1]).tipoDato;
	estado = inserta((yyvsp[0]), PAR_FORMAL);
}
#line 1582 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 171 "yacc.y" /* yacc.c:1646  */
    { printf("[Error SÍNTÁCTICO: linea %d] Error declaración de variables ", linea_actual);
	}
#line 1589 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 175 "yacc.y" /* yacc.c:1646  */
    {
			(yyvsp[0]).tipoDato = tempTipoDato;
			estado = inserta((yyvsp[0]), VARIABLE);
		}
#line 1598 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 180 "yacc.y" /* yacc.c:1646  */
    {
		(yyvsp[0]).tipoDato = tempTipoDato;
		estado = inserta((yyvsp[0]), VARIABLE);
		}
#line 1607 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 186 "yacc.y" /* yacc.c:1646  */
    {tempTipoDato = (yyvsp[0]).tipoDato;}
#line 1613 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 188 "yacc.y" /* yacc.c:1646  */
    {

	switch ((yyvsp[0]).tipoDato) {
		case NO_ASIG:
		tempTipoDato = 0;
		break;
		case DESC:
		tempTipoDato = 0;
		break;
		case ENTERO:
		tempTipoDato = LISTA_ENTERO;
		break;
		case REAL:
		tempTipoDato = LISTA_REAL;
		break;
		case BOOLEANO:
		tempTipoDato = LISTA_BOOLEANO;
		break;
		case CARACTER:
		tempTipoDato = LISTA_CARACTER;
		break;
	}

}
#line 1642 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 229 "yacc.y" /* yacc.c:1646  */
    {
//printf("buscando %s para comparar\n", $1.nombre );
int posicion = buscaEnTs((yyvsp[-3]));
if(posicion==-1){
	printf("[Error SEMÁNTICO: linea %d] ASIGNACION ", linea_actual);
	printf("variable no definida\n");
}
	else{
		entradaTS  temp = devuelveEntrada(posicion);
		tipoTemp = temp.tipoDato;

		//printf("Comparando %s tipoIzq: %d, tipoder: %d\n",temp.nombre,temp.tipoDato,$3.tipoDato);
		if ( tipoTemp != (yyvsp[-1]).tipoDato ) {
			printf("[Error SEMÁNTICO: linea %d] ASIGNACION ", linea_actual);
			printf("tipos no coinciden dato izq = %d, der = %d\n",tipoTemp,(yyvsp[-1]).tipoDato);
			}

	}
}
#line 1666 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 251 "yacc.y" /* yacc.c:1646  */
    { if((yyvsp[-2]).tipoDato != BOOLEANO ) printf("[Error SEMÁNTICO: linea %d] Condicional no booleana\n",linea_actual);
	}
#line 1673 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 254 "yacc.y" /* yacc.c:1646  */
    { if((yyvsp[-4]).tipoDato != BOOLEANO ) printf("[Error SEMÁNTICO: linea %d] Condicional no booleana\n",linea_actual);
	}
#line 1680 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 258 "yacc.y" /* yacc.c:1646  */
    { if((yyvsp[-2]).tipoDato != BOOLEANO ) printf("[Error SEMÁNTICO: linea %d] Condicional no booleana\n",linea_actual);
	}
#line 1687 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 274 "yacc.y" /* yacc.c:1646  */
    {
	contParam = 0;
	posicion = busca((yyvsp[0]));
}
#line 1696 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 279 "yacc.y" /* yacc.c:1646  */
    {
	if(posicion == -1){
		printf("[Error SEMÁNTICO: linea %d] Procedimiento no definido: %s\n" ,linea_actual, (yyvsp[-5]).nombre );
	} else{
		 entradaTS temp = devuelveEntrada(posicion);
		 printf("Llamada Procedimiento:  %s , %d\n", temp.nombre, temp.parametros );
		 //muestra();
		 if( temp.parametros == contParam){

		 }else{
				printf("[Error SEMANTICO: linea %d] Numero de expresiones erroneo: %s ,%d,%d \n",linea_actual, (yyvsp[-5]).nombre, temp.parametros ,contParam );
				(yyval).tipoDato = DESC;
		 }
	 }
}
#line 1716 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 297 "yacc.y" /* yacc.c:1646  */
    {
			if (((yyvsp[-4]).tipoDato == ENTERO) && ((yyvsp[-2]).tipoDato==(yyvsp[-4]).tipoDato) ){

			} else {

				fprintf(stderr, "[Error SEMÁNTICO: linea %d] \n ", linea_actual);
				fprintf(stderr, "Op con tipo de dato incorrecto \n");

				(yyval).tipoDato = DESC;
				}
}
#line 1732 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 311 "yacc.y" /* yacc.c:1646  */
    {
						(yyval) = (yyvsp[-1]);
						}
#line 1740 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 315 "yacc.y" /* yacc.c:1646  */
    {
				if ( ((yyvsp[0]).tipoDato != BOOLEANO)
					&& ((yyvsp[0]).tipoDato != LISTA_BOOLEANO) ) {

					(yyval).tipoDato = (yyvsp[0]).tipoDato;

				} else {

					fprintf(stderr, "[Error SEMÁNTICO: linea %d] \n ", linea_actual);
					fprintf(stderr, "Op con tipo de dato incorrecto \n");

					(yyval).tipoDato = DESC;
					}
		}
#line 1759 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 330 "yacc.y" /* yacc.c:1646  */
    {
				if ((yyvsp[0]).tipoDato > CARACTER) {
					switch ((yyvsp[-1]).dif) {
						case 0:
							(yyval).tipoDato = ENTERO;
						break;
						case 1:
							(yyval).tipoDato = listaASimple((yyvsp[0]).tipoDato);
						break;
						case 2:
							(yyval).tipoDato = (yyvsp[0]).tipoDato;
						break;
						default:
							(yyval).tipoDato = DESC;
						break;
					}
				} else {

					fprintf(stderr, "[Error SEMÁNTICO: linea %d] \n ", linea_actual);
					fprintf(stderr, "Op con tipo de dato incorrecto \n");

					(yyval).tipoDato = DESC;
					}
	}
#line 1788 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 355 "yacc.y" /* yacc.c:1646  */
    {
				if ((yyvsp[0]).tipoDato > CARACTER) {

					(yyval).tipoDato = (yyvsp[0]).tipoDato;

				} else {

					fprintf(stderr, "[Error SEMÁNTICO: linea %d] \n ", linea_actual);
					fprintf(stderr, "Op con tipo de dato incorrecto \n");

					(yyval).tipoDato = DESC;
					}
	}
#line 1806 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 369 "yacc.y" /* yacc.c:1646  */
    {
				if ((yyvsp[-2]).tipoDato > CARACTER) {
					if((yyvsp[0]).tipoDato == ENTERO){
						(yyval).tipoDato = (yyvsp[-2]).tipoDato;

					}else{
						fprintf(stderr, "[Error SEMÁNTICO: linea %d] \n ", linea_actual);
						fprintf(stderr, "No es un entero\n");
						(yyval).tipoDato = DESC;
					}
				} else {

					fprintf(stderr, "[Error SEMÁNTICO: linea %d] \n ", linea_actual);
					fprintf(stderr, "No es una lista\n");

					(yyval).tipoDato = DESC;
					}
	}
#line 1829 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 388 "yacc.y" /* yacc.c:1646  */
    {
				if ((yyvsp[0]).tipoDato == BOOLEANO) {

					(yyval).tipoDato = (yyvsp[0]).tipoDato;

				} else {

					fprintf(stderr, "[Error SEMÁNTICO: linea %d] \n ", linea_actual);
					fprintf(stderr, "Op con tipo de dato incorrecto \n");

					(yyval).tipoDato = DESC;
					}
	}
#line 1847 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 402 "yacc.y" /* yacc.c:1646  */
    {
		{
					if ((yyvsp[-1]).tipoDato > CARACTER) {

						(yyval).tipoDato = (yyvsp[-1]).tipoDato;

					} else {

						fprintf(stderr, "[Error SEMÁNTICO: linea %d] \n ", linea_actual);
						fprintf(stderr, "Op con tipo de dato incorrecto \n");

						(yyval).tipoDato = DESC;
						}
		}
	}
#line 1867 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 418 "yacc.y" /* yacc.c:1646  */
    {
		if ((yyvsp[-2]).tipoDato > CARACTER){

			if((yyvsp[0]).tipoDato == ENTERO){
				(yyval).tipoDato = listaASimple((yyvsp[-2]).tipoDato);
			} else {
				fprintf(stderr, "[Error SEMÁNTICO: linea %d] \n ", linea_actual);
				fprintf(stderr, " Debe ser entero para acceder a posicion \n");
				(yyval).tipoDato = DESC;
			}

		}else{
			fprintf(stderr, "[Error SEMÁNTICO: linea %d] \n ", linea_actual);
			fprintf(stderr, "No es una lista %s \n",(yyvsp[-2]).nombre);
			(yyval).tipoDato = DESC;

		}
	}
#line 1890 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 436 "yacc.y" /* yacc.c:1646  */
    {
		{
					if (((yyvsp[-2]).tipoDato > CARACTER) && ((yyvsp[0]).tipoDato == (yyvsp[-2]).tipoDato)) {

						(yyval).tipoDato = (yyvsp[-2]).tipoDato;

					} else {

						fprintf(stderr, "[Error SEMÁNTICO: linea %d] \n ", linea_actual);
						fprintf(stderr, "Op con tipo de dato incorrecto \n");

						(yyval).tipoDato = DESC;
						}
		}
	}
#line 1910 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 452 "yacc.y" /* yacc.c:1646  */
    {
		if ((yyvsp[-2]).tipoDato == LISTA_ENTERO || (yyvsp[-2]).tipoDato == LISTA_REAL){

			if((yyvsp[0]).tipoDato == REAL){
				(yyval).tipoDato == LISTA_REAL;
			} else if ((yyvsp[0]).tipoDato == ENTERO) {
				(yyval).tipoDato = (yyvsp[-2]).tipoDato;
			} else {
				fprintf(stderr, "[Error SEMÁNTICO: linea %d] \n ", linea_actual);
				fprintf(stderr, " Tipos no coinciden \n");
				(yyval).tipoDato = DESC;
			}

		} else if ((yyvsp[-2]).tipoDato == REAL || (yyvsp[-2]).tipoDato == ENTERO) {
			if ((yyvsp[-1]).dif = 0) {
				if ((yyvsp[0]).tipoDato == (yyvsp[-2]).tipoDato) {
					(yyval).tipoDato = (yyvsp[-2]).tipoDato;
				} else if ((yyvsp[0]).tipoDato == REAL){
					(yyval).tipoDato == REAL;
				} else if ((yyvsp[0]).tipoDato == LISTA_ENTERO || (yyvsp[0]).tipoDato == LISTA_REAL) {
					if ((yyvsp[-2]).tipoDato == ENTERO){
						(yyval).tipoDato = (yyvsp[0]).tipoDato;
					} else {
						(yyval).tipoDato = LISTA_REAL;
					}
				} else {
					fprintf(stderr, "[Error SEMÁNTICO: linea %d] \n ", linea_actual);
					fprintf(stderr, " Tipos no coinciden \n");
					(yyval).tipoDato = DESC;
				}

			} else {
				if ((yyvsp[0]).tipoDato == (yyvsp[-2]).tipoDato) {
					(yyval).tipoDato = (yyvsp[-2]).tipoDato;
				} else if ((yyvsp[0]).tipoDato == REAL){
					(yyval).tipoDato == REAL;
				} else {
					fprintf(stderr, "[Error SEMÁNTICO: linea %d] \n ", linea_actual);
					fprintf(stderr, " Tipos no coinciden \n");
					(yyval).tipoDato = DESC;
				}
			}
		} else {

			fprintf(stderr, "[Error SEMÁNTICO: linea %d] \n ", linea_actual);
			fprintf(stderr, " Tipos no coinciden \n");
			(yyval).tipoDato = DESC;
		}
	}
#line 1964 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 502 "yacc.y" /* yacc.c:1646  */
    {
				if (((yyvsp[-2]).tipoDato == BOOLEANO) && ((yyvsp[0]).tipoDato == (yyvsp[-2]).tipoDato) ) {

					(yyval).tipoDato = (yyvsp[-2]).tipoDato;

				} else {

					fprintf(stderr, "[Error SEMÁNTICO: linea %d] \n ", linea_actual);
					fprintf(stderr, "Op con tipo de dato incorrecto \n");

					(yyval).tipoDato = DESC;
					}
	}
#line 1982 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 516 "yacc.y" /* yacc.c:1646  */
    {
				if (((yyvsp[-2]).tipoDato == BOOLEANO) && ((yyvsp[0]).tipoDato == (yyvsp[-2]).tipoDato) ) {

					(yyval).tipoDato = (yyvsp[-2]).tipoDato;

				} else {

					fprintf(stderr, "[Error SEMÁNTICO: linea %d] \n ", linea_actual);
					fprintf(stderr, "Op con tipo de dato incorrecto \n");

					(yyval).tipoDato = DESC;
					}
	}
#line 2000 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 530 "yacc.y" /* yacc.c:1646  */
    {
				if (((yyvsp[-2]).tipoDato == BOOLEANO) && ((yyvsp[0]).tipoDato == (yyvsp[-2]).tipoDato) ) {

					(yyval).tipoDato = (yyvsp[-2]).tipoDato;

				} else {

					fprintf(stderr, "[Error SEMÁNTICO: linea %d] \n ", linea_actual);
					fprintf(stderr, "Op con tipo de dato incorrecto \n");

					(yyval).tipoDato = DESC;
					}
	}
#line 2018 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 544 "yacc.y" /* yacc.c:1646  */
    {
				if (((yyvsp[-2]).tipoDato == BOOLEANO) && ((yyvsp[0]).tipoDato == (yyvsp[-2]).tipoDato) ) {

					(yyval).tipoDato = (yyvsp[-2]).tipoDato;

				} else {

					fprintf(stderr, "[Error SEMÁNTICO: linea %d] \n ", linea_actual);
					fprintf(stderr, "Op con tipo de dato incorrecto \n");

					(yyval).tipoDato = DESC;
					}
	}
#line 2036 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 558 "yacc.y" /* yacc.c:1646  */
    {
		if ( ((yyvsp[-2]).tipoDato < BOOLEANO) && ((yyvsp[0]).tipoDato < BOOLEANO) ) {

			if ( ((yyvsp[-2]).tipoDato > DESC) && ((yyvsp[0]).tipoDato > DESC)  ) {

				(yyval).tipoDato = BOOLEANO;

			} else {

				fprintf(stderr, "[Error SEMÁNTICO: linea %d] \n ", linea_actual);
				fprintf(stderr, "Op +/- con tipo de dato");
				fprintf(stderr, "incorrecto\n");

				(yyval).tipoDato = DESC;
				}
		} else {

			fprintf(stderr, "[Error SEMÁNTICO: linea %d] \n ", linea_actual);
			fprintf(stderr, " Tipos no coinciden \n");
			(yyval).tipoDato = DESC;
			}
	}
#line 2063 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 581 "yacc.y" /* yacc.c:1646  */
    {
		if( ((yyvsp[-2]).tipoDato < LISTA_REAL) && ((yyvsp[0]).tipoDato == (yyvsp[-2]).tipoDato)   ) {

				(yyval).tipoDato = BOOLEANO;

			} else {

				fprintf(stderr, "[Error SEMÁNTICO: linea %d] \n ", linea_actual);
				fprintf(stderr, "Op +/- con tipo de dato");
				fprintf(stderr, "incorrecto\n");

				(yyval).tipoDato = DESC;
			}
	}
#line 2082 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 596 "yacc.y" /* yacc.c:1646  */
    {
				if (((yyvsp[-2]).tipoDato > CARACTER) && ((yyvsp[0]).tipoDato == ENTERO)) {

					(yyval).tipoDato = (yyvsp[-2]).tipoDato;

				} else {

					fprintf(stderr, "[Error SEMÁNTICO: linea %d] \n ", linea_actual);
					fprintf(stderr, "Op con tipo de dato incorrecto \n");

					(yyval).tipoDato = DESC;
					}
	}
#line 2100 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 610 "yacc.y" /* yacc.c:1646  */
    {
				if (((yyvsp[-2]).tipoDato == BOOLEANO) && ((yyvsp[0]).tipoDato == (yyvsp[-2]).tipoDato) ) {

					(yyval).tipoDato = (yyvsp[-2]).tipoDato;

				} else {

					fprintf(stderr, "[Error SEMÁNTICO: linea %d] \n ", linea_actual);
					fprintf(stderr, "Op con tipo de dato incorrecto \n");

					(yyval).tipoDato = DESC;
					}
	}
#line 2118 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 624 "yacc.y" /* yacc.c:1646  */
    {
		if ((yyvsp[-2]).tipoDato == LISTA_ENTERO || (yyvsp[-2]).tipoDato == LISTA_REAL){


			if((yyvsp[0]).tipoDato == REAL){
				(yyval).tipoDato == LISTA_REAL;
			} else if ((yyvsp[0]).tipoDato == ENTERO) {
				(yyval).tipoDato = (yyvsp[-2]).tipoDato;
			} else {
				fprintf(stderr, "[Error SEMÁNTICO: linea %d] \n ", linea_actual);
				fprintf(stderr, " Tipos no coinciden \n");
				(yyval).tipoDato = DESC;
			}

			//fprintf(stderr, "[EEEEE]izq %d der %d / \n", $1.tipoDato,$3.tipoDato);


		} else if ((yyvsp[-2]).tipoDato == REAL || (yyvsp[-2]).tipoDato == ENTERO) {
			if ((yyvsp[-1]).dif == 0) {
				if ((yyvsp[0]).tipoDato == (yyvsp[-2]).tipoDato) {
					(yyval).tipoDato = (yyvsp[-2]).tipoDato;
				} else if ((yyvsp[0]).tipoDato == REAL){
					(yyval).tipoDato == REAL;
				} else if ((yyvsp[0]).tipoDato == LISTA_ENTERO || (yyvsp[0]).tipoDato == LISTA_REAL) {
					if ((yyvsp[-2]).tipoDato == ENTERO){
						(yyval).tipoDato = (yyvsp[0]).tipoDato;
					} else {
						(yyval).tipoDato = LISTA_REAL;
					}
				} else {
					fprintf(stderr, "[Error SEMÁNTICO: linea %d] \n ", linea_actual);
					fprintf(stderr, " Tipos no coinciden \n");
					(yyval).tipoDato = DESC;
				}

			} else {
				if ((yyvsp[0]).tipoDato == (yyvsp[-2]).tipoDato) {
					(yyval).tipoDato = (yyvsp[-2]).tipoDato;
				} else if ((yyvsp[0]).tipoDato == REAL){
					(yyval).tipoDato == REAL;
				} else {
					fprintf(stderr, "[Error SEMÁNTICO: linea %d] \n ", linea_actual);
					fprintf(stderr, " Orden incorrecto \n");
					(yyval).tipoDato = DESC;
				}
			}
		}
	}
#line 2171 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 673 "yacc.y" /* yacc.c:1646  */
    {
				if ((yyvsp[-4]).tipoDato > CARACTER) {
						if((yyvsp[-2]).tipoDato == listaASimple((yyvsp[-4]).tipoDato)){
							if((yyvsp[0]).tipoDato == ENTERO){
								(yyval).tipoDato = (yyvsp[-4]).tipoDato;
							}else{
								fprintf(stderr, "[Error SEMÁNTICO: linea %d] \n ", linea_actual);

								fprintf(stderr, "Valor distinto de entero: [%s]  \n", linea_actual,(yyvsp[0]).nombre);
							}
					}else{
						fprintf(stderr, "[Error SEMÁNTICO: linea %d] \n ", linea_actual);

						fprintf(stderr, "Valor distinto de lista: [%s]  \n", linea_actual,(yyvsp[-2]).nombre);
					}
				}else{
					fprintf(stderr, "[Error SEMÁNTICO: linea %d] \n ", linea_actual);

					fprintf(stderr, "No es una lista: [%s]  \n", linea_actual,(yyvsp[-4]).nombre);

				}



	}
#line 2201 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 698 "yacc.y" /* yacc.c:1646  */
    {
		int posicion2 = buscaEnTs((yyvsp[0]));
		if(posicion2 == -1){
			fprintf(stderr, "[Error SEMÁNTICO: linea %d] \n ", linea_actual);

			fprintf(stderr, "Variable no definida: [%s]  \n", linea_actual,(yyvsp[0]).nombre);
}else {
	entradaTS temp = devuelveEntrada(posicion2); (yyval).tipoDato = temp.tipoDato; }
}
#line 2215 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 707 "yacc.y" /* yacc.c:1646  */
    {(yyval).tipoDato = (yyvsp[0]).tipoDato; }
#line 2221 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 708 "yacc.y" /* yacc.c:1646  */
    {(yyval).tipoDato = (yyvsp[0]).tipoDato; }
#line 2227 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 709 "yacc.y" /* yacc.c:1646  */
    {(yyval).tipoDato = (yyvsp[0]).tipoDato; }
#line 2233 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 710 "yacc.y" /* yacc.c:1646  */
    {(yyval).tipoDato = (yyvsp[0]).tipoDato; }
#line 2239 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 711 "yacc.y" /* yacc.c:1646  */
    {(yyval).tipoDato = (yyvsp[0]).tipoDato; }
#line 2245 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 716 "yacc.y" /* yacc.c:1646  */
    {
	contParam++;
	entradaTS temp = devuelveEntrada(posicion + contParam );
	if(temp.tipoDato != (yyvsp[0]).tipoDato){

		fprintf(stderr, "[Error SEMÁNTICO: linea %d] \n ", linea_actual);

		printf("Tipo param erroneo: %d ,%d ,%d \n", temp.tipoDato, (yyvsp[0]).tipoDato, contParam );

	}

}
#line 2262 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 729 "yacc.y" /* yacc.c:1646  */
    {
 	contParam++;
 	entradaTS temp = devuelveEntrada(posicion + contParam );
 	if(temp.tipoDato != (yyvsp[0]).tipoDato){
					
		fprintf(stderr, "[Error SEMÁNTICO: linea %d] \n ", linea_actual);

		printf("Tipo param erroneo: %d ,%d ,%d \n", temp.tipoDato, (yyvsp[0]).tipoDato, contParam );
	}
 }
#line 2277 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2281 "y.tab.c" /* yacc.c:1646  */
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
#line 774 "yacc.y" /* yacc.c:1906  */

#include "lex.yy.c"


void yyerror(const char *msg)
{
	printf("[Error : linea %d]: %s\n", linea_actual,msg);
}

#include "main.c"
