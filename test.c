#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
int main(int ac, char **argv)
{
    (void)ac;
    int pid = fork();
    write(1, "salut\n", 6);
    if (pid == 0)
    {
        //close(1);
        execv(argv[1], argv);
        exit(0);
    }
    else
        waitpid(pid, NULL, 0);
    write(1, "OK\n", 3);
}