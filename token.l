%{
#include <stdlib.h>
#include <string.h>
#include "tabla.h"
%}
%%

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

"lista_de"	return DEFLIST;

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

\'[^\']\'	return CARACTER;
\"[^\"]*\"	return CADENA;

%%

main() {
  	
	int val;
  
	val = yylex();
	while (val!=0)
		printf(" %d \n", val);
		val = yylex();
	exit(0);
  
 	 
}
