#include <Windows.h>
#include <stdio.h>

#define BUFFER_LENGTH 4096
#define MAX_ARRAY_LENGTH 2048
#define SKIP_N 30 // It's a key value
#define EXT_NAME ".lmx"
int main(int argc, char *argv[]) {
	unsigned char buffer[BUFFER_LENGTH];
	FILE *file_in, *file_out;
	char arr[MAX_ARRAY_LENGTH], *ptr;
	int i, j;
	double x = 0.2, y;
	
	if ((file_in = fopen(argv[1], "rb")) != NULL) {
		printf ("Type your key here:\n");
		scanf ("%s", arr);
		
		for (i = 0, ptr = arr; *ptr != '\0'; ptr++, i++) {
			y = 1/(double)*ptr;
			for (j = i+SKIP_N; j >= 0; j--)
				y *= 4 - 4*y;
			x = (x+y) / 2;
		}
		printf ("x = %lf\n", x); // DEBUG
		
		for (i = 0, ptr = argv[1]; *ptr != '\0'; ptr++, i++)
			arr[i] = *ptr;
		for (ptr = EXT_NAME; *ptr != '\0'; ptr++)
			arr[i++] = *ptr;
		arr[i] = '\0';
		printf("Output: %s\n", arr);
		file_out = fopen(arr, "wb");
		
		while ((j = fread(buffer, 1, BUFFER_LENGTH, file_in)) != 0){
			//printf ("%s", buffer); // DEBUG
			for (i = 0; i < BUFFER_LENGTH; i++) {
				x *= 4 - 4*x;
				buffer[i] ^= *(unsigned char*)&x;
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
