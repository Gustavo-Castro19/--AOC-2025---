#include <stddef.h>
#ifndef DECODE_H
#define DECODE_H

typedef enum{
  RIGHT = 'R', 
  LEFT = 'L'
}dir_rotations;

void rotate(int *point, char *buff,dir_rotations tide);

#endif /* DECODE_H */
