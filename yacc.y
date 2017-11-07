

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


%%

//Pagina 45 pdf de practicas - simplificar BNF

Programa : Cabecera_programa bloque
bloque : Inicio_de_bloque Declar_de_variables_locales Declar_de_subprogs Sentencias Fin_de_bloque
Declar_de_variables_locales : Marca_ini_declar_variables Variables_locales Marca_fin_declar_variables
	                          |

Marca_ini_declar_variables : 'variables' Inicio_de_bloque
Marca_fin_declar_variables : Fin_de_bloque 'finvariables' ;

Declar_de_subprogs : Declar_de_subprogs Declar_subprog
	|

Declar_subprog : Cabecera_subprograma bloque

Cabecera_programa : principal
Cabecera_subprograma : procedimiento identificador '(' parametros ')'
parametros : parametro
	| parametros ',' parametro
	|
parametro : tipo identificador

Inicio_de_bloque :  '{'
Fin_de_bloque :  '}'

Variables_locales : Variables_locales Cuerpo_declar_variables
	| Cuerpo_declar_variables
Cuerpo_declar_variables : tipo Identificadores ';'
Identificadores : identificador | Identificadores ',' <identificador>

tipo : tipo_normal | tipo_lista
tipo_lista : 'lista_de' tipo_normal
tipo_normal: 'entero' | 'real' | 'caracter' | 'booleano'

Sentencias : Sentencias Sentencia
	| Sentencia ;

Sentencia : bloque
	| sentencia_asignacion
	| sentencia_if
	| sentencia_while
	| sentencia_entrada
	| sentencia_salidaa	| llamada_proced
	| sentencia_for

sentencia_asignacion : identificador = expresion ';'
//<sentencia_if> : si (<expresion>) <Sentencia>
//	| si (<expresion>) <Sentencia> sino <Sentencia>
// <sentencia_while> : mientras ( <expresion> ) <Sentencia>

sentencia_entrada : nomb_entrada identificadores ';'
nomb_entrada : 'lee'

sentencia_salida : nomb_salida lista_expresiones_o_cadena ';'
nomb_salida : 'escribe'

exp-cad : expresion
	| string_comillas
lista_expresiones_o_cadena : exp-cad
	| lista_expresiones_o_cadena ',' exp-cad

llamada_proced : identificador '(' [<lista_expreiones>] ')' ';'
sentencia_for : 'durante' identificador ':='  expresion 'hasta' expresion 'hacer' Sentencia

expresion : '(' <expresion> ')'
	| op_unario expresion
	| expresion op_binario expresion
	| expresion'++'expresion'@'expresion
	| identificador
	| constante

lista_expresiones : lista_expresiones expresion | expresion
op_binario : '+'
	| -
	| **
	| *
	| /
	| &
| &&
	| ^
	| “|”
	| "||"
	| +=
	| -=
	| =
| ==
| !=
	| <=
	| >=
	| <
	| >
| %
| @


op_unario: # | ? | ! | ++ | -- | -  | +
Signo : + | -

identificador : letra cadena
constante : entero | real | lista | booleano | caracter_comillas

lista : lista_enteros
	| lista_reales
	| lista_booleanos
	| lista_caracteres

lista_enteros: '[' Enteros ']'

Enteros : entero_signo
	| Enteros ',' entero_signo

lista_reales : '[' Reales ']'
Reales: real_signo
	|Reales ',' real_signo



lista_booleanos : '[' Booleanos ']'
Booleanos : booleano
	| Booleanos ',' booleano

lista_caracteres: '[' Caracteres ']'
Caracteres: caracter_comillas
| Cadenas ',' caracter_comillas

entero_sig : signo entero
	| entero

entero : digito | entero digito

real_signo : real
	| signo real

real : entero'.'entero

cadena : caracter | cadena caracter

caracter_comillas : '‘' caracter '’' | '‘' caracter_especial '’'

caracter_especial :  cualquier_caracter_ASCII
caracter : digito | letra

string_comillas: '“' string”
string : caracter | caracter_especial
	|string caracter | string caracter_especial


digito :  [0 - 9]

letra : [a - z] | [A - Z]

booleano : 'verdadero' | 'falso'


%%
