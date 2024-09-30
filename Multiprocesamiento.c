#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    for (int i = 0; i < 3; i++) {
        pid_t pid = fork();

        if (pid < 0) {
            perror("Error al crear hijo");
            exit(1);
        } else if (pid == 0) {
            printf("Hijo %d (PID: %d) contando hasta 1000:\n", i + 1, getpid());
            for (int j = 1; j <= 1000; j++) {
                if (j % 100 == 0) {
                    printf("Hijo %d: %d\n", i + 1, j);
                }
            }
            exit(0);
        }
    }

    for (int i = 0; i < 3; i++) {
        wait(NULL);
    }

    printf("Todos los procesos hijos han terminado...\n");
    return 0;
}
