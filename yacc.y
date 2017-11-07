

%{
  int vbltable[26]; //NOSE QUE ES
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
%token UNARIOSIMPLE
%token MASMENOS
%token ARROBA
%token OPBINARIO
%token DURANTE
%token DOSPUNTOSIGUAL
%token HASTA
%token HACER
%token TIPO
%token CARACTER
%token CADENA
%token IDENTIFICADOR
%token ENTERO



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
Cabecera_subprograma : PROCED IDENTIFICADOR ABRIRPARENT parametros CERRARPARENT ;
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
Cuerpo_declar_variables : tipo Identificadores PUNTOCOMA ;
Identificadores : IDENTIFICADOR | Identificadores COMA IDENTIFICADOR ;

tipo : tipo_normal | tipo_lista ;
tipo_lista : DEFLIST tipo_normal ;
tipo_normal: TIPO ;

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
	| CONDSI ABRIRPARENT expresion CERRARPARENT Sentencia CONDSINO Sentencia
  ;

 sentencia_while : CONDMIENTRAS ABRIRPARENT expresion CERRARPARENT Sentencia ;

sentencia_entrada : nomb_entrada Identificadores PUNTOCOMA ;
nomb_entrada : LEE ;

sentencia_salida : nomb_salida lista_expresiones_o_cadena PUNTOCOMA ;
nomb_salida : ESCRIBE ;

expcad : expresion
	| string_comillas
  ;

lista_expresiones_o_cadena : expcad
	| lista_expresiones_o_cadena COMA expcad
  ;

llamada_proced : IDENTIFICADOR ABRIRPARENT  lista_expresiones  CERRARPARENT PUNTOCOMA ;
sentencia_for : DURANTE IDENTIFICADOR DOSPUNTOSIGUAL  expresion HASTA expresion HACER Sentencia ;

expresion : ABRIRPARENT expresion CERRARPARENT
	| op_unario expresion
	| expresion op_binario expresion
	| expresion MASMAS expresion ARROBA expresion
	| IDENTIFICADOR
	| constante
  ;

lista_expresiones : lista_expresiones expresion | expresion | ;

op_binario : OPBINARIO
;

op_unario: MASMAS | UNARIOSIMPLE | MASMENOS
;

Signo : MASMENOS
;

constante : ENTERO | REAL | lista | VERDFALS | CARACTER ;

lista : lista_enteros
	| lista_reales
	| lista_booleanos
	| lista_caracteres
  ;

lista_enteros: ABRIRCORCH Enteros CERRARCORCH ;

Enteros : entero_signo
	| Enteros COMA entero_signo
;

lista_reales : ABRIRCORCH Reales CERRARCORCH ;

Reales: real_signo
	|Reales COMA real_signo
  ;


lista_booleanos : ABRIRCORCH Booleanos CERRARCORCH ;

Booleanos : VERDFALS
	| Booleanos COMA VERDFALS
  ;

lista_caracteres: ABRIRCORCH Caracteres CERRARCORCH ;

Caracteres: CARACTER
| Caracteres COMA CARACTER
;

entero_sig : MASMENOS ENTERO
	| ENTERO
  ;

real_signo : REAL
	| MASMENOS REAL
  ;

cadena : caracter | cadena caracter ;


string_comillas: CADENA ;

string : caracter | caracter_especial
	|string caracter | string caracter_especial
  ;




%%
