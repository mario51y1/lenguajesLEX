procedimiento principal()
{
  variables
    lista_de entero abb;
    booleano vb;
    real vr;
    caracter vc;
    entero ve;

    booleano vb1, vb2, vb3;
    real vr1, vr2, vr3;
    caracter vc1, vc2, vc3;
    entero ve1, ve2, ve3;

    lista_de real lr;
    lista_de booleano lb;
    lista_de entero le;
  finvariables;

  procedimiento funcionA(entero a1,real a2, caracter a3)
  {
    variables
      entero x1,x2;
    finvariables;

    procedimiento funcionB(caracter b1, booleano b2)
    {
      variables
        real xf,x2;
      finvariables;

      procedimiento funcionC(booleano c1, entero c2)
      {
        variables
          real x1;
        finvariables;

        x1 = 1.3;

        si ( c2 > 10  )
          c2 = c2 - 1;
        sino
          x1 = 3.1;
      }

      xf = funcionC(verdadero,10);

      x2 = xf * (funcionC(false,1)-funcionC(true,23))/10.0;

      mientras (x2*funcionC(false,1)-xf<10.0) {
        x2 = x2*xf;
      }

      procedimiento funcionD(real d1)
      {
        variables
          caracter dato;
          entero valor;
        finvariables;

        procedimiento funcionE( caracter e1, caracter e2){
          lee e1 , e2;
          si (e1 == 'a')
            return e1;
          sino si (e1 == 'b')
            return e2;
          else
            return ' ' ;

        }

        lee valor;
        if (d1> 0.0){
          variables
            entero dato;
          finvariables;

          dato = 2;
          dato = valor*20/dato;
        }else{
          valor = valor * 100;
          d1 = d1 /1000.0;

        }
        return d1;
      }
    pe = pe <-10;
    pf = pf <-10.0;
    pc = pc<-'#';

    if(?(pe<-20)==20)
      ve = pe->;
    else
      pe = pe * pe2;
      pe = pe2 - pe <- 10 * (20/2000);

    }

  }

  funcionA(3);

  si (ve == veA) {
    ve = 5 ;
  }

}
