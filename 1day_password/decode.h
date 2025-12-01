#include <stddef.h>
#ifndef DECODE_H
#define DECODE_H

#define lineSize 500

typedef enum{
  RIGHT = 'R', 
  LEFT = 'L'
}dir_rotations;

void rotate(int *point, char *buff,dir_rotations tide);
int count_zeros_during_rotation(int start, int distance, int is_right);

#endif /* DECODE_H */
