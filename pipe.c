#include <stdlib.h>
#include <stdio.h>

int main()
{
    int fd[2], n;
    char buff[100];
    pid_t pid;
    p = fork();
    if (p > 0)
    { // parent
        close(fd[0]);
        printf("Passing to child");
        wirte(fd[1], "Hello ", 12);
        wait();
    }
    else
    {
        close(fd[1]);
        n = read(fd[0], buff, 100);
        write(1, buff, n);
    }
}