OBJS = main.o sll.o dll.o stack.o test-dll.o integer.o
OPTS = -Wall -Wextra -g -std=c99 
 
main : $(OBJS) 
		gcc $(OPTS) $(OBJS) -o main -lm 

main.o : main.c 
		gcc $(OPTS) -c main.c 

sll.o : sll.c sll.h 
		gcc $(OPTS) -c sll.c

dll.o : dll.c dll.h
		gcc $(OPTS) -c dll.c

test-dll.o : dll.c
		gcc $(OPTS) -c test-dll.c

stack.o : stack.c stack.h
		gcc $(OPTS) -c stack.c

integer.o : integer.c integer.h 
		gcc $(OPTS) -c integer.c 

clean : 
		rm -f $(OBJS) main 
 
test : main 
		./main