#include <unistd.h>

// Função que escreve uma string em um buffer de saída (no caso o terminal)
int main()
{
    // String que será escrita
    char *string = "Exemplo de string";
    // Ponteiro para percorrer a string
    char *p;
    // Resposta da chamada de escrita
    int writeRes;

    // Percorre a string enquanto o ponteiro não aponta para o fim da string "\0"
    for (p = string; *p; p++)
    {
        /* Escreve no file descriptor específico (no caso, 1 significa o próprio terminal - primeiro argumento)
        do buffer "p" (segundo argumento) 1 byte (terceiro argumento) */
        writeRes = write(1, p, 1);

        if (writeRes == -1)
        {
            printf("Erro ao escrever!");
            return -1;
        }
    }

    return 0;
}
