OBJS = main.o sll.o integer.o
OPTS = -Wall -Wextra -g -std=c99 
 
main : $(OBJS) 
		gcc $(OPTS) $(OBJS) -o main -lm 

main.o : main.c 
		gcc $(OPTS) -c main.c 

sll.o : sll.c sll.h 
		gcc $(OPTS) -c sll.c

integer.o : integer.c integer.h 
		gcc $(OPTS) -c integer.c 

clean : 
		rm -f $(OBJS) main 
 
test : main 
		./main