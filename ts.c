#include "ts.h"


#define MAX_TS 500

unsigned int indice=0;
unsigned int subprog;

entradaTS TS[MAX_TS];

int buscaHastaMarca(entradaTS entrada){
  int j = indice-1;

  while ( TS[j].entrada != MARCA && j>=0 && (indice!=0)) {
    if(!strcmp(TS[j].nombre, entrada.nombre)){
      //printf("Se encontro la entrada en este scope : %s , %d \n", entrada.nombre,j);
      return j;
    }
    else j--;
  }

  //printf("No se encontro la entrada en este scope: %s\n", entrada.nombre);
  return -1;
}

int busca(entradaTS entrada){
  int j = 0;

  while ( (j<=(indice-1)) && (indice!=0)) {
    if(!strcmp(TS[j].nombre, entrada.nombre)){
      //printf("Se encontro la entrada en : %s , %d \n", entrada.nombre,j);
      return j;
    }
    else j++;
  }

//  printf("No se encontro la entrada: %s\n", entrada.nombre);
  return -1;

}

int buscaEnTs(entradaTS entrada){
  int j = indice-1;

  while(j>=0  && (indice!=0)){
    while (TS[j].entrada != MARCA && (j>=0)) {
      if(!strcmp(TS[j].nombre, entrada.nombre)){
        //printf("Se encontro la entrada en : %s , %d \n", entrada.nombre,j);
        return j;
      }
      else j--;
    }
    j--;
    //printf("No se encontro en este scope \n");
    //printf("Revisando parametros\n");
    while (TS[j].entrada == PAR_FORMAL && (j>=0)) {
      if(!strcmp(TS[j].nombre, entrada.nombre)){
      //  printf("Se encontro la entrada en parametro : %s , %d \n", entrada.nombre,j);
        return j;
      }
      else j--;
    }
    //j--;
    //printf("No se encontro entre los parametros, Revisando Padre \n");

  }

  //printf("No se encontro la entrada en este scope: %s\n", entrada.nombre);
  return -1;

}


int inserta(entradaTS entrada,tipoEntrada tipo){
  if(tipo == MARCA || buscaHastaMarca(entrada) == -1){

    TS[indice].entrada = tipo;
    TS[indice].nombre = entrada.nombre;
    TS[indice].tipoDato = entrada.tipoDato;
    TS[indice].parametros = entrada.parametros;
    TS[indice].valor = entrada.valor;
    //printf("Insertado: %s, Tentrada : %d , Tipo: %d\n", TS[indice].nombre,  TS[indice].entrada , TS[indice].tipoDato  );

    indice++;

    return 1;
  } else {
    //printf("No se pudo insertar entrada porque ya existe: %s\n", entrada.nombre );
    return 0;
  }
}

entradaTS devuelveEntrada(int posicion){
  if(posicion<=indice && posicion>=0)
    return  TS[posicion];
}

int eliminarHastaMarca(){

  int j = indice-1;

  while ( TS[j].entrada != MARCA && j>0 && (indice!=0)) {
    j--;
  }

  indice = j;
  //printf("Eliminando scope hasta: %d\n", indice);
  return 0;

}
int ultimaPosicion(){
  return indice-1;
}

int actualiza(int posicion,entradaTS entrada){
  if(posicion>0){
    TS[posicion].entrada = entrada.entrada;
    TS[posicion].nombre = entrada.nombre;
    TS[posicion].tipoDato = entrada.tipoDato;
    TS[posicion].parametros = entrada.parametros;
    TS[posicion].valor = entrada.valor;
    return posicion;
  }
  return -1;
}

void muestra(){
//  printf("mostrando TS: \n" );
  int j = 0;
  while ( (j<=(indice-1)) && (indice!=0)) {
  //  printf("tipoEntrada: %i , nombre: %s  , parametros: %d \n",TS[j].entrada, TS[j].nombre, TS[j].parametros );
    j++;
  }

}
