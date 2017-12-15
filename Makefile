.SUFFIXES:

prog: main.o y.tab.o
	gcc -o prog main.o y.tab.o

y.tab.o: y.tab.c
	gcc -c y.tab.c

main.o: main.c
	gcc -c main.c

y.tab.c: yacc.y lex.yy.c
	yacc -o y.tab.c yacc.y

lex.yy.c: token.l
	flex token.l

limpia:
	rm -f prog main.o y.tab.o y.tab.c lex.yy.c

todo:
	make limpia
	make prog
