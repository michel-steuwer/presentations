#include <stdlib.h> /* malloc, free, NULL */
#include <stdio.h> /*  fprintf, stderr */

int main(void) {
    /* Let's allocate memory. */
    char *mem = (char*) malloc( sizeof(char) * 20);

    /* Check to make sure that we got the allocated memory. */
    if (mem == NULL) {
        fprintf(stderr, "Unable to allocate enough memory for mem!\n");
        return -1;
    }

    /* Let's allocate more memory. We just lost the pointer to the older memory. */
    mem = (char*) malloc( sizeof(char) * 30);

    /* Check to make sure that we got the allocated memory. */
    if (mem == NULL) {
        fprintf(stderr, "Unable to allocate enough memory for array!\n");
        return -1;
    }

    /* We have no more use for mem, we better free it. */
    free(mem);

    /* The first allocated memory still hasn't be freed! Thankfully,
     when the program ends, it will all be deallocated by the OS. */

    /* Everything went fine! */
    return 0;
}