#ifndef __TS_H__
#define __TS_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    MARCA = 0
	, PROC
	, VARIABLE
	, PAR_FORMAL
} tipoEntrada;

  typedef enum {
      NO_ASIG = 0
  	, DESC			//< Desconocido / Erroneo 1
  	, ENTERO    //2
    , REAL      //3
    , BOOLEANO  //4
    , CARACTER  //5
    , LISTA_REAL
    , LISTA_ENTERO
    , LISTA_BOOLEANO
    , LISTA_CARACTER
  } dtipo;

typedef union valor {
  	int entero;
  	float real;
  	unsigned char booleano;
  	char caracter;
  	} tValor;

typedef struct {
  tipoEntrada entrada;
  char *nombre;
  dtipo tipoDato;
  unsigned int parametros;
  unsigned int dif;
  tValor valor;
} entradaTS;

#define YYSTYPE entradaTS


int inserta(entradaTS entrada,tipoEntrada tipo);
int busca(entradaTS entrada);
void muestra();
int buscaEnTs(entradaTS entrada);
int eliminarHastaMarca();
entradaTS  devuelveEntrada(int posicion);
int buscaVariableEnScope(entradaTS entrada);
int buscaProc(entradaTS entrada);
dtipo listaASimple(dtipo i);
dtipo simpleALista(dtipo i);

extern int yylineno;
extern FILE *yyin;
extern char *yytext;

#endif
