#include "ts.h"


#define MAX_TS 500

unsigned int indice=0;
unsigned int subprog;

entradaTS TS[MAX_TS];

int buscaHastaMarca(entradaTS entrada){
  int j = indice;

  while ( TS[j].entrada != MARCA && j>0 && (indice!=0)) {
    if(!strcmp(TS[j].nombre, entrada.nombre)){
      printf("Se encontro la entrada en este scope : %s , %d \n", entrada.nombre,j);
      return j;
    }
    else j--;
  }

  printf("No se encontro la entrada en este scope: %s\n", entrada.nombre);
  return -1;
}

int busca(entradaTS entrada){
  int j = 0;

  while ( (j<=(indice-1)) && (indice!=0)) {
    if(!strcmp(TS[j].nombre, entrada.nombre)){
      printf("Se encontro la entrada en : %s , %d \n", entrada.nombre,j);
      return j;
    }
    else j++;
  }

  printf("No se encontro la entrada: %s\n", entrada.nombre);
  return -1;

}

int inserta(entradaTS entrada,tipoEntrada tipo){
  if(tipo == MARCA || buscaHastaMarca(entrada) == -1){

    TS[indice].entrada = tipo;
    TS[indice].nombre = entrada.nombre;
    TS[indice].tipoDato = entrada.tipoDato;
    TS[indice].parametros = entrada.parametros;
    TS[indice].valor = entrada.valor;

    indice++;
    printf("Insertada entrada: %s\n", entrada.nombre );

    return 1;
  } else {
    printf("No se pudo insertar entrada porque ya existe: %s\n", entrada.nombre );
    return 0;
  }
}

entradaTS devuelveEntrada(int posicion){
  if(posicion<=indice && posicion>=0)
    return TS[posicion];
}

int eliminarHastaMarca(entradaTS entrada){

  int j = indice;

  while ( TS[j].entrada != MARCA && j>0 && (indice!=0)) {
    j--;
  }

  indice = j;
  printf("Eliminando scope hasta: %d\n", indice);
  return 0;

}


void muestra(){

  int j = 0;
  while ( (j<=(indice-1)) && (indice!=0)) {
    printf("tipoEntrada: %i , nombre: %s \n",TS[j].entrada, TS[j].nombre );
  }

}
