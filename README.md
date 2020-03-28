# SSC5723-gpso5
### Estrutura das pastas
- **systemCalls:** Programas da etapa 1 (system calls):
	- **ioAndFiles:** Programas para realizar *system calls* relacionadas a entra/saída e arquivos;
		- creat: Programa que cria um arquivo dado um nome definido no código;
		- readdir: Programa que abre a pasta atual e lista seus conteúdos (arquivos/pastas/links);
		- write: Programa que escreve uma string em um descritor de arquivo (nesse caso, o terminal);
	- **memory:** Programas para realizar *system calls* relacionadas ao gerenciamento de memória;
		- shmget: Programa que obtém um o identificador de um segmento de memória específico (no caso, um arquivo);
		- shmat: Programa que acopla um segmento de memória ao processo;
		- shmdt: Programa que que acopla e depois desacopla um segmento de memória do processo;
	- **processes:** Programas para realizar *system calls* relacionadas a processos
		- execve: Programa executa um outro passando argumentos;
		- exit: Programa que interrompe sua execução;
		- wait: Programa que cria um filho e o espera terminar sua execução;

- **cpuIOBound:** Programas da etapa 2 (CPU-bound/IO-bound);
	- cpuBound: Programa CPU-Bound, calcula os números primos até certo valor e a soma dos primos e dos não primos;
	- ioBound: Programa IO-Bound, lê os arquivos de cada pasta a partir da pasta root do sistema e escreve o resultado em um arquivo.

------------

### Como compilar?
Para compilar cada um dos arquivos, rode o comando:
`sudo gcc main.c`

------------

### Como executar?
Para executar cada um dos arquivos, rode o comando:
`./main`
