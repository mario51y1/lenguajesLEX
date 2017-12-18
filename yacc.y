%{
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

	int linea_actual = 1;

%}

%error-verbose

%token INICIOVARS
%token FINVARS
%token PUNTOCOMA
%token MAIN
%token PROCED
%token ABRIRCORCH
%token CERRARCORCH
%token ABRIRPARENT
%token CERRARPARENT
%token ABRIRLLAVES
%token CERRARLLAVES
%token DEFLIST
%token ASIG
%token CONDSI
%token CONDMIENTRAS
%token CONDSINO
%token LEE
%token ESCRIBE
%token COMA
%token MASMAS
%token MASMENOS
%token DURANTE
%token DOSPUNTOSIGUAL
%token HASTA
%token HACER
%token TIPO
%token VERDFALS
%token T_CARACTER
%token T_CADENA
%token IDENTIFICADOR
%token T_ENTERO
%token T_REAL


%left LOGOR
%left LOGAND
%left ORBIT
%left EXOR
%left ANDBIT
%left IGUALDAD
%left REL
%left MASMENOS
%left MULTIDIV PORCENTAJE
%right UNARIOSLISTA
%right EXCLAMACION
%right MENOSMENOS
%right MASMAS
%right MULMUL
%left AVANRETRO
%right ARROBA


%%

//Pagina 45 pdf de practicas - simplificar BNF

Programa : Cabecera_programa bloque ;

bloque : Inicio_de_bloque
	{
	yylval.nombre = strdup("INIBLOQUE");
	inserta(yylval, MARCA);
	}
	Declar_de_variables_locales
	Declar_de_subprogs
	Sentencias
	Fin_de_bloque
	{eliminarHastaMarca(yylval);}
		;


Declar_de_variables_locales : Marca_ini_declar_variables
			      Variables_locales
			      Marca_fin_declar_variables
			     |
;

Marca_ini_declar_variables : INICIOVARS ;
Marca_fin_declar_variables : FINVARS PUNTOCOMA ;

Declar_de_subprogs : Declar_de_subprogs Declar_subprog
	|
  ;

Declar_subprog : Cabecera_subprograma bloque;

Cabecera_programa : PROCED MAIN ABRIRPARENT CERRARPARENT
	{
	$2.tipoDato = NO_ASIG;
	inserta($2, PROC);
	}
;



Cabecera_subprograma : PROCED IDENTIFICADOR
 {
	 estado = inserta($2, PROC);
 }
 ABRIRPARENT parametros CERRARPARENT
| PROCED error_subprog ;
error_subprog : error ;

parametros : parametro
	| parametros COMA parametro
	|
  ;
parametro : tipo IDENTIFICADOR
	{
	$2.tipoDato = $1.tipoDato;
	estado = inserta($2, PAR_FORMAL);
}
;

Inicio_de_bloque :  ABRIRLLAVES ;
Fin_de_bloque :  CERRARLLAVES ;

Variables_locales : Variables_locales Cuerpo_declar_variables
	| Cuerpo_declar_variables
  ;
Cuerpo_declar_variables : tipo Identificadores PUNTOCOMA
	| error_decl_variables
	;
error_decl_variables : error ;

Identificadores : IDENTIFICADOR
		{
			$1.tipoDato = tempTipoDato;
			estado = inserta($1, VARIABLE);
		}
| Identificadores COMA IDENTIFICADOR
		{
		$3.tipoDato = tempTipoDato;
		estado = inserta($3, VARIABLE);
		}
;

tipo : TIPO {tempTipoDato = $1.tipoDato;} | tipo_lista  ;
tipo_lista : DEFLIST TIPO
{

	switch ($2.tipoDato) {
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

} ;

Sentencias : Sentencias Sentencia
	| Sentencia
  ;


Sentencia : bloque
	| sentencia_asignacion
	| sentencia_if
	| sentencia_while
	| sentencia_entrada
	| sentencia_salida
  	| llamada_proced
	| sentencia_for
;

sentencia_asignacion : IDENTIFICADOR ASIG expresion PUNTOCOMA
{
entradaTS temp = devuelveEntrada(buscaHastaMarca($1));
tipoTemp = temp.tipoDato;
char * nombre;
nombre = temp.nombre;
	printf("Comparando tipos de %s: %d y %d ",temp.nombre, tipoTemp,  $3.tipoDato );

if ( tipoTemp != $3.tipoDato ) {
	printf("[ERR] Error linea: %d ASIGNACION ", linea_actual);
	printf("tipos no coinciden\n");
	}
}
;

sentencia_if : CONDSI ABRIRPARENT expresion CERRARPARENT Sentencia
	| CONDSI ABRIRPARENT expresion CERRARPARENT Sentencia CONDSINO Sentencia;

sentencia_while : CONDMIENTRAS ABRIRPARENT expresion CERRARPARENT Sentencia ;

sentencia_entrada : LEE Identificadores PUNTOCOMA ;

sentencia_salida : ESCRIBE lista_expresiones_o_cadena PUNTOCOMA ;

expcad : expresion
	| T_CADENA
  ;

lista_expresiones_o_cadena : expcad
	| lista_expresiones_o_cadena COMA expcad  ;

llamada_proced : IDENTIFICADOR  ABRIRPARENT  lista_expresiones  CERRARPARENT PUNTOCOMA;

sentencia_for : DURANTE IDENTIFICADOR DOSPUNTOSIGUAL  expresion HASTA expresion HACER Sentencia ;

expresion : ABRIRPARENT expresion CERRARPARENT
  	| MASMENOS expresion %prec EXCLAMACION
	| UNARIOSLISTA expresion
	| MASMAS expresion
	| MENOSMENOS expresion
	| EXCLAMACION expresion
	| expresion AVANRETRO
	| expresion MULMUL expresion
	| expresion MULTIDIV expresion
	| expresion LOGAND expresion
	| expresion EXOR expresion
	| expresion ORBIT expresion
	| expresion LOGOR expresion
	| expresion REL expresion
	| expresion IGUALDAD expresion
	| expresion PORCENTAJE expresion
	| expresion ANDBIT expresion
	| expresion MASMENOS expresion
	| expresion MASMAS expresion ARROBA expresion
	| IDENTIFICADOR
	| T_ENTERO
	| T_REAL
	| T_CARACTER
	| VERDFALS
  | lista
  |	error_expresion	;
error_expresion : error ;

lista_expresiones : lista_expresiones COMA expresion
 | expresion
 |
  ;

lista : lista_enteros
	| lista_reales
	| lista_booleanos
	| lista_caracteres
  ;

lista_enteros: ABRIRCORCH Enteros CERRARCORCH ;

Enteros : T_ENTERO
	| Enteros COMA T_ENTERO
;

lista_reales : ABRIRCORCH Reales CERRARCORCH ;

Reales: T_REAL
	|Reales COMA T_REAL
  ;


lista_booleanos : ABRIRCORCH Booleanos	 CERRARCORCH ;

Booleanos : VERDFALS
	| Booleanos COMA VERDFALS
  ;

lista_caracteres: ABRIRCORCH Caracteres CERRARCORCH ;

Caracteres: T_CARACTER
| Caracteres COMA T_CARACTER
;


%%
#include "lex.yy.c"
#include "ts.h"


void yyerror(const char *msg)
{
	printf("[Linea %d]: %s\n", linea_actual,msg);
}

#include "main.c"
