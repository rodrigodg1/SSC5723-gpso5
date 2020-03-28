#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

// Função que obtém um o identificador de um segmento de memória específico
int main()
{
    // identificador do segmento de memória do processo
    int shmid;
    // tamanho do segmento
    int size = 1024;
    // caminho do arquivo a ser lido (obs.: criar arquivo no caminho especificado antes de executar)
    char *path = "./file";

    /* obtém o identificador a  partir de um novo arquivo gerado no caminho 
    especificado com uma chave qualquer, com o tamanho de 1024 bytes.
    As flags utilizadas no último parâmetro são:
    IPC_CREAT - cria um novo segmento ao invés de buscar pela chave
    IPC_EXCL - assegura que o segmento será criado, caso contrário ocrre uma falha
    SHM_R - permissão para leitura
    SHM_W - permissão para escrita*/
    shmid = shmget(ftok(path, 122), size, IPC_CREAT | IPC_EXCL | SHM_R | SHM_W);

    if (shmid == -1)
    {
        return -1;
    }

    printf("shmid: %d", shmid);

    return 0;
}
