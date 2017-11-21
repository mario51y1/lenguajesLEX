

%{
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
%token REAL

%token LOGOR
%token LOGAND
%token ORBIT
%token EXOR
%token ANDBIT
%token IGUALDAD
%token RELACION
%token MENOSMENOS
%token MULTIDIV
%token EXCLAMACION
%token AVANRETRO
%token UNARIOSLISTA
%token PORCENTAJE
%token MULMUL


%start Programa

%right ASIG
%left MASMENOS
%right MASMAS
%left UNARIOSIMPLE
%right ARROBA
%left OPBINARIO
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
	| CONDSI ABRIRPARENT expresion CERRARPARENT Sentencia CONDSINO Sentencia
  ;

 sentencia_while : CONDMIENTRAS ABRIRPARENT expresion CERRARPARENT Sentencia ;

sentencia_entrada : LEE Identificadores PUNTOCOMA ;

sentencia_salida : ESCRIBE lista_expresiones_o_cadena PUNTOCOMA ;

expcad : expresion
	| CADENA
  ;

lista_expresiones_o_cadena : expcad
	| lista_expresiones_o_cadena COMA expcad
  ;

llamada_proced : IDENTIFICADOR ABRIRPARENT  lista_expresiones  CERRARPARENT PUNTOCOMA ;

sentencia_for : DURANTE IDENTIFICADOR DOSPUNTOSIGUAL  expresion HASTA expresion HACER Sentencia ;

expresion : ABRIRPARENT expresion CERRARPARENT
  | MASMAS expresion
  | UNARIOSIMPLE expresion
  | MASMENOS expresion
	| expresion OPBINARIO expresion
	| expresion MASMAS expresion ARROBA expresion
	| IDENTIFICADOR
  | ENTERO
  | REAL
  | VERDFALS
  | CARACTER
  | lista
  ;

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
