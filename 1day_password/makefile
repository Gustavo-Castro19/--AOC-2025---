CFLAGS = -Wall -Wextra -O3 -pedantic 

all: solution.c solution_two.c 

solution.c: decode.c decode.h  
	cc $(CFLAGS) decode.c solution.c -o solution 

solution_two.c: decode.h decode_two.c 
	cc $(CFLAGS) decode_two.c solution_two.c -o solution2

clean: 
	rm solution solution2 

.PHONY: clean 
