#include <Windows.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
	// argv[0]: this program
	// argv[1]: input
	FILE *file_out, *file_in;
	char arr[2048];
	char *ptr;
	const int BUFFER_LENGTH = 4096;
	char *ext_name = ".lmx";
	unsigned char buffer[BUFFER_LENGTH];
	int i, j;
	double x = 0.2, y;
	
	if ((file_in = fopen(argv[1], "rb")) != NULL) {
		printf ("Type your arr:\n");
		scanf ("%s", arr);
		printf ("%s\n%s\n%s\n", argv[0], argv[1], arr); // DEBUG
		
		for (i = 0, ptr = arr; *ptr != '\0'; ptr++, i++) {
			printf ("times: %d\n", i); // DEBUG
			y = 1/(double)*ptr;
			printf ("y: %lf\n", y); // DEBUG
			for (j = i+3; j >= 0; j--) {
				y *= 4 - 4*y;
				printf ("-y: %lf\n", y); // DEBUG
			}
			x = (x+y) / 2;
		}
		printf ("x: %lf\n", x); // DEBUG
		
		// Join strings
		for (i = 0, ptr = argv[1]; *ptr != '\0'; ptr++, i++)
			arr[i] = *ptr;
		for ( ; *ext_name != '\0'; ext_name++)
			arr[i++] = *ext_name;
		arr[i] = '\0';
		printf("path: %s", arr);
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
	}
	
	scanf ("%s", arr); // DEBUG
	return 0;
}
