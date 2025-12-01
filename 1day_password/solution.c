#include <string.h>
#include "decode.h"
#include <stdio.h>
#define lineSize 500

int main(void){

char buffer[lineSize];
int pointer = 50; 
int pass = 0; 

FILE *fd = fopen("sequence.txt","r");
if(fd == NULL){
fprintf(stderr, "the archive couldn't open well, please verify the name");
return -1;
}; 


while(fgets(buffer,lineSize,fd)){
  switch(buffer[0]){
      case RIGHT: 
        rotate(&pointer,buffer,RIGHT); 
        break; 
      case LEFT:
        rotate(&pointer,buffer,LEFT);
        break;
      default:
        fprintf(stderr, "MUST BE UNREACHABLE\n");
        break; 
  }
  if(pointer == 0) ++pass;  
}

printf("%d\n", pass);  

return 0; 
}
