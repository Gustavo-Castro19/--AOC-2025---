CFLAGS = -Wall -Wextra -O3 -pedantic 

all: solution solution_two 

solution: solution.c decode.c decode.h  
	cc $(CFLAGS) decode.c solution.c -o solution 

solution_two: solution_two.c decode.h decode_two.c 
	cc $(CFLAGS) decode_two.c solution_two.c -o solution_two

clean: 
	rm solution solution_two 

.PHONY: clean 
