.SUFFIXES:

prog: y.tab.o
	gcc -o prog y.tab.o

y.tab.o: yacc
	gcc -c y.tab.c

main.o:
	gcc -c main.c

yacc: lex
	bison -dyv -o y.tab.c yacc.y

lex:
	flex token.l

limpia:
	rm -f prog main.o y.tab.o y.tab.c lex.yy.c compilador

todo:
	make limpia
	make alt

alt: lex yacc
	gcc ts.c y.tab.c -o compilador
