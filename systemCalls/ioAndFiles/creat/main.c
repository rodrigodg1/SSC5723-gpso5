#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

// Função que cria um arquivo específico
int main()
{
    // File descriptor (refere-se a entrada da tabela de arquivos abertos do sistema)
    int fileDesc;
    // Endereço do arquivo
    char *pathname = "./file";

    fileDesc = creat(pathname, O_RDWR);

    if (fileDesc == -1)
    {
        printf("Erro! Provavelmente o arquivo já existe.");
        return -1;
    }

    printf("file descriptor: %d", fileDesc);

    return 0;
}
