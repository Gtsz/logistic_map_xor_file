#include <stdio.h>

#define BUF_LEN 4096
#define SKIP_N 30

int main(int argc, char *argv[]) {
  FILE *file_in, *file_out;
  unsigned char buffer[BUF_LEN];
  double x = 0.2, y;
  char *ptr;
  int i, j;
  
  if (argv[3])
  if (file_out = fopen(argv[2], "wb"))
  if (file_in = fopen(argv[1], "rb")) {
    for (i = 0, ptr = argv[3]; *ptr; ptr++, i++) {
      y = 1/(double)*ptr;
      for (j = i+SKIP_N; j >= 0; j--)
        y *= 4 - 4*y;
      x = (x+y) / 2;
    }
    
    while (i = fread(buffer, 1, BUF_LEN, file_in)) {
      for (j = 0; j < BUF_LEN; j++) {
        x *= 4 - 4*x;
        buffer[j] ^= *((unsigned char*)&x+7);
      }
      fwrite(buffer, 1, i, file_out);
    }
    fclose(file_in);
    fclose(file_out);
	return 0;
  }
  
  return -1;
}