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
	int posicion;
	int contExp = 0;

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

Programa : Cabecera_programa bloque {muestra();printf("Compilacion Terminada\n");};

bloque : Inicio_de_bloque
	{
	yylval.tipoDato = NO_ASIG;
	yylval.nombre = strdup("INIBLOQUE");
	inserta(yylval, MARCA);
	}
	Declar_de_variables_locales
	Declar_de_subprogs
	Sentencias
	Fin_de_bloque
	{
		eliminarHastaMarca();//muestra();
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

Declar_subprog : Cabecera_subprograma bloque;

Cabecera_programa : PROCED MAIN ABRIRPARENT CERRARPARENT
{
	$2.tipoDato = NO_ASIG;
	inserta($2, PROC);
}
;



Cabecera_subprograma : PROCED IDENTIFICADOR {
		contParam = 0;
	 $2.tipoDato = NO_ASIG;
	 $2.parametros = 0;
	 estado = inserta($2, PROC);
	 posicion = ultimaPosicion();
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
	contParam++;
	entradaTS temp = devuelveEntrada(posicion);
	temp.parametros++;
	actualiza(posicion,temp);
	$$.tipoDato = $1.tipoDato;
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
//printf("buscando %s para comparar\n", $1.nombre );
int posicion = buscaEnTs($1);
if(posicion==-1){
	printf("[ERR] Error linea: %d ASIGNACION ", linea_actual);
	printf("variable no definida\n");
}
	else{
		entradaTS  temp = devuelveEntrada(posicion);
		tipoTemp = temp.tipoDato;

		//printf("Comparando %s tipoIzq: %d, tipoder: %d\n",temp.nombre,temp.tipoDato,$3.tipoDato);
		if ( tipoTemp != $3.tipoDato ) {
			printf("[ERR] Error linea: %d ASIGNACION ", linea_actual);
			printf("tipos no coinciden dato izq = %d, der = %d\n",tipoTemp,$3.tipoDato);
			}

	}
}
;

sentencia_if : CONDSI ABRIRPARENT expresion CERRARPARENT Sentencia { if($3.tipoDato != BOOLEANO ) printf("Fallo tipo de condicional\n");}
	| CONDSI ABRIRPARENT expresion CERRARPARENT Sentencia CONDSINO Sentencia { if($3.tipoDato != BOOLEANO ) printf("Fallo tipo de condicional\n");}
	;

sentencia_while : CONDMIENTRAS ABRIRPARENT expresion CERRARPARENT Sentencia { if($3.tipoDato != BOOLEANO ) printf("Fallo tipo de condicional\n");} ;

sentencia_entrada : LEE Identificadores PUNTOCOMA

;

sentencia_salida : ESCRIBE lista_expresiones_o_cadena PUNTOCOMA ;

expcad : expresion
	| T_CADENA
  ;

lista_expresiones_o_cadena : expcad
	| lista_expresiones_o_cadena COMA expcad  ;

llamada_proced : IDENTIFICADOR {
	contParam = 0;
	posicion = busca($1);
}
ABRIRPARENT  lista_expresiones  CERRARPARENT PUNTOCOMA
{
	if(posicion == -1){
		printf("Procedimiento no definido: %s\n" , $1.nombre );
	} else{
		 entradaTS temp = devuelveEntrada(posicion);
		 printf("Llamada Procedimiento:  %s , %d\n", temp.nombre, temp.parametros );
		 //muestra();
		 if( temp.parametros == contParam){

		 }else{
				printf("Numero de expresiones erroneo: %s ,%d,%d \n", $1.nombre, temp.parametros ,contParam );
		 }
	 }
}
;

sentencia_for : DURANTE IDENTIFICADOR DOSPUNTOSIGUAL  expresion HASTA expresion HACER Sentencia
{
			if (($4.tipoDato == ENTERO) && ($6.tipoDato==$4.tipoDato) ){

			} else {

				fprintf(stderr, "ERROR linea: %d \n ", linea_actual);
				fprintf(stderr, "Op con tipo de dato incorrecto \n");

				$$.tipoDato = DESC;
				}
}

 ;

expresion : ABRIRPARENT expresion CERRARPARENT{
						$$ = $2;
						}
  | MASMENOS expresion %prec EXCLAMACION
	{
				if ( ($2.tipoDato != BOOLEANO)
					&& ($2.tipoDato != LISTA_BOOLEANO) ) {

					$$.tipoDato = $2.tipoDato;

				} else {

					fprintf(stderr, "ERROR linea: %d \n ", linea_actual);
					fprintf(stderr, "Op con tipo de dato incorrecto \n");

					$$.tipoDato = DESC;
					}
		}
	| UNARIOSLISTA expresion
	{
				if ($2.tipoDato > CARACTER) {

					$$.tipoDato = $2.tipoDato;

				} else {

					fprintf(stderr, "ERROR linea: %d \n ", linea_actual);
					fprintf(stderr, "Op con tipo de dato incorrecto \n");

					$$.tipoDato = DESC;
					}
	}
	| MASMAS expresion
	{
				if ($2.tipoDato > CARACTER) {

					$$.tipoDato = $2.tipoDato;

				} else {

					fprintf(stderr, "ERROR linea: %d \n ", linea_actual);
					fprintf(stderr, "Op con tipo de dato incorrecto \n");

					$$.tipoDato = DESC;
					}
	}
	| MENOSMENOS expresion
	{
				if ($2.tipoDato > CARACTER) {

					$$.tipoDato = $2.tipoDato;

				} else {

					fprintf(stderr, "ERROR linea: %d \n ", linea_actual);
					fprintf(stderr, "Op con tipo de dato incorrecto \n");

					$$.tipoDato = DESC;
					}
	}
	| EXCLAMACION expresion
	{
				if ($2.tipoDato == BOOLEANO) {

					$$.tipoDato = $2.tipoDato;

				} else {

					fprintf(stderr, "ERROR linea: %d \n ", linea_actual);
					fprintf(stderr, "Op con tipo de dato incorrecto \n");

					$$.tipoDato = DESC;
					}
	}
	| expresion AVANRETRO
	{
		{
					if ($1.tipoDato > CARACTER) {

						$$.tipoDato = $1.tipoDato;

					} else {

						fprintf(stderr, "ERROR linea: %d \n ", linea_actual);
						fprintf(stderr, "Op con tipo de dato incorrecto \n");

						$$.tipoDato = DESC;
						}
		}
	}
	| expresion MULMUL expresion{
		{
					if (($1.tipoDato > CARACTER) && ($3.tipoDato == $1.tipoDato)) {

						$$.tipoDato = $1.tipoDato;

					} else {

						fprintf(stderr, "ERROR linea: %d \n ", linea_actual);
						fprintf(stderr, "Op con tipo de dato incorrecto \n");

						$$.tipoDato = DESC;
						}
		}
	}
	| expresion MULTIDIV expresion
	{
		if ( $1.tipoDato == $3.tipoDato ) {


			if ( ($1.tipoDato != BOOLEANO)
				&& ($1.tipoDato != LISTA_BOOLEANO) ) {

				$$.tipoDato = $1.tipoDato;

			} else {

				fprintf(stderr, "ERROR linea: %d \n ", linea_actual);
				fprintf(stderr, "Op * o /  con tipo de dato");
				fprintf(stderr, "incorrecto");

				$$.tipoDato = DESC;
				}
		} else {

			fprintf(stderr, "ERROR linea: %d * o /", linea_actual);
			fprintf(stderr, " Tipos no coinciden \n");
			$$.tipoDato = DESC;
			}
	}
	| expresion LOGAND expresion
	{
				if (($1.tipoDato == BOOLEANO) && ($3.tipoDato == $1.tipoDato) ) {

					$$.tipoDato = $1.tipoDato;

				} else {

					fprintf(stderr, "ERROR linea: %d \n ", linea_actual);
					fprintf(stderr, "Op con tipo de dato incorrecto \n");

					$$.tipoDato = DESC;
					}
	}
	| expresion EXOR expresion
	{
				if (($1.tipoDato == BOOLEANO) && ($3.tipoDato == $1.tipoDato) ) {

					$$.tipoDato = $1.tipoDato;

				} else {

					fprintf(stderr, "ERROR linea: %d \n ", linea_actual);
					fprintf(stderr, "Op con tipo de dato incorrecto \n");

					$$.tipoDato = DESC;
					}
	}
	| expresion ORBIT expresion
	{
				if (($1.tipoDato == BOOLEANO) && ($3.tipoDato == $1.tipoDato) ) {

					$$.tipoDato = $1.tipoDato;

				} else {

					fprintf(stderr, "ERROR linea: %d \n ", linea_actual);
					fprintf(stderr, "Op con tipo de dato incorrecto \n");

					$$.tipoDato = DESC;
					}
	}
	| expresion LOGOR expresion
	{
				if (($1.tipoDato == BOOLEANO) && ($3.tipoDato == $1.tipoDato) ) {

					$$.tipoDato = $1.tipoDato;

				} else {

					fprintf(stderr, "ERROR linea: %d \n ", linea_actual);
					fprintf(stderr, "Op con tipo de dato incorrecto \n");

					$$.tipoDato = DESC;
					}
	}
	| expresion REL expresion
	{
		if ( ($1.tipoDato < BOOLEANO) && ($3.tipoDato < BOOLEANO) ) {

			if ( ($1.tipoDato > DESC) && ($3.tipoDato > DESC)  ) {

				$$.tipoDato = BOOLEANO;

			} else {

				fprintf(stderr, "ERROR linea: %d \n ", linea_actual);
				fprintf(stderr, "Op +/- con tipo de dato");
				fprintf(stderr, "incorrecto\n");

				$$.tipoDato = DESC;
				}
		} else {

			fprintf(stderr, "ERROR linea: %d +/-", linea_actual);
			fprintf(stderr, " Tipos no coinciden \n");
			$$.tipoDato = DESC;
			}
	}
	| expresion IGUALDAD expresion
	{
		if( ($1.tipoDato < LISTA_REAL) && ($3.tipoDato == $1.tipoDato)   ) {

				$$.tipoDato = BOOLEANO;

			} else {

				fprintf(stderr, "ERROR linea: %d \n ", linea_actual);
				fprintf(stderr, "Op +/- con tipo de dato");
				fprintf(stderr, "incorrecto\n");

				$$.tipoDato = DESC;
			}
	}
	| expresion PORCENTAJE expresion
	{
				if (($1.tipoDato > CARACTER) && ($3.tipoDato == ENTERO)) {

					$$.tipoDato = $1.tipoDato;

				} else {

					fprintf(stderr, "ERROR linea: %d \n ", linea_actual);
					fprintf(stderr, "Op con tipo de dato incorrecto \n");

					$$.tipoDato = DESC;
					}
	}
	| expresion ANDBIT expresion
	{
				if (($1.tipoDato == BOOLEANO) && ($3.tipoDato == $1.tipoDato) ) {

					$$.tipoDato = $1.tipoDato;

				} else {

					fprintf(stderr, "ERROR linea: %d \n ", linea_actual);
					fprintf(stderr, "Op con tipo de dato incorrecto \n");

					$$.tipoDato = DESC;
					}
	}
	| expresion MASMENOS expresion
	{
		if ( ($1.tipoDato < BOOLEANO) && ($3.tipoDato < BOOLEANO) ) {

			if ( ($1.tipoDato > DESC) && ($3.tipoDato > DESC)  ) {

				if(($1.tipoDato == REAL) || ($3.tipoDato == REAL))
					$$.tipoDato = REAL;
				else
					$$.tipoDato == $1.tipoDato;

			} else {

				fprintf(stderr, "ERROR linea: %d \n ", linea_actual);
				fprintf(stderr, "Op +/- con tipo de dato");
				fprintf(stderr, "incorrecto\n");

				$$.tipoDato = DESC;
				}
		} else {

			fprintf(stderr, "ERROR linea: %d +/-", linea_actual);
			fprintf(stderr, " Tipos no coinciden \n");
			$$.tipoDato = DESC;
			}
	}
	| expresion MASMAS expresion ARROBA expresion
	{
				if ($1.tipoDato > CARACTER) {

					switch ($3.tipoDato) {
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
					if(tempTipoDato == $1.tipoDato){
						if($5.tipoDato != ENTERO){
							fprintf(stderr, "ERROR linea: %d \n ", linea_actual);
							fprintf(stderr, "Posicion no valida \n");
							$$.tipoDato = DESC;

						}else{
							$$.tipoDato = $1.tipoDato;
						}
					}else{
						fprintf(stderr, "ERROR linea: %d \n ", linea_actual);
						fprintf(stderr, "Valor distinto tipo de dato de lista \n");
						$$.tipoDato = DESC;
					}
				} else {

					fprintf(stderr, "ERROR linea: %d \n ", linea_actual);
					fprintf(stderr, "Op con tipo de dato incorrecto \n");

					$$.tipoDato = DESC;
					}
	}
	| IDENTIFICADOR {
		int posicion2 = buscaEnTs($1);
		if(posicion2 == -1){
			fprintf(stderr, "ERROR linea: %d Variable no definida: [%s]  \n", linea_actual,$1.nombre);
}else {
	entradaTS temp = devuelveEntrada(posicion2); $$.tipoDato = temp.tipoDato; }
}
	| T_REAL {$$.tipoDato = $1.tipoDato; }
	| T_ENTERO {$$.tipoDato = $1.tipoDato; }
	| T_CARACTER {$$.tipoDato = $1.tipoDato; }
	| VERDFALS {$$.tipoDato = $1.tipoDato; }
  | lista {$$.tipoDato = $1.tipoDato; }
  |	error_expresion	;
error_expresion : error ;

lista_expresiones : lista_expresiones COMA expresion
{
	contParam++;
	entradaTS temp = devuelveEntrada(posicion + contParam );
	if(temp.tipoDato != $3.tipoDato){
		printf("[ERR] Error linea: %d", linea_actual);
		printf("Tipo param erroneo: %d ,%d ,%d \n", temp.tipoDato, $3.tipoDato, contParam );

	}

}
 | expresion
 {
 	contParam++;
 	entradaTS temp = devuelveEntrada(posicion + contParam );
 	if(temp.tipoDato != $1.tipoDato){

		printf("[ERR] Error linea: %d", linea_actual);
		printf("Tipo param erroneo: %d ,%d ,%d \n", temp.tipoDato, $1.tipoDato, contParam );
	}
 }
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


void yyerror(const char *msg)
{
	printf("[Linea %d]: %s\n", linea_actual,msg);
}

#include "main.c"
