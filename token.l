%{
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "y.tab.h"

int linea_actual=0;
%}
%%
[ \t\n]	;

"["	return ABRIRCORCH;
"]"	return CERRARCORCH;
"("	return ABRIRPARENT;
")"	return CERRARPARENT;
"{"	return ABRIRLLAVES;
"}"	return CERRARLLAVES;
";"	return PUNTOCOMA;

"**"	return OPBINARIO;
"/"	return OPBINARIO;
"&&"	return OPBINARIO;
"^"	return OPBINARIO;
"|"	return OPBINARIO;
"||"	return OPBINARIO;
"+="	return OPBINARIO;
"-="	return OPBINARIO;
"=="	return OPBINARIO;
"!="	return OPBINARIO;
"<="	return OPBINARIO;
">="	return OPBINARIO;
"<"	return OPBINARIO;
">"	return OPBINARIO;
"%"	return OPBINARIO;
"*"	return OPBINARIO;
"&"	return OPBINARIO;

"--"	return UNARIOSIMPLE;
"!"	return UNARIOSIMPLE;
"#"	return UNARIOSIMPLE;
"?"	return UNARIOSIMPLE;

"+"	return MASMENOS;
"-"	return MASMENOS;
"++"	return MASMAS;

"@"	return ARROBA;

","	return COMA;
"="	return ASIG;
":="	return DOSPUNTOSIGUAL;

"lee"	return LEE;
"escribe"	return ESCRIBE;
"durante"	return DURANTE;

"si"	return CONDSI;
"mientras"	return CONDMIENTRAS;
"sino"	return CONDSINO;

"hasta"	return HASTA;
"hacer"	return HACER;

"lista_de "	return DEFLIST;

"booleano"	return TIPO;
"real"	return TIPO;
"caracter"	return TIPO;
"entero"	return TIPO;

"principal"	return MAIN;
"procedimiento"	return PROCED;
"verdadero"	return VERDFALS;
"falso"	return VERDFALS;

"variables"	return INICIOVARS;
"finvariables"	return FINVARS;

[\+\-]?([0-9])+	return ENTERO;
[\+\-]?([0-9])+\.([0-9])+	return REAL;

\'[^\']\'	return CARACTER;
\"[^\"]*\"	return CADENA;

[a-zA-Z][a-zA-Z0-9]*	return IDENTIFICADOR;
. ;
%%

int main(int argc, char *argv[]) {

	int val;
  	yyin = fopen (argv[1],"rt");
	val = yylex();

	printf(" %d \n", val);

	exit(0);


}
