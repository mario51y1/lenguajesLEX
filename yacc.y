%error-verbose

%{
#include <iostream>
using namespace std;

FILE *yyin;



%}


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
%token VERDFALS
%token MASMAS
%token MASMENOS
%token ARROBA
%token DURANTE
%token DOSPUNTOSIGUAL
%token HASTA
%token HACER
%token TIPO
%token CARACTER
%token CADENA
%token IDENTIFICADOR
%token ENTERO
%token REAL

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

bloque : Inicio_de_bloque Declar_de_variables_locales Declar_de_subprogs Sentencias Fin_de_bloque ;

Declar_de_variables_locales : Marca_ini_declar_variables Variables_locales Marca_fin_declar_variables
|
;

Marca_ini_declar_variables : INICIOVARS Inicio_de_bloque ;
Marca_fin_declar_variables : Fin_de_bloque FINVARS PUNTOCOMA ;

Declar_de_subprogs : Declar_de_subprogs Declar_subprog
	|
  ;

Declar_subprog : Cabecera_subprograma bloque ;

Cabecera_programa : MAIN ;

Cabecera_subprograma : PROCED IDENTIFICADOR ABRIRPARENT parametros CERRARPARENT 
	| PROCED error_subprog ;
error_subprog : error ;

parametros : parametro
	| parametros COMA parametro
	|
  ;
parametro : tipo IDENTIFICADOR ;

Inicio_de_bloque :  ABRIRLLAVES ;
Fin_de_bloque :  CERRARLLAVES ;

Variables_locales : Variables_locales Cuerpo_declar_variables
	| Cuerpo_declar_variables
  ;
Cuerpo_declar_variables : tipo Identificadores PUNTOCOMA 
	| error_decl_variables;
error_decl_variables : error ; 

Identificadores : IDENTIFICADOR | Identificadores COMA IDENTIFICADOR ;

tipo : TIPO | tipo_lista ;
tipo_lista : DEFLIST TIPO ;

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

sentencia_asignacion : IDENTIFICADOR ASIG expresion PUNTOCOMA ;

sentencia_if : CONDSI ABRIRPARENT expresion CERRARPARENT Sentencia
	| CONDSI ABRIRPARENT expresion CERRARPARENT Sentencia CONDSINO Sentencia;

sentencia_while : CONDMIENTRAS ABRIRPARENT expresion CERRARPARENT Sentencia ;

sentencia_entrada : LEE Identificadores PUNTOCOMA ; 

sentencia_salida : ESCRIBE lista_expresiones_o_cadena PUNTOCOMA ;

expcad : expresion
	| CADENA
  ;

lista_expresiones_o_cadena : expcad
	| lista_expresiones_o_cadena COMA expcad  ;

llamada_proced : IDENTIFICADOR ABRIRPARENT  lista_expresiones  CERRARPARENT PUNTOCOMA ;

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
	| expresion IGUALDAD expresion
	| expresion PORCENTAJE expresion
	| expresion ANDBIT expresion
	| expresion MASMENOS expresion
	| expresion MASMAS expresion ARROBA expresion 
	| IDENTIFICADOR
  | ENTERO
  | REAL
  | VERDFALS
  | CARACTER
  | lista
  |	error_expresion	;
error_expresion : error ;

lista_expresiones : lista_expresiones COMA expresion | expresion ;

lista : lista_enteros
	| lista_reales
	| lista_booleanos
	| lista_caracteres
  ;

lista_enteros: ABRIRCORCH Enteros CERRARCORCH ;

Enteros : ENTERO
	| Enteros COMA ENTERO
;

lista_reales : ABRIRCORCH Reales CERRARCORCH ;

Reales: REAL
	|Reales COMA REAL
  ;


lista_booleanos : ABRIRCORCH Booleanos CERRARCORCH ;

Booleanos : VERDFALS
	| Booleanos COMA VERDFALS
  ;

lista_caracteres: ABRIRCORCH Caracteres CERRARCORCH ;

Caracteres: CARACTER
| Caracteres COMA CARACTER
;


%%

void main(int argc, char **argv){
	yyin = fopen("input.c","r");
	yyparse();
	fclose(yyin);
	return 0;
}