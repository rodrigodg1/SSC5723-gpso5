#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Função que interrompe a execução
int main()
{
    for (int i = 0; 1; i++)
    {
        if (i == 50)
        {
            printf("Terminando o sistema");
            // Sai diretamente do sistema, retornando o status passado no parâmetro
            exit(0);
        }
    }

    printf("Essa linha não será executada!");

    return 0;
}
