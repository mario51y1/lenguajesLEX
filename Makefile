.SUFFIXES:

prog: y.tab.o
	gcc -o prog y.tab.o

y.tab.o: yacc
	gcc -c y.tab.c

main.o: main.c
	gcc -c main.c

yacc: yacc.y lex.yy.c
	bison -o y.tab.c yacc.y

lex: token.l
	flex token.l

limpia:
	rm -f prog main.o y.tab.o y.tab.c lex.yy.c

todo:
	make limpia
	make prog

alt:
	make yacc
	make lex
	gcc peticiones.c y.tab.c -o compilador
