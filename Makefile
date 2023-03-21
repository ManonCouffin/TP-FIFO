test : element.c element.h fifo.c
	gcc -c fifo.c
	gcc -c element.c
	gcc -o test.out element.o fifo.o
	./test.out
	
