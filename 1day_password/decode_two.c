#include "decode.h"
#include <stdlib.h>
#include <stdio.h>

int count_zeros_during_rotation(int ptr_start, int distance, int is_right) {
    if (distance <= 1) return 0;  
    
    if (is_right) {
        int first = (100 - (ptr_start % 100)) % 100;
        if (first == 0) first = 100;
        
        if (first > distance - 1) return 0;
        
        return 1 + (distance - 1 - first) / 100;
    } else {
        int first = ptr_start % 100;
        if (first == 0) first = 100;
        
        if (first > distance - 1) return 0;
        
        return 1 + (distance - 1 - first) / 100;
    }
}
