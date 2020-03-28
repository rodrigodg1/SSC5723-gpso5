#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Função que chama um programa de determinado arquivo passando argumentos
int main()
{
    // Argumentos a serem passados ao programa, o último deve ser nulo
    char *const argv[] = {"world", NULL};

    // Variáveis de ambiente a serem definidas ao programa, a última deve ser nula
    char *const envp[] = {NULL};

    int ret;

    /* Executa o programa especificado pelo primeiro argumento,
    passando como argumentos os valores do segundo argumento e como
    variáveis de sistema no formato chave-valor os valores do terceiro parâmetro
    */
    ret = execve("helloworld", argv, envp);

    // Se ocorrer algum erro, o retorno é -1
    if (ret == -1)
    {
        return -1;
    }

    return 0;
}
