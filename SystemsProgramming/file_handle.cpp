#include <stdio.h>
#include <stdlib.h>

struct file_handle {
  FILE* file;
  const char * name;

  file_handle(const char * filename) {
    file = fopen(filename, "r");
    if (!file) {
      perror("File opening failed");
      exit(EXIT_FAILURE);
    }
    name = filename;
    printf(" ===== opened file %s =====\n", name);
  }

  ~file_handle() {
    fclose(file);
    printf(" ===== closed %s file =====\n", name);
  }
};
typedef struct file_handle file_handle;

int main() {
  file_handle f("./file_handle.cpp");

  char buf[255];
  while (fgets(buf, sizeof(buf), f.file) != NULL) {
    printf("%s", buf);
  }

}
