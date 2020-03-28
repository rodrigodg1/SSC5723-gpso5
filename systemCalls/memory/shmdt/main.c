#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

// Função que acopla e depois desacopla um segmento de memória do processo
int main()
{
    int shmid;
    int size = 1024;
    char *path = "/file";
    char *mem;
    int dtres;

    /* Cria um segmento de memória, ver exemplo do shmget */
    shmid = shmget(ftok(path, 119), size, 0);

    if (shmid == -1)
    {
        return -1;
    }

    /* Acopla o segmento no processo */
    mem = shmat(shmid, 0, 0);

    if (mem == (char *)-1)
    {
        return -1;
    }

    /* Desacolpa o segmento do processo, a função aceita um parâmetro,
    o endereço de memória do segmento */
    dtres = shmdt(mem);

    printf("response: %d", dtres);

    return 0;
}
