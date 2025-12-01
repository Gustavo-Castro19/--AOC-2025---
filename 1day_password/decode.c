#include "decode.h"
#include <stdlib.h>
#include <stdio.h>

void rotate(int *point, char *buff,dir_rotations tide) {
    int numForm = atoi(buff + 1); 
    
    if (tide == LEFT) {
        *point = (*point - numForm) % 100;
    } else if (tide == RIGHT) {
        *point = (*point + numForm) % 100;
    } else {
        fprintf(stderr, "MUST BE UNREACHABLE\n");
        return;
    }
    
    if (*point < 0) {
        *point += 100;
    }
}
