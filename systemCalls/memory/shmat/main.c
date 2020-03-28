#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

// Função que acopla um segmento de memória ao processo
int main()
{
    int shmid;
    int size = 1024;
    char *path = "/file";
    // Endereço da memória alocada
    char *mem;

    /* Cria um segmento de memória, ver exemplo do shmget */
    shmid = shmget(ftok(path, 120), size, 0);

    if (shmid == -1)
    {
        return -1;
    }

    /* Shmat aceita três parâmetros, o id do segmento de memória, 
    um endereço especificado para acoplar o segmento na memória do processo (0 se não for necessário) e 
    opções gerais numa flag (0 se não necessário)
    */
    mem = shmat(shmid, 0, 0);

    if (mem == (char *)-1)
    {
        return -1;
    }

    printf("mem: %p", mem);

    return 0;
}
