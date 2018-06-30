// A simple program for file encryption (insecure)
#include <stdio.h>

#define BUF_LEN 4096
#define SKIP_N 30 // Incompatible if this value changes

int main(int argc, char *argv[]) {
  FILE *file_in, *file_out;
  unsigned char buffer[BUF_LEN];
  double x = 0.2, y;
  char *ptr;
  int i, j;
  
  if (argv[3]) // Key string
  if (file_out = fopen(argv[2], "wb"))
  if (file_in = fopen(argv[1], "rb")) {
    // Initializing the cipher stream
    for (i = 0, ptr = argv[3]; *ptr; ptr++, i++) {
      y = 1/(double)*ptr;
      for (j = i+SKIP_N; j >= 0; j--)
        y *= 4 - 4*y;
      x = (x+y) / 2;
    }
    //printf ("x = %lf\n", x); // DEBUG
    
    while (i = fread(buffer, 1, BUF_LEN, file_in)) {
      //printf ("%s", buffer); // DEBUG
      for (j = 0; j < BUF_LEN; j++) {
        x *= 4 - 4*x; // Logistic Map
        buffer[j] ^= *((unsigned char*)&x+7); // XOR
      }
      fwrite(buffer, 1, i, file_out);
    }
    fclose(file_in);
    fclose(file_out);
    printf("Process finished!\n");
	return 0;
  }
  
  printf("Parameter(s) missing, args: <path_in> <path_out> <key>\n");
  return 0;
}