
.PHONY=debug

main: main.c sl.h sorted-list.c
	gcc -o test main.c sl.h sorted-list.c

debug: main.c sl.h sorted-list.c
	gcc -g -o test main.c sl.h sorted-list.c


