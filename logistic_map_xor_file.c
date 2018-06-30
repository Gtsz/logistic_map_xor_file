#include <stdio.h>

#define BUF_LEN 4096
#define MAX_ARR_LEN 2048
#define SKIP_N 30 // It's a key value
#define EXT_NAME ".lmx"

int main(int argc, char *argv[]) {
  unsigned char buffer[BUF_LEN];
  FILE *file_in, *file_out;
  char arr[MAX_ARR_LEN], *ptr;
  int i, j;
  double x = 0.2, y;
  
  if ((file_in = fopen(argv[1], "rb")) != NULL) {
    // Subprogram: key input
    printf ("Input your key here:\n");
    scanf ("%s", arr);
    
    // Subprogram: Initialize variable x
    for (i = 0, ptr = arr; *ptr; ptr++, i++) {
      y = 1/(double)*ptr;
      for (j = i+SKIP_N; j >= 0; j--)
        y *= 4 - 4*y;
      x = (x+y) / 2; // This method isn't perfect
    }
    //printf ("x = %lf\n", x); // DEBUG
    
    // Subprogram: Join the output path and open it
    for (i = 0, ptr = argv[1]; *ptr; ptr++, i++)
      arr[i] = *ptr;
    for (ptr = EXT_NAME; *ptr; ptr++)
      arr[i++] = *ptr;
    arr[i] = '\0';
    printf("Output: %s\n", arr);
    file_out = fopen(arr, "wb");
    
    // Subprogram: XOR the file
    while ((j = fread(buffer, 1, BUF_LEN, file_in)) != 0) {
      //printf ("%s", buffer); // DEBUG
      for (i = 0; i < BUF_LEN; i++) {
        x *= 4 - 4*x;
        buffer[i] ^= *((unsigned char*)&x+7); // bits from 57th to 64th
      }
      fwrite(buffer, 1, j, file_out);
    }
    fclose(file_out);
    fclose(file_in);
    printf("Process finished!");
  }
  
  //scanf ("%s", arr); // DEBUG
  return 0;
}
