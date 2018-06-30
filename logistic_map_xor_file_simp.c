// A simple program for file encryption
#include <stdio.h>

#define BUF_LEN 4096
#define SKIP_N 30 // It's a key value

int main(int argc, char *argv[]) {
  unsigned char buffer[BUF_LEN];
  FILE *file_in, *file_out;
  char *ptr;
  int i, j;
  double x = 0.2, y;
  
  if (argv[3]) // Key string
  if (file_out = fopen(argv[2], "wb"))
  if (file_in = fopen(argv[1], "rb")) {
    // Initializing
    for (i = 0, ptr = argv[3]; *ptr; ptr++, i++) {
      y = 1/(double)*ptr;
      for (j = i+SKIP_N; j >= 0; j--)
        y *= 4 - 4*y;
      x = (x+y) / 2; // This method isn't perfect
    }
    //printf ("x = %lf\n", x); // DEBUG
    
    // Stream cipher: logistic map, XOR
    while ((j = fread(buffer, 1, BUF_LEN, file_in)) != 0) {
      //printf ("%s", buffer); // DEBUG
      for (i = 0; i < BUF_LEN; i++) {
        x *= 4 - 4*x;
        buffer[i] ^= *((unsigned char*)&x+3); // bits from 57th to 64th
      }
      fwrite(buffer, 1, j, file_out);
    }
    fclose(file_out);
    fclose(file_in);
    printf("Process finished!");
	return 0;
  }
  
  printf("parameter missing, args: <path_in> <path_out> <key>\n");
  return 0;
}
