#include <stdio.h>
#include <stdlib.h>


void localice(const char *extension) {
	char Ejercicio2[256];
	snprintf(Ejercicio2, sizeof(Ejercicio2), "find /home/meylymendoza -name \"*.%s\" -mtime -5", extension);
	printf("Archivos de los ùltimos 5 dìas .%s:\n", extension);

	system(Ejercicio2);
	printf("\n");
}

int main() {
	localice("txt");
    localice("jpg");
    localice("pdf");
    localice("c");
	return 0;
}
