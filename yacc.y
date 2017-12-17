%{
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

Programa : Cabecera_programa { pet_GenIni(); }
 bloque ;

bloque : Inicio_de_bloque
	{
	yylval.lexema = strdup("INIBLOQUE");
	yylval.tipoDato = NO_ASIG;
	pet_introTS(yylval, MARCA);

	//pet_GenIniBlq(NULL, $1.colIni, $1.colFin);
	}
	Declar_de_variables_locales
	Declar_de_subprogs
	Sentencias
	Fin_de_bloque
	{
	pet_SacarTS();

	//pet_GenFinBlq();
	}
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

Declar_subprog : Cabecera_subprograma bloque
		{
		pet_GenFinDecProc();
		}
;

Cabecera_programa : PROCED MAIN ABRIRPARENT CERRARPARENT
{
$2.tipoDato = NO_ASIG;
pet_introTS($2, PROC);
}
;



Cabecera_subprograma : PROCED IDENTIFICADOR
 {
	 $2.tipoDato = NO_ASIG;

	 estado = pet_introTS($2, PROC);
	if ( estado )
		pet_GenDecProc($2.lexema, NO_ASIG);
	}
 ABRIRPARENT parametros CERRARPARENT
 {
 	pet_GenFinCabecera();
 }
| PROCED error_subprog ;
error_subprog : error ;

parametros : parametro
	| parametros COMA parametro
	|
	{
	pet_GenParam(NO_ASIG, NULL);
	}
  ;
parametro : tipo IDENTIFICADOR
	{
	$2.tipoDato = $1.tipoDato;
	estado = pet_introTS($2, PAR_FORMAL);

	if ( estado )
		pet_GenParam($1.tipoDato, $2.lexema);
	}
;

Inicio_de_bloque :  ABRIRLLAVES ;
Fin_de_bloque :  CERRARLLAVES ;

Variables_locales : Variables_locales Cuerpo_declar_variables
	| Cuerpo_declar_variables
  ;
Cuerpo_declar_variables : tipo {tempTipoDato = $1.tipoDato;} Identificadores PUNTOCOMA
	| error_decl_variables;
error_decl_variables : error ;

Identificadores : IDENTIFICADOR
		{
			$1.tipoDato = tempTipoDato;
			estado = pet_introTS($1, VARIABLE);

		if ( estado ) {
			pet_GenDecVar($1.tipoDato, $1.lexema);
			}
		}
| Identificadores COMA IDENTIFICADOR
		{
		$3.tipoDato = tempTipoDato;
		estado = pet_introTS($3, VARIABLE);

		if ( estado ) {
			pet_GenDecVar($3.tipoDato, $3.lexema);
			}
		}
;

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

sentencia_asignacion : IDENTIFICADOR ASIG expresion PUNTOCOMA
{

tipoTemp = pet_BuscarTS($1);
$1.tipoDato = tipoTemp;
estado = pet_VerifTIPO($1, $3);


if ( tipoTemp != $3.tipoDato ) {
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

pet_GenIniBlq("/** Asignacion **/\n", $1.colIni, $3.colFin);

// Peticion de ASIGNACION

pet_GenAsig(2, $1.lexema, $3.nomTemp, NULL, NULL);

pet_GenFinBlq();
}
; ;

sentencia_if : CONDSI ABRIRPARENT expresion CERRARPARENT Sentencia
	| CONDSI ABRIRPARENT expresion CERRARPARENT Sentencia CONDSINO Sentencia;

sentencia_while : CONDMIENTRAS ABRIRPARENT expresion CERRARPARENT Sentencia ;

sentencia_entrada : LEE
{
pet_GenIniBlq("/** Sent ENTRADA **/\n", $1.colIni, $1.colFin);
}
Identificadores
{
pet_GenENTRADA($3.formato, $3.variables);

pet_GenFinBlq();
} PUNTOCOMA ;

sentencia_salida : ESCRIBE lista_expresiones_o_cadena PUNTOCOMA ;

expcad : expresion
	| T_CADENA
  ;

lista_expresiones_o_cadena : expcad
	| lista_expresiones_o_cadena COMA expcad  ;

llamada_proced : IDENTIFICADOR {
$1.nParam = pet_BuscarPROC($1);
contParam = 0;
if ( $1.nParam < 0 )
	fprintf(stderr, "[ERR] Proc no declarado: %s\n", $1.lexema);
else {
	// Usamos
	$1.tipoDato = NO_ASIG;
	pet_GenIniBlq("/** Llamada a PROC **/\n"
		, $1.colIni, $1.colFin);
	}
} ABRIRPARENT  lista_expresiones  CERRARPARENT PUNTOCOMA
{
if ( contParam != $1.nParam && $1.nParam >= 0 ) {
	fprintf(stderr, "[ERR] Linea %d Num parametros no concuerda\n", yylineno);
	fprintf(stderr, "[ERR] Declarados: %d  Usados: %d\n",$1.nParam, contParam);
} else if ( $4.tipoDato != NO_ASIG ) {
	fprintf(stderr, "[ERR] Linea %d Llamada a PROC incorrecta\n", yylineno);
} else {
	// Llamada CORRECTA
	pet_GenLlamada($1.lexema, $4.variables);
	// TODO: Liberar MEMORIA
	free($4.variables);
	}
pet_GenFinBlq();
}
;

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
	{
	/**********************************************
	  COMPROBACION DE TIPOS

	  NO SE PIDE LA ASIGNACION DE VALORES !!!!!!!
	  OP_ARIT12 = "+", "-"
	 **********************************************/

	if ( $1.tipoDato == $3.tipoDato ) {
		/**************************************************
		  La suma/resta se puede hacer para cualquier tipo
		  EXCEPTO para booleanos
		 **************************************************/

		if ( ($1.tipoDato != BOOLEANO)
			&& ($1.tipoDato != LISTA_BOOLEANO) ) {

			$$.tipoDato = $1.tipoDato;

			/* Hay que definir las operaciones para listas 	*/
			/* $2.nParam define la operacion		*/
			/* 1 = Suma, 2 = Resta				*/

			//  operar(&($$), $1, $3, $2.nParam);

		} else {

			fprintf(stderr, "ERROR linea: %d ", yylineno);
			fprintf(stderr, "Op +/- con tipo de dato");
			fprintf(stderr, "incorrecto");

			$$.tipoDato = DESC;
			}
	} else {

		fprintf(stderr, "ERROR linea: %d OP_A12 ", yylineno);
		fprintf(stderr, "Tipos no coinciden ");
		$$.tipoDato = DESC;
		}

	/******************************************
	  Asignacion variables de localizacion
	  TODO: Verificacion TIPO por OPERADOR !!!
	 ******************************************/

	estado = pet_VerifTIPO($1, $3);

	$$.linIni = $1.linIni;
	$$.colIni = $1.colIni;
	$$.linFin = $3.linFin;
	$$.colFin = $3.colFin;

	$$.nomTemp = pet_GenTemp();

	if ( estado ) {
		$$.tipoDato = $1.tipoDato;
		pet_GenDecVar($$.tipoDato, $$.nomTemp);

		fprintf(stderr, "ASIG %s = %s %s %s\n"
			, $$.nomTemp, $1.nomTemp
			, $2.lexema, $3.nomTemp);

		pet_GenAsig(4, $$.nomTemp, $1.nomTemp
			, $2.lexema, $3.nomTemp);
	} else {
		$$.tipoDato = DESC;
		}
	}
	| expresion MASMAS expresion ARROBA expresion
	| IDENTIFICADOR
	| T_ENTERO
	| T_REAL
	| T_CADENA
	| T_CARACTER
	| VERDFALS
  | lista
  |	error_expresion	;
error_expresion : error ;

lista_expresiones : lista_expresiones COMA expresion
{
fprintf(stderr, "[COMP] Argumentos R1\n");
tipoOK = pet_BuscarPARAM($3);
contParam++;

if ( tipoOK && $1.tipoDato == NO_ASIG ) {
	$$.tipoDato = NO_ASIG;
	tamCadena = strlen($1.variables)
		+ 2 + strlen($3.nomTemp) + 1;

	$$.variables = (char *) malloc(tamCadena * sizeof(char));
	if ( $$.variables == NULL ) {
		perror("LISTA_EXP");
		$$.tipoDato = DESC;
	} else {
		strcpy($$.variables, $1.variables);
		strcat($$.variables, ", ");
		strcat($$.variables, $3.nomTemp);
		fprintf(stderr, "DEBUG ListaEXP %s\n"
			, $$.variables);

		// Deberiamos poder liberar memoria !!!
		free($3.nomTemp);
		free($1.variables);
		}
} else {
	$$.tipoDato = DESC;
	}
}
 | expresion
 {
 fprintf(stderr, "[COMP] Argumentos R2\n");
 tipoOK = pet_BuscarPARAM($1);
 contParam++;
 if ( tipoOK ) {
 	$$.tipoDato = NO_ASIG;
 	// Crear la lista de expresiones...
 	$$.variables = strdup($1.nomTemp);
 	fprintf(stderr, "DEBUG ListaExp %s\n", $1.nomTemp);
 	// Deberiamos poder liberar la memoria
 	// de nomTemp ???? y toda la demas...
 	free($1.nomTemp);
 } else
 	$$.tipoDato = DESC;
 }
 |
 {
 $$.tipoDato = NO_ASIG;
 $$.variables = strdup("<< SIN_ARGUMENTOS >>");
 }
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
#include "sefasgen.h"


void yyerror(const char *msg)
{
	fprintf(stderr,"[Linea %d]: %s\n", linea_actual,msg);
}

#include "main.c"
