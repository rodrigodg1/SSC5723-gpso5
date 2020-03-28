#include <dirent.h>
#include <errno.h>
#include <sys/types.h>
#include <stdio.h>

// Função que abre uma pasta e a percorre
int main()
{
    // Ponteiro que aponta para um diretório
    DIR *dir;

    // Ponteiro para uma entrada da pasta (arquivo, pasta, link)
    struct dirent *dirEntry;

    // Abre a pasta atual
    dir = opendir("./");

    if (dir == NULL)
    {
        printf("Ocorreu um erro ao abrir a pasta.");
        return -1;
    }

    printf("Arquivos da pasta:\n");

    /* Percorre os arquivos da pasta em cada chamada readdir passando a pasta como parâmetro 
    enquanto a resposta não é NULL*/
    while ((dirEntry = readdir(dir)) != NULL)
    {
        printf("%s\n", dirEntry->d_name);
    }

    // Fecha a pasta
    closedir(dir);

    return 0;
}
