#include <stdio.h>
#include <stdlib.h>

/* função exemplo de programa CPU-bound que atribui em um vetor o valor 1
 para números primos e 0 para números não primos e depois soma todos os primos e todos os não primos*/
int main()
{
    int numbersPrimeValue[10000];
    int primeSum = 0;
    int nonPrimeSum = 0;

    // 0 e 1 não são primos, 2 é
    numbersPrimeValue[0] = 0;
    numbersPrimeValue[1] = 0;
    numbersPrimeValue[2] = 1;

    // percorre todos os números de 3 a 10000 para procurar por números primos
    for (int i = 3; i < 10000; i++)
    {
        int isPrime = 1;

        // percorre todos os números do 2 até ele para ver se o número é divisível
        for (int j = 2; j <= i / 2; ++j)
        {
            // se o número for divisível, não é primo
            if (i % j == 0)
            {
                isPrime = 0;
                break;
            }
        }

        numbersPrimeValue[i] = isPrime;
    }

    for (int i = 0; i < 10000; i++)
    {
        if (numbersPrimeValue[i] == 1)
        {
            primeSum += i;
        }
        else
        {
            nonPrimeSum += i;
        }
    }
}
