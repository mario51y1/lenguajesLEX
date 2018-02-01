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
				real t1,t2;
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

			funcionC (verdadero, 10);

      xf = 3.1;
      t1 = 0.3;
      t2 = 3.1;
			x2 = xf*(t1 - t2)/10.0;

			mientras(x2/t1-xf<10.0) {
				x2 = x2/xf ;
			}
		}

		procedimiento funcionD (real d1)
		{
			variables
				caracter dato ;
				entero valor ;
			finvariables;

			procedimiento funcionE (caracter e1,caracter e2)
			{
				escribe "introduzca_dos caracteres:";
				lee e1, e2 ;
				si(e1=='a')
          e1 = 'z';
				sino
          si(e1=='b')
					    e2 = 'z';
					sino
					   e1 = ' ';
			}

			escribe "introduzca_un_valor_entero:";
			lee valor ;
			si(d1>0.0)
			{
				variables
					entero dato ;
				finvariables;

				dato = 2 ;
				dato= valor*20/dato ;
			}
			sino
			{
				valor= valor*100 ;
				d1= d1/1000.0 ;
			}
		}

		pe = pf;
		pf = pf++10.0@0 ;
		pc = pc++'#'@0 ;

		si( ?(pe++ 20@0) == 20) {
			ve = 3 + pe@0 ;
		}
		si
		{
			pe = pe * ve ;
			pe = pe;
			pe = 1 + pe;
			ve = pe2@0;
			pe2 = pe2++(pe@0)@2  ;
		}
	}
	funcionA(ve1,vr1,vc1);
}
