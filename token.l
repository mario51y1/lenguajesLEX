
%option	noyywrap
option yylineno

%{

	//yylval.lexema = strdup(yytext);


#include <string.h>
#include <stdio.h>

#include "y.tab.h"

#include "ts.h"

#define MAXLONBUFFER 200

tipoEntrada tipoTS;
extern entradaTS yylval;

%}

%%
[ \t]	{};

"\n"	{linea_actual++;}

"["	{return ABRIRCORCH;}

"]"	{return CERRARCORCH;}

"("	{	return ABRIRPARENT;	}

")"	{
	return CERRARPARENT;
	}

"{"	{

	return ABRIRLLAVES;
	}

"}"	{

	return CERRARLLAVES;
	}

";"	{return PUNTOCOMA;}

"**"	{
	return MULMUL;
	}

"/"	{
		// Actualizamos para el siguiente

	yylval.dif = 1;

	return MULTIDIV;
	}

"&&"	{
	return LOGAND;
	}

"^"	{
	return EXOR;
	}

"|"	{

	return ORBIT;
	}

"||"	{
	return LOGOR;
	}

"+="	{
	yylval.dif = 0;


	return IGUALDAD;
	}

"-="	{

	yylval.dif = 1;


	return IGUALDAD;
	}

"=="	{

	yylval.dif = 2;


	return IGUALDAD;
	}

"!="	{

	yylval.dif = 3;


	return IGUALDAD;
	}

"<="	{

	yylval.dif = 0;

	return REL;
	}

">="	{

	yylval.dif = 1;

	return REL;
	}

"<"	{

	yylval.dif = 2;

	return REL;
	}

">"	{

	yylval.dif = 3;

	return REL;
	}

"%"	{return PORCENTAJE;}

"*"	{

	yylval.dif = 0;

	return MULTIDIV;
	}

"&"	{

	return ANDBIT;
	}

"--"	{return MENOSMENOS;}
"!"	{

	return EXCLAMACION;
	}

"#"	{yylval.dif=0;return UNARIOSLISTA;}
"?"	{yylval.dif=1;return UNARIOSLISTA;}
"$"	{yylval.dif=2;return UNARIOSLISTA;}

">>"	{yylval.dif=0;return AVANRETRO;}
"<<"	{yylval.dif=1;return AVANRETRO;}

"+"	{
	yylval.dif = 0;

	return MASMENOS;
	}

"-"	{
	yylval.dif = 1;

	return MASMENOS;
	}

"++"	{return MASMAS;}

"@"	{return ARROBA;}

","	{return COMA;}
"="	{return ASIG;}
":="	{return DOSPUNTOSIGUAL;}

"lee"	{
	return LEE;
	}

"escribe"	{
			return ESCRIBE;
		}

"durante"	{return DURANTE;}

"si"	{
	return CONDSI;
	}

"mientras"	{return CONDMIENTRAS;}

"sino"	{	return CONDSINO;
	}

"hasta"	{return HASTA;}
"hacer"	{return HACER;}

"lista_de "	{return DEFLIST;}

"booleano"	{
		yylval.tipoDato = BOOLEANO;
		return TIPO;
		}
"real"	{
	yylval.tipoDato = REAL;
	return TIPO;
	}

"caracter"	{
		yylval.tipoDato = CARACTER;
		return TIPO;
		}

"entero"	{
		yylval.tipoDato = ENTERO;
		return TIPO;
		}

"principal"	{
	yylval.nombre =  strdup(yytext);
		return MAIN;
		}

"procedimiento"	{
		return PROCED;
		}

"verdadero"	{
		yylval.tipoDato = BOOLEANO;
		yylval.valor.booleano = 1;

		return VERDFALS;
		}

"falso"	{
	yylval.tipoDato = BOOLEANO;
	yylval.valor.booleano = 0;

	return VERDFALS;
	}

"variables"	{

		return INICIOVARS;
		}

"finvariables"	{

		return FINVARS;
		}

[\+\-]?([0-9])+	{

		yylval.tipoDato = ENTERO;
		yylval.valor.entero = atoi(yytext);

		return T_ENTERO;
		}

[\+\-]?([0-9])+\.([0-9])+	{
			yylval.tipoDato = REAL;
			yylval.valor.real = atof(yytext);
			return T_REAL;
		}

[a-zA-Z][a-zA-Z0-9]*	{
					yylval.nombre = strdup(yytext);
					return IDENTIFICADOR;
					}


\'[^\']\'	{

		yylval.tipoDato = CARACTER;

		yylval.valor.caracter = yytext[0];

		return T_CARACTER;
		}

\"[^\"]*\"	{
		return T_CADENA;
		}

. ;
%%
