procedimiento principal()
{
  variables
    booleano vb;
    real vr;
    caracter vc;
    entero ve,veA;

    booleano vb1, vb2, vb3;
    real vr1, vr2, vr3;
    caracter vc1, vc2, vc3;
    entero ve1, ve2, ve3;

    lista_de real lr;
    lista_de booleano lb;
    lista_de entero pe,pe2;
    lista_de real pf;
    lista_de caracter pc;

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
      procedimiento funcionD(real d1,entero ee1)
      {
        variables
          caracter dato;
          entero valor;
        finvariables;

        procedimiento funcionE( caracter e1, caracter e2,caracter devolver)
        {
          si (e1 == 'a')
            devolver = e1;
          sino si (e1 == 'b')
            devolver =  e2;
          sino
            devolver = ' ' ;
        }

        si ( d1>0.0 ){
          variables
            entero dato;
          finvariables;
          dato = 2;
          dato = valor*20/dato;
        }sino{
          valor = valor * 100;
          d1 = d1 /1000.0;

        }
      }
    }
  }


      funcionC(verdadero,3);

      funcionD(3.5,7);

      x2 = xf * (-10.0);

      mientras(x2<10.0)
        x2 = x2*xf;




    pe = pe <-10;
    pf = pf <-10.0;
    pc = pc<-'#';

    si(pe == 20){
      ve = pe;
      }
    sino{
      pe = pe * pe2;
      pe = pe2 - pe <- 10 * (20/2000);
      }
    }



  funcionA(3,3.5,'a');

  si(ve == veA)
    ve = 5 ;


}
