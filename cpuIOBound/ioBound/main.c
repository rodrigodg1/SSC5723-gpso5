#include <dirent.h>
#include <errno.h>
#include <sys/types.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>

// Função para escrever em um arquivo
int writeInFile(char *string, int fileDesc)
{
    // Ponteiro para percorrer as strings para salvar no arquivo
    char *p;
    // Resposta da chamada de escrita
    int writeRes;

    // Percorre a string enquanto o ponteiro não aponta para o fim da string "\0"
    for (p = string; *p; p++)
    {
        /* Escreve no file descriptor específico do arquivo criado*/
        writeRes = write(fileDesc, p, 1);

        if (writeRes == -1)
        {
            printf("Erro ao escrever!");
            return -1;
        }
    }
}

// Função que abre a primeira pasta de cada pasta e a percorre, salvando o resultado em um arquivo
int main()
{
    // File descriptor (refere-se a entrada da tabela de arquivos abertos do sistema)
    int fileDesc;
    // Endereço do arquivo
    char *pathname = "./dirs";
    // Ponteiro que aponta para o diretório atual
    DIR *dir;
    // Diretório da pasta atual (começa pela root)
    char dirPath[1000] = "/";
    // Ponteiro para uma entrada da pasta (arquivo, pasta, link)
    struct dirent *dirEntry;

    // cria o arquivo
    fileDesc = open(pathname, O_CREAT | O_WRONLY | O_TRUNC | O_APPEND);

    if (fileDesc == -1)
    {
        printf("Erro! Provavelmente o arquivo já existe.");
        return -1;
    }

    // Abre a pasta enquanto ela existir
    while (1)
    {
        // Diretório da próxima pasta a abrir
        char nextDirPath[1000] = "";

        dir = opendir(dirPath);

        if (dir == NULL)
        {
            break;
        }

        writeInFile("\nArquivos da pasta", fileDesc);
        writeInFile(dirPath, fileDesc);
        writeInFile(":\n", fileDesc);

        /* Percorre os arquivos da pasta em cada chamada readdir passando a pasta como parâmetro 
            enquanto a resposta não é NULL*/
        while ((dirEntry = readdir(dir)) != NULL)
        {
            writeInFile(dirEntry->d_name, fileDesc);
            writeInFile("\n", fileDesc);

            if (dirEntry->d_type == DT_DIR && !nextDirPath[0] && strcmp(dirEntry->d_name, ".") && strcmp(dirEntry->d_name, ".."))
            {
                strcpy(nextDirPath, dirEntry->d_name);
            }
        }

        // Fecha a pasta
        closedir(dir);

        if (nextDirPath[0])
        {
            strcat(dirPath, nextDirPath);
            strcat(dirPath, "/");
        }
        else
        {
            break;
        }
    }

    return 0;
}
