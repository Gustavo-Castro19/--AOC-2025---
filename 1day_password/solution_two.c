#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "decode.h"

int main() {
    int pointer = 50;
    int pass = 0;
    char line[lineSize];

    FILE *fd = fopen("input.txt", "r");
    if (fd == NULL) {
        fprintf(stderr, "Error opening file\n");
        return 1;
    }
    
    while (fgets(line, lineSize, fd)) {
        line[strcspn(line, "\n")] = '\0';
        
        char direction = line[0];
        int distance = atoi(line + 1);
        
        if (direction == LEFT) {
            pass += count_zeros_during_rotation(pointer, distance, 0);
            pointer = (pointer - distance) % 100;
        } else if (direction == RIGHT) {
            pass += count_zeros_during_rotation(pointer, distance, 1);
            pointer = (pointer + distance) % 100;
        }
        
        if (pointer < 0) pointer += 100;
        
        if (pointer == 0) {
            pass++;
        }
    }

    fclose(fd);
    printf("%d\n", pass);
    return 0;
}
