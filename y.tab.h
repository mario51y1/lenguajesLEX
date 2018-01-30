/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison interface for Yacc-like parsers in C

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
