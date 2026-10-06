vv#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid;

    // Crear el proceso hijo
    pid = fork();

    if (pid < 0) {
        perror("Error en fork()");
        return EXIT_FAILURE;
    } 
    else if (pid == 0) {
        // Proceso hijo: imprime números del 10,000 al 1
        for (int i = 10000; i >= 1; i--) {
            printf("[HIJO] Numero: %d\n", i);
        }
        exit(EXIT_SUCCESS);
    } 
    else {
        // Proceso padre: imprime números del 1 al 10,000
        for (int i = 1; i <= 10000; i++) {
            printf("[PADRE] Numero: %d\n", i);
        }
        
        // Esperar a que el proceso hijo termine
        wait(NULL);
    }

    return EXIT_SUCCESS;
}