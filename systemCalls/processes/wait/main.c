#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

// Função que cria um processo filho e o espera terminar
int main()
{
    /* Cria um processo clone do atual,
    se o clone é o primeiro, executa o código a seguir */
    if (fork() == 0)
    {
        printf("Child is starting\n");
        // Espera 3 segundos para testar
        sleep(3);
        printf("Child is finishing\n");
        exit(3);
    }
    else
    {
        // Espera por algum de seus filhos terminar
        wait(NULL);
        printf("Parent is finishing");
        exit(3);
    }
}
