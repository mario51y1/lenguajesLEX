principal
{
  variables
  {
    booleano vb;
    real vr;
    caracter vc;
    entero ve;

    booleano vb1, vb2, vb3;
    real vr1, vr2, vr3;
    caracter vc1, vc2, vc3;
    entero ve1, ve2, ve3;

    lista_de real lr;
    lista_d booleano lb;
    lista_de entero le;

  }
  finvariables

  procedimiento funcionA(entero veA)
  {
    variables
    {
      booleano vbA;
    }
    finvariables;

    vbA = verdadero;
    ve / veA;
  }

  funcionA(3);

  si (ve == veA) {
    ve = 5
  }

}
