procedimiento principal(){
  variables
    entero a;
    real b;
    booleano c;
    lista_de entero lis;
    entero a1,aa,aa2;

  finvariables;

  procedimiento funcionA(entero dato1,entero dato2){
    variables
      entero a;
      entero b;
    finvariables;

    si(dato1 == dato2){
      a = dato2;
      b = dato1;
    }sino{
      a = dato1;
      a = dato2;
    }
  }

  funcionA(a,a);

  mientras(c)
    c = falso;

  c = a;

}
