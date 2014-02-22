
.PHONY=debug

main: main.c sl.h sorted-list.c
	gcc -g -c sorted-list.c
	ar rcs libsl.a sorted-list.o
	gcc -o test main.c sl.h sorted-list.c

debug: main.c sl.h sorted-list.c
	gcc -g -o test main.c sl.h sorted-list.c

clean:
	rm test

