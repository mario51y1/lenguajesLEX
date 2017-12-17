
%option	noyywrap
option yylineno

%{


#include <string.h>
#include <stdio.h>

#include "y.tab.h"

#include "sefasgen.h"

#define MAXLONBUFFER 200
char buffer[MAXLONBUFFER];

static int linI = 0;
static int linF = 0;
static int colI = 0;
static int colF = 0;


tEntrada tipoTS;
extern stEntrada yylval;

void actualizarLoc(stEntrada *reg, int tamToken);
%}

%%
[ \t]	{colI+=yyleng;};

"\n"	{linea_actual++;	colI += yyleng;}

"["	{ colI += yyleng;return ABRIRCORCH;}

"]"	{ colI += yyleng;return CERRARCORCH;}

"("	{
	colF = colI + yyleng - 1;

		yylval.colIni = colI;
		yylval.colFin = colF;
		yylval.linIni = linI;
		yylval.linFin = linF;

		colI = colF+1;
		colF = colI;

	return ABRIRPARENT;
	}

")"	{
	colF = colI + yyleng - 1;

		yylval.colIni = colI;
		yylval.colFin = colF;
		yylval.linIni = linI;
		yylval.linFin = linF;

		colI = colF+1;
		colF = colI;

	return CERRARPARENT;
	}

"{"	{
	colF = colI + yyleng - 1;

	yylval.colIni = colI;
	yylval.colFin = colF;
	yylval.linIni = linI;
	yylval.linFin = linF;

	// Actualizamos para el siguiente
	colI = colF+1;
	colF = colI;

	return ABRIRLLAVES;
	}

"}"	{
	colF = colI + yyleng - 1;

		yylval.colIni = colI;
		yylval.colFin = colF;
		yylval.linIni = linI;
		yylval.linFin = linF;

		// Actualizamos para el siguiente
		colI = colF+1;
		colF = colI;
	return CERRARLLAVES;
	}

";"	{ colI += yyleng;return PUNTOCOMA;}

"**"	{
	colF = colI + yyleng - 1;

		yylval.colIni = colI;
		yylval.colFin = colF;
		yylval.linIni = linI;
		yylval.linFin = linF;

		// Actualizamos para el siguiente
		colI = colF+1;
		colF = colI;

	return MULMUL;
	}

"/"	{
	colF = colI + yyleng - 1;

		yylval.colIni = colI;
		yylval.colFin = colF;
		yylval.linIni = linI;
		yylval.linFin = linF;

		// Actualizamos para el siguiente
		colI = colF+1;
		colF = colI;
	yylval.lexema = strdup(yytext);
	yylval.nParam = 1;

	return MULTIDIV;
	}

"&&"	{
	colF = colI + yyleng - 1;

			yylval.colIni = colI;
			yylval.colFin = colF;
			yylval.linIni = linI;
			yylval.linFin = linF;

			// Actualizamos para el siguiente
			colI = colF+1;
			colF = colI;
		yylval.lexema = strdup(yytext);

	return LOGAND;
	}

"^"	{
	colF = colI + yyleng - 1;

		yylval.colIni = colI;
		yylval.colFin = colF;
		yylval.linIni = linI;
		yylval.linFin = linF;

		// Actualizamos para el siguiente
		colI = colF+1;
		colF = colI;
	yylval.lexema = strdup(yytext);

	return EXOR;
	}

"|"	{
	colF = colI + yyleng - 1;

		yylval.colIni = colI;
		yylval.colFin = colF;
		yylval.linIni = linI;
		yylval.linFin = linF;

		// Actualizamos para el siguiente
		colI = colF+1;
		colF = colI;
	yylval.lexema = strdup(yytext);

	return ORBIT;
	}

"||"	{
	colF = colI + yyleng - 1;

		yylval.colIni = colI;
		yylval.colFin = colF;
		yylval.linIni = linI;
		yylval.linFin = linF;

		// Actualizamos para el siguiente
		colI = colF+1;
		colF = colI;
	yylval.lexema = strdup(yytext);

	return LOGOR;
	}

"+="	{
	colF = colI + yyleng - 1;

			yylval.colIni = colI;
			yylval.colFin = colF;
			yylval.linIni = linI;
			yylval.linFin = linF;

			// Actualizamos para el siguiente
			colI = colF+1;
			colF = colI;
	yylval.nParam = 0;
	yylval.lexema = strdup(yytext);

	return IGUALDAD;
	}

"-="	{
	colF = colI + yyleng - 1;

			yylval.colIni = colI;
			yylval.colFin = colF;
			yylval.linIni = linI;
			yylval.linFin = linF;

			// Actualizamos para el siguiente
			colI = colF+1;
			colF = colI;
	yylval.nParam = 1;
	yylval.lexema = strdup(yytext);

	return IGUALDAD;
	}

"=="	{
	colF = colI + yyleng - 1;

			yylval.colIni = colI;
			yylval.colFin = colF;
			yylval.linIni = linI;
			yylval.linFin = linF;

			// Actualizamos para el siguiente
			colI = colF+1;
			colF = colI;
	yylval.nParam = 2;
	yylval.lexema = strdup(yytext);

	return IGUALDAD;
	}

"!="	{
	colF = colI + yyleng - 1;

			yylval.colIni = colI;
			yylval.colFin = colF;
			yylval.linIni = linI;
			yylval.linFin = linF;

			// Actualizamos para el siguiente
			colI = colF+1;
			colF = colI;
	yylval.nParam = 3;
	yylval.lexema = strdup(yytext);

	return IGUALDAD;
	}

"<="	{
	colF = colI + yyleng - 1;

			yylval.colIni = colI;
			yylval.colFin = colF;
			yylval.linIni = linI;
			yylval.linFin = linF;

			// Actualizamos para el siguiente
			colI = colF+1;
			colF = colI;
	yylval.nParam = 0;
	yylval.lexema = strdup(yytext);
	return REL;
	}

">="	{
	colF = colI + yyleng - 1;

			yylval.colIni = colI;
			yylval.colFin = colF;
			yylval.linIni = linI;
			yylval.linFin = linF;

			// Actualizamos para el siguiente
			colI = colF+1;
			colF = colI;
	yylval.nParam = 1;
	yylval.lexema = strdup(yytext);
	return REL;
	}

"<"	{
	colF = colI + yyleng - 1;

			yylval.colIni = colI;
			yylval.colFin = colF;
			yylval.linIni = linI;
			yylval.linFin = linF;

			// Actualizamos para el siguiente
			colI = colF+1;
			colF = colI;
	yylval.nParam = 2;
	yylval.lexema = strdup(yytext);
	return REL;
	}

">"	{
	colF = colI + yyleng - 1;

			yylval.colIni = colI;
			yylval.colFin = colF;
			yylval.linIni = linI;
			yylval.linFin = linF;

			// Actualizamos para el siguiente
			colI = colF+1;
			colF = colI;
	yylval.nParam = 3;
	yylval.lexema = strdup(yytext);
	return REL;
	}

"%"	{colI+=yyleng;return PORCENTAJE;}

"*"	{
	colF = colI + yyleng - 1;

			yylval.colIni = colI;
			yylval.colFin = colF;
			yylval.linIni = linI;
			yylval.linFin = linF;

			// Actualizamos para el siguiente
			colI = colF+1;
			colF = colI;

	yylval.nParam = 0;
	yylval.lexema = strdup(yytext);
	return MULTIDIV;
	}

"&"	{
	colF = colI + yyleng - 1;

			yylval.colIni = colI;
			yylval.colFin = colF;
			yylval.linIni = linI;
			yylval.linFin = linF;

			// Actualizamos para el siguiente
			colI = colF+1;
			colF = colI;
	yylval.lexema = strdup(yytext);

	return ANDBIT;
	}

"--"	{colI+=yyleng;return MENOSMENOS;}
"!"	{
	colF = colI + yyleng - 1;

			yylval.colIni = colI;
			yylval.colFin = colF;
			yylval.linIni = linI;
			yylval.linFin = linF;

			// Actualizamos para el siguiente
			colI = colF+1;
			colF = colI;
			yylval.lexema = strdup(yytext);

	return EXCLAMACION;
	}

"#"	{colI+=yyleng;yylval.nParam=0;return UNARIOSLISTA;}
"?"	{colI+=yyleng;yylval.nParam=1;return UNARIOSLISTA;}
"$"	{colI+=yyleng;yylval.nParam=2;return UNARIOSLISTA;}

">>"	{colI+=yyleng;yylval.nParam=0;return AVANRETRO;}
"<<"	{colI+=yyleng;yylval.nParam=1;return AVANRETRO;}

"+"	{
	colF = colI + yyleng - 1;

		yylval.colIni = colI;
		yylval.colFin = colF;
		yylval.linIni = linI;
		yylval.linFin = linF;

		// Actualizamos para el siguiente
		colI = colF+1;
		colF = colI;

	yylval.lexema = strdup(yytext);
	yylval.nParam = 0;

	return MASMENOS;
	}

"-"	{
	colF = colI + yyleng - 1;

		yylval.colIni = colI;
		yylval.colFin = colF;
		yylval.linIni = linI;
		yylval.linFin = linF;

		// Actualizamos para el siguiente
		colI = colF+1;
		colF = colI;

	yylval.lexema = strdup(yytext);
	yylval.nParam = 1;

	return MASMENOS;
	}

"++"	{colI+=yyleng;return MASMAS;}

"@"	{colI+=yyleng;return ARROBA;}

","	{colI += yyleng;return COMA;}
"="	{colI += yyleng;return ASIG;}
":="	{colI+=yyleng;return DOSPUNTOSIGUAL;}

"lee"	{
	colF = colI + yyleng - 1;

	yylval.colIni = colI;
	yylval.colFin = colF;

	colI = colF+1;
	colF = colI;

	return LEE;
	}

"escribe"	{
	colF = colI + yyleng - 1;

			yylval.colIni = colI;
			yylval.colFin = colF;
			yylval.linIni = linI;
			yylval.linFin = linF;

			// Actualizamos para el siguiente
			colI = colF+1;
			colF = colI;
			return ESCRIBE;
		}

"durante"	{colI += yyleng;return DURANTE;}

"si"	{
	colF = colI + yyleng - 1;

		yylval.colIni = colI;
		yylval.colFin = colF;
		yylval.linIni = linI;
		yylval.linFin = linF;

		// Actualizamos para el siguiente
		colI = colF+1;
		colF = colI;

	return CONDSI;
	}

"mientras"	{colI += yyleng;return CONDMIENTRAS;}

"sino"	{
	colF = colI + yyleng - 1;

		yylval.colIni = colI;
		yylval.colFin = colF;
		yylval.linIni = linI;
		yylval.linFin = linF;

		// Actualizamos para el siguiente
		colI = colF+1;
		colF = colI;

	return CONDSINO;
	}

"hasta"	{colI += yyleng;return HASTA;}
"hacer"	{colI += yyleng;return HACER;}

"lista_de "	{colI += yyleng;return DEFLIST;}

"booleano"	{
		colI += yyleng;
		yylval.tipoDato = BOOLEANO;
		return TIPO;
		}
"real"	{
	colI += yyleng;
	yylval.tipoDato = REAL;
	return TIPO;
	}

"caracter"	{
		colI += yyleng;
		yylval.tipoDato = CARACTER;
		return TIPO;
		}

"entero"	{
		colI += yyleng;
		yylval.tipoDato = ENTERO;
		return TIPO;
		}

"principal"	{
		yylval.lexema = strdup(yytext);

		colF = colI + yyleng - 1;

		yylval.colIni = colI;
		yylval.colFin = colF;
		yylval.linIni = linI;
		yylval.linFin = linF;

		// Actualizamos para el siguiente
		colI = colF+1;
		colF = colI;

		return MAIN;
		}

"procedimiento"	{
		colF = colI + yyleng - 1;

		yylval.lexema = strdup(yytext);

		yylval.colIni = colI;
		yylval.colFin = colF;
		yylval.linIni = linI;
		yylval.linFin = linF;

		// Actualizamos para el siguiente
		colI = colF+1;
		colF = colI;

		return PROCED;
		}

"verdadero"	{
		colF = colI + yyleng - 1;

		yylval.colIni = colI;
		yylval.colFin = colF;
		yylval.linIni = linI;
		yylval.linFin = linF;

		// Actualizamos para el siguiente
		colI = colF+1;
		colF = colI;


		yylval.tipoDato = BOOLEANO;
		yylval.valor.booleano = 1;

		return VERDFALS;
		}

"falso"	{
	colF = colI + yyleng - 1;

		yylval.colIni = colI;
		yylval.colFin = colF;
		yylval.linIni = linI;
		yylval.linFin = linF;

		// Actualizamos para el siguiente
		colI = colF+1;
		colF = colI;

	yylval.tipoDato = BOOLEANO;
	yylval.valor.booleano = 0;

	return VERDFALS;
	}

"variables"	{
		colI+=yyleng;
		return INICIOVARS;
		}

"finvariables"	{
		colI+=yyleng;
		return FINVARS;
		}

[\+\-]?([0-9])+	{
		colF = colI + yyleng - 1;

		yylval.colIni = colI;
		yylval.colFin = colF;
		yylval.linIni = linI;
		yylval.linFin = linF;

		// Actualizamos para el siguiente
		colI = colF+1;
		colF = colI;
		yylval.tipoDato = ENTERO;
		yylval.valor.entero = atoi(yytext);

		return T_ENTERO;
		}

[\+\-]?([0-9])+\.([0-9])+	{
	colF = colI + yyleng - 1;

			yylval.colIni = colI;
			yylval.colFin = colF;
			yylval.linIni = linI;
			yylval.linFin = linF;

			// Actualizamos para el siguiente
			colI = colF+1;
			colF = colI;
			yylval.tipoDato = REAL;
			yylval.valor.real = atof(yytext);

			return T_REAL;
		}

[a-zA-Z][a-zA-Z0-9]*	{
					actualizarLoc(&yylval, yyleng);
					yylval.lexema = strdup(yytext);
					return IDENTIFICADOR;
					}


\'[^\']\'	{
	colF = colI + yyleng - 1;

			yylval.colIni = colI;
			yylval.colFin = colF;
			yylval.linIni = linI;
			yylval.linFin = linF;

			// Actualizamos para el siguiente
			colI = colF+1;
			colF = colI;
					yylval.tipoDato = CARACTER;

		yylval.valor.caracter = yytext[0];

		return T_CARACTER;
		}

\"[^\"]*\"	{
	colF = colI + yyleng - 1;

			yylval.colIni = colI;
			yylval.colFin = colF;
			yylval.linIni = linI;
			yylval.linFin = linF;

			// Actualizamos para el siguiente
			colI = colF+1;
			colF = colI;
			yylval.lexema = strdup(yytext);
		return T_CADENA;
		}

. ;
%%

void actualizarLoc(stEntrada *reg, int tamToken) {
	colF = colI + tamToken - 1;

	reg->colIni = colI;
	reg->colFin = colF;
	reg->linIni = linI;
	reg->linFin = linF;

	// Actualizamos contadores globales
	colI = colF+1;
	colF = colI;
	}
