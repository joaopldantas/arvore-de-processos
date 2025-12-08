#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void executaN(const char *nome, const char *cmd) {
    printf("[%s] PID=%d executando comando: %s\n", nome, getpid(), cmd);
    execl(cmd, cmd, NULL);
    perror("execl falhou");
    exit(1);
}

int main() {
    pid_t f1, f2;
    pid_t n1, n2, n3, n4;

    printf("[P1] PID=%d iniciado\n", getpid());

    f1 = fork();

    if (f1 == 0) {
        printf("[F1] PID=%d, Pai=%d\n", getpid(), getppid());
        n1 = fork();
        if (n1 == 0)
            executaN("N1", "/bin/date");

        n2 = fork();
        if (n2 == 0)
            executaN("N2", "/bin/pwd");

        wait(NULL);
        wait(NULL);

        printf("[F1] Sou processo filho. Meu PID=%d | Pai=%d\n",
               getpid(), getppid());
        exit(0);
    }

    f2 = fork();

    if (f2 == 0) {
        printf("[F2] PID=%d, Pai=%d\n", getpid(), getppid());
        n3 = fork();
        if (n3 == 0)
            executaN("N3", "/bin/ls");

        n4 = fork();
        if (n4 == 0)
            executaN("N4", "/usr/bin/whoami");

        wait(NULL);
        wait(NULL);

        printf("[F2] Sou processo filho. Meu PID=%d | Pai=%d\n",
               getpid(), getppid());
        exit(0);
    }

    wait(NULL); //F1
    wait(NULL); //F2

    printf("[P1] Sou o pai. PID=%d. Encerrando o programa.\n", getpid());
    return 0;
}