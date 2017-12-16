
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

"\n"	{linea_actual++;
	colI += yyleng;}

"["	{ colI += yyleng;return ABRIRCORCH;}

"]"	{ colI += yyleng;return CERRARCORCH;}

"("	{
	actualizarLoc(&yylval,yyleng);
	return ABRIRPARENT;
	}

")"	{
	actualizarLoc(&yylval,yyleng);
	return CERRARPARENT;
	}

"{"	{
	actualizarLoc(&yylval,yyleng);

	return ABRIRLLAVES;
	}

"}"	{
	actualizarLoc(&yylval,yyleng);
	return CERRARLLAVES;
	}

";"	{ colI += yyleng;return PUNTOCOMA;}

"**"	{
	actualizarLoc(&yylval,yyleng);
	return MULMUL;
	}

"/"	{
	actualizarLoc(&yylval,yyleng);
	yylval.lexema = strdup(yytext);
	yylval.nParam = 1;
	return MULTIDIV;
	}

"&&"	{
	actualizarLoc(&yylval,yyleng);
	yylval.lexema = strdup(yytext);

	return LOGAND;
	}

"^"	{
	actualizarLoc(&yylval,yyleng);
	yylval.lexema = strdup(yytext);
	
	return EXOR;
	}

"|"	{
	actualizarLoc(&yylval,yyleng);
	yylval.lexema = strdup(yytext);

	return ORBIT;
	}
	
"||"	{
	actualizarLoc(&yylval,yyleng);
	yylval.lexema = strdup(yytext);
	
	return LOGOR;
	}

"+="	{
	actualizarLoc(&yylval,yyleng);
	
	yylval.nParam = 0;
	yylval.lexema = strdup(yytext);
	
	return IGUALDAD;
	}

"-="	{
	actualizarLoc(&yylval,yyleng);
	
	yylval.nParam = 1;
	yylval.lexema = strdup(yytext);
	
	return IGUALDAD;
	}

"=="	{
	actualizarLoc(&yylval,yyleng);
	
	yylval.nParam = 2;
	yylval.lexema = strdup(yytext);
	
	return IGUALDAD;
	}

"!="	{
	actualizarLoc(&yylval,yyleng);
	
	yylval.nParam = 3;
	yylval.lexema = strdup(yytext);
	
	return IGUALDAD;
	}

"<="	{
	actualizarLoc(&yylval,yyleng);
	
	yylval.nParam = 0;
	yylval.lexema = strdup(yytext);
	return REL;
	}

">="	{
	actualizarLoc(&yylval,yyleng);
	
	yylval.nParam = 1;
	yylval.lexema = strdup(yytext);
	return REL;
	}

"<"	{
	actualizarLoc(&yylval,yyleng);
	
	yylval.nParam = 2;
	yylval.lexema = strdup(yytext);
	return REL;
	}

">"	{
	actualizarLoc(&yylval,yyleng);
	
	yylval.nParam = 3;
	yylval.lexema = strdup(yytext);
	return REL;
	}

"%"	{colI+=yyleng;return PORCENTAJE;}

"*"	{
	actualizarLoc(&yylval,yyleng);
	
	yylval.nParam = 0;
	yylval.lexema = strdup(yytext);
	return MULTIDIV;
	}

"&"	{
	actualizarLoc(&yylval,yyleng);
	
	yylval.lexema = strdup(yytext);
	
	return ANDBIT;
	}

"--"	{colI+=yyleng;return MENOSMENOS;}
"!"	{
	actualizarLoc(&yylval,yyleng);
	yylval.lexema = strdup(yytext);

	return EXCLAMACION;
	}

"#"	{colI+=yyleng;yylval.nParam=0;return UNARIOSLISTA;}
"?"	{colI+=yyleng;yylval.nParam=1;return UNARIOSLISTA;}
"$"	{colI+=yyleng;yylval.nParam=2;return UNARIOSLISTA;}

">>"	{colI+=yyleng;yylval.nParam=0;return AVANRETRO;}
"<<"	{colI+=yyleng;yylval.nParam=1;return AVANRETRO;}

"+"	{
	actualizarLoc(&yylval,yyleng);
	
	yylval.lexema = strdup(yytext);
	yylval.nParam = 0;

	return MASMENOS;
	}

"-"	{
	actualizarLoc(&yylval,yyleng);

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
		actualizarLoc(&yylval, yyleng);
		return ESCRIBE;
		}

"durante"	{colI += yyleng;return DURANTE;}

"si"	{
	actualizarLoc(&yylval,yyleng);

	return CONDSI;
	}

"mientras"	{colI += yyleng;return CONDMIENTRAS;}

"sino"	{
	actualizarLoc(&yylval,yyleng);

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
		yylval.tipoDato = REAL;
		return TIPO;
		}

"entero"	{
		colI += yyleng; 
		yylval.tipoDato = REAL;
		return TIPO;
		}

"principal"	{
		yylval.lexema = strdup(yytext);	

		actualizarLoc(&yylval,yyleng);

		return MAIN;				
		}

"procedimiento"	{	
		actualizarLoc(&yylval,yyleng);
		return PROCED;
		}

"verdadero"	{
		actualizarLoc(&yylval,yyleng);

		yylval.tipoDato = BOOLEANO;
		yylval.valor.booleano = 1;
		return VERDFALS;
		}

"falso"	{
	actualizarLoc(&yylval,yyleng);
	
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
		actualizarLoc(&yylval,yyleng);
		yylval.tipoDato = ENTERO;
		yylval.valor.entero = atoi(yytext);
		
		return T_ENTERO;
		}
[\+\-]?([0-9])+\.([0-9])+	{
				actualizarLoc(&yylval, yyleng);
				yylval.tipoDato = REAL;
				yylval.valor.entero = atof(yytext);
		
				return T_REAL;
				}

\'[^\']\'	{
		actualizarLoc(&yylval, yyleng);
		yylval.tipoDato = CARACTER;

		yylval.valor.caracter = yytext[0];
		
		return T_CARACTER;
		}

\"[^\"]*\"	{
		actualizarLoc(&yylval, yyleng);
		yylval.lexema = strdup(yytext);		
		return CADENA;
		}
[a-zA-Z][a-zA-Z0-9]*	{
			actualizarLoc(&yylval, yyleng);
			yylval.lexema = strdup(yytext);			
			return IDENTIFICADOR;
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

