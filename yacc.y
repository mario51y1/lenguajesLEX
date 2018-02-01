%{
	#include <stdio.h>
	#include <string.h>

	#include "ts.h"

	#define semantico 

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

%right ARROBA
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


%%

//#if defined semantico
//Pagina 45 pdf de practicas - simplificar BNF

Programa : Cabecera_programa bloque 

		{
		#if defined semantico
			muestra();printf("Compilacion Terminada\n");
		#endif
		}
		;

bloque : Inicio_de_bloque

	{
	#if defined semantico
		yylval.tipoDato = NO_ASIG;
		yylval.nombre = strdup("INIBLOQUE");
		inserta(yylval, MARCA);
		#endif
		}

	Declar_de_variables_locales
	Declar_de_subprogs
	Sentencias
	Fin_de_bloque

	{
	#if defined semantico
		eliminarHastaMarca();//muestra();
		#endif
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
	#if defined semantico
		$2.tipoDato = NO_ASIG;
		inserta($2, PROC);
		#endif
		}
;



Cabecera_subprograma : PROCED IDENTIFICADOR 

	{
	#if defined semantico
		contParam = 0;
		$2.tipoDato = NO_ASIG;
		$2.parametros = 0;
		estado = inserta($2, PROC);
		posicion = ultimaPosicion();
		#endif
		}
 ABRIRPARENT parametros CERRARPARENT

| PROCED error_subprog ;
error_subprog : error

	{
	#if defined semantico 	
		printf("[Error SÍNTÁCTICO: linea %d] Error creación de subprograma ", linea_actual);
	
	#endif
	}

parametros : parametro
	| parametros COMA parametro
	|
  ;
parametro : tipo IDENTIFICADOR

	{
	#if defined semantico
		contParam++;
		entradaTS temp = devuelveEntrada(posicion);
		temp.parametros++;
		actualiza(posicion,temp);
		$$.tipoDato = $1.tipoDato;
		$2.tipoDato = $1.tipoDato;
		estado = inserta($2, PAR_FORMAL);
	#endif
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

error_decl_variables : error
	
	{
	#if defined semantico 
		printf("[Error SÍNTÁCTICO: linea %d] Error declaración de variables ", linea_actual);
	#endif
	}
	;

Identificadores : IDENTIFICADOR
	{
	#if defined semantico
		
		$1.tipoDato = tempTipoDato;
		estado = inserta($1, VARIABLE);
	#endif
	}

	| Identificadores COMA IDENTIFICADOR
			{
		#if defined semantico
			$3.tipoDato = tempTipoDato;
			estado = inserta($3, VARIABLE);
		#endif
		}
	;

tipo : TIPO 

	{
	#if defined semantico
		tempTipoDato = $1.tipoDato;} | tipo_lista  ;
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
	#endif
	}
	;

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
	#if defined semantico

		//printf("buscando %s para comparar\n", $1.nombre );
		int posicion = buscaEnTs($1);
		if(posicion==-1){
		printf("[Error SEMÁNTICO: linea %d] ASIGNACION ", linea_actual);
		printf("variable no definida\n");
		}
		else{
			entradaTS  temp = devuelveEntrada(posicion);
			tipoTemp = temp.tipoDato;

			//printf("Comparando %s tipoIzq: %d, tipoder: %d\n",temp.nombre,temp.tipoDato,$3.tipoDato);
			if ( tipoTemp != $3.tipoDato ) {
				printf("[Error SEMÁNTICO: linea %d] ASIGNACION ", linea_actual);
				printf("tipos no coinciden dato izq = %d, der = %d\n",tipoTemp,$3.tipoDato);
				}

		}
	#endif
	}
;

sentencia_if : CONDSI ABRIRPARENT expresion CERRARPARENT Sentencia
	
	{
	#if defined semantico	
		if($3.tipoDato != BOOLEANO ) printf("[Error SEMÁNTICO: linea %d] Condicional no booleana\n",linea_actual);
	#endif
	}

	| CONDSI ABRIRPARENT expresion CERRARPARENT Sentencia CONDSINO Sentencia
	
	{
	#if defined semantico
		if($3.tipoDato != BOOLEANO ) printf("[Error SEMÁNTICO: linea %d] Condicional no booleana\n",linea_actual);
	#endif
	}
	;

sentencia_while : CONDMIENTRAS ABRIRPARENT expresion CERRARPARENT Sentencia
	
	{
	#if defined semantico
		if($3.tipoDato != BOOLEANO ) printf("[Error SEMÁNTICO: linea %d] Condicional no booleana\n",linea_actual);
	#endif
	}
	;

sentencia_entrada : LEE Identificadores PUNTOCOMA

;

sentencia_salida : ESCRIBE lista_expresiones_o_cadena PUNTOCOMA ;

expcad : expresion
	| T_CADENA
  ;

lista_expresiones_o_cadena : expcad
	| lista_expresiones_o_cadena COMA expcad  ;

llamada_proced : IDENTIFICADOR 
	
	{
	#if defined semantico
		contParam = 0;
		posicion = busca($1);
	#endif
	}
	;

| ABRIRPARENT  lista_expresiones  CERRARPARENT PUNTOCOMA

	{
	#if defined semantico
		if(posicion == -1){
			printf("[Error SEMÁNTICO: linea %d] Procedimiento no definido: %s\n" ,linea_actual, $1.nombre );
		} else{
			 entradaTS temp = devuelveEntrada(posicion);
			 printf("Llamada Procedimiento:  %s , %d\n", temp.nombre, temp.parametros );
			 //muestra();
			 if( temp.parametros == contParam){

			 }else{
					printf("[Error SEMANTICO: linea %d] Numero de expresiones erroneo: %s ,%d,%d \n",linea_actual, $1.nombre, temp.parametros ,contParam );
					$$.tipoDato = DESC;
			 }
		 }
	#endif
	}
	;

sentencia_for : DURANTE IDENTIFICADOR DOSPUNTOSIGUAL  expresion HASTA expresion HACER Sentencia

	{
	#if defined semantico
		if (($4.tipoDato == ENTERO) && ($6.tipoDato==$4.tipoDato) ){

		} else {

			fprintf(stderr, "[Error SEMÁNTICO: linea %d] \n ", linea_actual);
			fprintf(stderr, "Op con tipo de dato incorrecto \n");

			$$.tipoDato = DESC;
			}
	#endif
	}
 	;

expresion : ABRIRPARENT expresion CERRARPARENT

	{
	#if defined semantico
		$$ = $2;
	#endif
	}

 	| MASMENOS expresion %prec EXCLAMACION
	
	{
	#if defined semantico
		if ( ($2.tipoDato != BOOLEANO)
			&& ($2.tipoDato != LISTA_BOOLEANO) ) {

			$$.tipoDato = $2.tipoDato;

		} else {

			fprintf(stderr, "[Error SEMÁNTICO: linea %d] \n ", linea_actual);
			fprintf(stderr, "Op con tipo de dato incorrecto \n");

			$$.tipoDato = DESC;
			}
	#endif
	}

	| UNARIOSLISTA expresion
	
	{
	#if defined semantico
		if ($2.tipoDato > CARACTER) {
			switch ($1.dif) {
				case 0:
					$$.tipoDato = ENTERO;
				break;
				case 1:
					$$.tipoDato = listaASimple($2.tipoDato);
				break;
				case 2:
					$$.tipoDato = $2.tipoDato;
				break;
				default:
					$$.tipoDato = DESC;
				break;
			}
		} else {

			fprintf(stderr, "[Error SEMÁNTICO: linea %d] \n ", linea_actual);
			fprintf(stderr, "Op con tipo de dato incorrecto \n");

			$$.tipoDato = DESC;
			}
	#endif
	}

	| MASMAS expresion

	{
	#if defined semantico
		if ($2.tipoDato > CARACTER) {
			$$.tipoDato = $2.tipoDato;

		} else {

			fprintf(stderr, "[Error SEMÁNTICO: linea %d] \n ", linea_actual);
			fprintf(stderr, "Op con tipo de dato incorrecto \n");

			$$.tipoDato = DESC;
			}
	#endif
	}
	
	| expresion MENOSMENOS expresion

	{
	#if defined semantico
		if ($1.tipoDato > CARACTER) {

			if($3.tipoDato == ENTERO){
				$$.tipoDato = $1.tipoDato;

			}else{
				fprintf(stderr, "[Error SEMÁNTICO: linea %d] \n ", linea_actual);
				fprintf(stderr, "No es un entero\n");
				$$.tipoDato = DESC;
			}
		} else {

			fprintf(stderr, "[Error SEMÁNTICO: linea %d] \n ", linea_actual);
			fprintf(stderr, "No es una lista\n");

			$$.tipoDato = DESC;
		}
	#endif
	}
	
	| EXCLAMACION expresion

	{
	#if defined semantico
		if ($2.tipoDato == BOOLEANO) {

			$$.tipoDato = $2.tipoDato;

		} else {

			fprintf(stderr, "[Error SEMÁNTICO: linea %d] \n ", linea_actual);
			fprintf(stderr, "Op con tipo de dato incorrecto \n");

			$$.tipoDato = DESC;
		}
	#endif
	}

	| expresion AVANRETRO
	
	{
	#if defined semantico
		{
			if ($1.tipoDato > CARACTER) {

				$$.tipoDato = $1.tipoDato;

			} else {

				fprintf(stderr, "[Error SEMÁNTICO: linea %d] \n ", linea_actual);
				fprintf(stderr, "Op con tipo de dato incorrecto \n");

				$$.tipoDato = DESC;
			}
		}
	#endif
	}

	| expresion ARROBA expresion

	{
	#if defined semantico
		if ($1.tipoDato > CARACTER){

			if($3.tipoDato == ENTERO){
				$$.tipoDato = listaASimple($1.tipoDato);
			} else {
				fprintf(stderr, "[Error SEMÁNTICO: linea %d] \n ", linea_actual);
				fprintf(stderr, " Debe ser entero para acceder a posicion \n");
				$$.tipoDato = DESC;
			}

		}else{
			fprintf(stderr, "[Error SEMÁNTICO: linea %d] \n ", linea_actual);
			fprintf(stderr, "No es una lista %s \n",$1.nombre);
			$$.tipoDato = DESC;

		}
	#endif
	}

	| expresion MULMUL expresion

	{
	#if defined semantico	
		if (($1.tipoDato > CARACTER) && ($3.tipoDato == $1.tipoDato)) {

			$$.tipoDato = $1.tipoDato;

		} else {

			fprintf(stderr, "[Error SEMÁNTICO: linea %d] \n ", linea_actual);
			fprintf(stderr, "Op con tipo de dato incorrecto \n");

			$$.tipoDato = DESC;
		}
	#endif
	}

	| expresion MULTIDIV expresion

	{
	#if defined semantico
		if ($1.tipoDato == LISTA_ENTERO || $1.tipoDato == LISTA_REAL){

			if($3.tipoDato == REAL){
				$$.tipoDato == LISTA_REAL;
			} else if ($3.tipoDato == ENTERO) {
				$$.tipoDato = $1.tipoDato;
			} else {
				fprintf(stderr, "[Error SEMÁNTICO: linea %d] \n ", linea_actual);
				fprintf(stderr, " Tipos no coinciden \n");
				$$.tipoDato = DESC;
			}

		} else if ($1.tipoDato == REAL || $1.tipoDato == ENTERO) {
			if ($2.dif = 0) {
				if ($3.tipoDato == $1.tipoDato) {
					$$.tipoDato = $1.tipoDato;
				} else if ($3.tipoDato == REAL){
					$$.tipoDato == REAL;
				} else if ($3.tipoDato == LISTA_ENTERO || $3.tipoDato == LISTA_REAL) {
					if ($1.tipoDato == ENTERO){
						$$.tipoDato = $3.tipoDato;
					} else {
						$$.tipoDato = LISTA_REAL;
					}
				} else {
					fprintf(stderr, "[Error SEMÁNTICO: linea %d] \n ", linea_actual);
					fprintf(stderr, " Tipos no coinciden \n");
					$$.tipoDato = DESC;
				}

			} else {
				if ($3.tipoDato == $1.tipoDato) {
					$$.tipoDato = $1.tipoDato;
				} else if ($3.tipoDato == REAL){
					$$.tipoDato == REAL;
				} else {
					fprintf(stderr, "[Error SEMÁNTICO: linea %d] \n ", linea_actual);
					fprintf(stderr, " Tipos no coinciden \n");
					$$.tipoDato = DESC;
				}
			}
		} else {

			fprintf(stderr, "[Error SEMÁNTICO: linea %d] \n ", linea_actual);
			fprintf(stderr, " Tipos no coinciden \n");
			$$.tipoDato = DESC;
		}
	#endif
	}

	| expresion LOGAND expresion

	{
	#if defined semantico
		if (($1.tipoDato == BOOLEANO) && ($3.tipoDato == $1.tipoDato) ) {

			$$.tipoDato = $1.tipoDato;

		} else {

			fprintf(stderr, "[Error SEMÁNTICO: linea %d] \n ", linea_actual);
			fprintf(stderr, "Op con tipo de dato incorrecto \n");

			$$.tipoDato = DESC;
		}
	#endif
	}

	| expresion EXOR expresion

	{
	#if defined semantico

		if (($1.tipoDato == BOOLEANO) && ($3.tipoDato == $1.tipoDato) ) {

			$$.tipoDato = $1.tipoDato;

		} else {

			fprintf(stderr, "[Error SEMÁNTICO: linea %d] \n ", linea_actual);
			fprintf(stderr, "Op con tipo de dato incorrecto \n");

			$$.tipoDato = DESC;
		}
	#endif
	}

	| expresion ORBIT expresion

	{
	#if defined semantico
				if (($1.tipoDato == BOOLEANO) && ($3.tipoDato == $1.tipoDato) ) {

					$$.tipoDato = $1.tipoDato;

				} else {

					fprintf(stderr, "[Error SEMÁNTICO: linea %d] \n ", linea_actual);
					fprintf(stderr, "Op con tipo de dato incorrecto \n");

					$$.tipoDato = DESC;
					}
	#endif
	}

	| expresion LOGOR expresion

	{
	#if defined semantico
				if (($1.tipoDato == BOOLEANO) && ($3.tipoDato == $1.tipoDato) ) {

					$$.tipoDato = $1.tipoDato;

				} else {

					fprintf(stderr, "[Error SEMÁNTICO: linea %d] \n ", linea_actual);
					fprintf(stderr, "Op con tipo de dato incorrecto \n");

					$$.tipoDato = DESC;
					}
	#endif
	}

	| expresion REL expresion

	{
	#if defined semantico
		if ( ($1.tipoDato < BOOLEANO) && ($3.tipoDato < BOOLEANO) ) {

			if ( ($1.tipoDato > DESC) && ($3.tipoDato > DESC)  ) {

				$$.tipoDato = BOOLEANO;

			} else {

				fprintf(stderr, "[Error SEMÁNTICO: linea %d] \n ", linea_actual);
				fprintf(stderr, "Op +/- con tipo de dato");
				fprintf(stderr, "incorrecto\n");

				$$.tipoDato = DESC;
				}
		} else {

			fprintf(stderr, "[Error SEMÁNTICO: linea %d] \n ", linea_actual);
			fprintf(stderr, " Tipos no coinciden \n");
			$$.tipoDato = DESC;
			}
	#endif
	}

	| expresion IGUALDAD expresion

	{
	#if defined semantico
		if( ($1.tipoDato < LISTA_REAL) && ($3.tipoDato == $1.tipoDato)   ) {

				$$.tipoDato = BOOLEANO;

			} else {

				fprintf(stderr, "[Error SEMÁNTICO: linea %d] \n ", linea_actual);
				fprintf(stderr, "Op +/- con tipo de dato");
				fprintf(stderr, "incorrecto\n");

				$$.tipoDato = DESC;
			}
	#endif
	}

	| expresion PORCENTAJE expresion

	{
	#if defined semantico
		if (($1.tipoDato > CARACTER) && ($3.tipoDato == ENTERO)) {

			$$.tipoDato = $1.tipoDato;

		} else {

			fprintf(stderr, "[Error SEMÁNTICO: linea %d] \n ", linea_actual);
			fprintf(stderr, "Op con tipo de dato incorrecto \n");

			$$.tipoDato = DESC;
		}
	#endif
	}

	| expresion ANDBIT expresion

	{
	#if defined semantico
				if (($1.tipoDato == BOOLEANO) && ($3.tipoDato == $1.tipoDato) ) {

					$$.tipoDato = $1.tipoDato;

				} else {

					fprintf(stderr, "[Error SEMÁNTICO: linea %d] \n ", linea_actual);
					fprintf(stderr, "Op con tipo de dato incorrecto \n");

					$$.tipoDato = DESC;
					}
	#endif
	}

	| expresion MASMENOS expresion

	{
	#if defined semantico
		if ($1.tipoDato == LISTA_ENTERO || $1.tipoDato == LISTA_REAL){


			if($3.tipoDato == REAL){
				$$.tipoDato == LISTA_REAL;
			} else if ($3.tipoDato == ENTERO) {
				$$.tipoDato = $1.tipoDato;
			} else {
				fprintf(stderr, "[Error SEMÁNTICO: linea %d] \n ", linea_actual);
				fprintf(stderr, " Tipos no coinciden \n");
				$$.tipoDato = DESC;
			}

			//fprintf(stderr, "[EEEEE]izq %d der %d / \n", $1.tipoDato,$3.tipoDato);


		} else if ($1.tipoDato == REAL || $1.tipoDato == ENTERO) {
			if ($2.dif == 0) {
				if ($3.tipoDato == $1.tipoDato) {
					$$.tipoDato = $1.tipoDato;
				} else if ($3.tipoDato == REAL){
					$$.tipoDato == REAL;
				} else if ($3.tipoDato == LISTA_ENTERO || $3.tipoDato == LISTA_REAL) {
					if ($1.tipoDato == ENTERO){
						$$.tipoDato = $3.tipoDato;
					} else {
						$$.tipoDato = LISTA_REAL;
					}
				} else {
					fprintf(stderr, "[Error SEMÁNTICO: linea %d] \n ", linea_actual);
					fprintf(stderr, " Tipos no coinciden \n");
					$$.tipoDato = DESC;
				}

			} else {
				if ($3.tipoDato == $1.tipoDato) {
					$$.tipoDato = $1.tipoDato;
				} else if ($3.tipoDato == REAL){
					$$.tipoDato == REAL;
				} else {
					fprintf(stderr, "[Error SEMÁNTICO: linea %d] \n ", linea_actual);
					fprintf(stderr, " Orden incorrecto \n");
					$$.tipoDato = DESC;
				}
			}
		}
	#endif
	}

	| expresion MASMAS expresion ARROBA expresion

	{
	#if defined semantico
		if ($1.tipoDato > CARACTER) {
			if($3.tipoDato == listaASimple($1.tipoDato)){
				if($5.tipoDato == ENTERO){
					$$.tipoDato = $1.tipoDato;
				}else{
					fprintf(stderr, "[Error SEMÁNTICO: linea %d] \n ", linea_actual);

					fprintf(stderr, "Valor distinto de entero: [%s]  \n", linea_actual,$5.nombre);
				}
			}else{
				fprintf(stderr, "[Error SEMÁNTICO: linea %d] \n ", linea_actual);

				fprintf(stderr, "Valor distinto de lista: [%s]  \n", linea_actual,$3.nombre);
			}
		}else{
			fprintf(stderr, "[Error SEMÁNTICO: linea %d] \n ", linea_actual);

			fprintf(stderr, "No es una lista: [%s]  \n", linea_actual,$1.nombre);

		}
	#endif
	}

	| IDENTIFICADOR 

	{
	#if defined semantico
		int posicion2 = buscaEnTs($1);
		if(posicion2 == -1){
			fprintf(stderr, "[Error SEMÁNTICO: linea %d] \n ", linea_actual);

			fprintf(stderr, "Variable no definida: [%s]  \n", linea_actual,$1.nombre);
		}else {
			entradaTS temp = devuelveEntrada(posicion2); $$.tipoDato = temp.tipoDato; }
	#endif
	}
	
	| T_REAL 

	{
	#if defined semantico
	$$.tipoDato = $1.tipoDato; 
	#endif
	}

	| T_ENTERO 

	{
	#if defined semantico
	$$.tipoDato = $1.tipoDato; 
	#endif
	}

	| T_CARACTER 

	{
	#if defined semantico
	$$.tipoDato = $1.tipoDato;
	#endif
	}

	| VERDFALS 	

	{
	#if defined semantico
	$$.tipoDato = $1.tipoDato; 
	#endif
	}

	| lista 

	{
	#if defined semantico
	$$.tipoDato = $1.tipoDato; 
	#endif
	}

  |	error_expresion	;

error_expresion : error ;

lista_expresiones : lista_expresiones COMA expresion

	{
	#if defined semantico
		contParam++;
		entradaTS temp = devuelveEntrada(posicion + contParam );
		if(temp.tipoDato != $3.tipoDato){

			fprintf(stderr, "[Error SEMÁNTICO: linea %d] \n ", linea_actual);

			printf("Tipo param erroneo: %d ,%d ,%d \n", temp.tipoDato, $3.tipoDato, contParam );

		}
	#endif
	}

 	| expresion

	{
	#if defined semantico
	 	contParam++;
	 	entradaTS temp = devuelveEntrada(posicion + contParam );
	 	if(temp.tipoDato != $1.tipoDato){

			fprintf(stderr, "[Error SEMÁNTICO: linea %d] \n ", linea_actual);

			printf("Tipo param erroneo: %d ,%d ,%d \n", temp.tipoDato, $1.tipoDato, contParam );
		}
	#endif
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
	printf("[Error : linea %d]: %s\n", linea_actual,msg);
}

#include "main.c"
