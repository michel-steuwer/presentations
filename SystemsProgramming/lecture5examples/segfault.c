#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 

void null_ptr() {
  int * i_ptr = NULL;

  printf("%i\n", *i_ptr);
}

/*
void recurse() {
  recurse();
}
*/

void write_only_memory() {
  char * s = "hello world";
  s[0] = 'H';
  printf("%s\n", s);
}
  
void overflow(int argc, char *argv[]) 
{ 
       char buffer[5];

       if (argc < 2) { 
              printf("strcpy() NOT executed....\n"); 
              printf("Syntax: %s <characters>\n", argv[0]); 
              exit(0); 
       } 
  
       // copy the user input to buffer, without any 
       // bound checking a secure version is srtcpy_s() 
       strcpy(buffer, argv[1]); 
       printf("buffer content= %s\n", buffer); 
  
       printf("strcpy() executed...\n"); 
} 

int main(int argc, char *argv[]) {
  overflow(argc, argv);
}