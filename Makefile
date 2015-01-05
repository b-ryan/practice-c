default:

bin/list: list/list.h list/list.c list/list_main.c
	gcc list/list.c list/list_main.c -o bin/list

list: bin/list
	./bin/list $N

bin/array: array/array.c array/array_main.c
	gcc -ggdb array/array.c array/array_main.c -o bin/array

array: bin/array
	./bin/array

.PHONY: list array
