# pipex

## Context
##### Reproduce shell pipe operator in C.
##### The program will be executed like this 
`./pipex infile cmd1 cmd2 outfile` 
##### so it takes 4 arguments : infile outfile are files names and cmd1 cmd2 are shell commands with their parameters.
## Theory
##### Each UNIX process is associated to 3 distincts flows :
##### 1) standard input (STDIN), by default it is associated to the keyboard.
##### 2) standard output (STDOUT), by default it is associated to the terminal.
##### 3) standard error output (STDERR), by default it is associated to the same terminal as before.
![LBRdx](https://user-images.githubusercontent.com/81758850/227573016-34338578-1fc4-4dc1-a7af-5d1c708a8227.png)
##### Shell allows to combinate commands by redirected standard inputs and standard outputs. By putting \< follows by the name of the file, you are able to read the standard input in this file. Then, it is also possible to redirected the standard output in a file with \> and \>>.
##### But there is an easier way to combinate multiples commands. It is about the redirection of the standard output of a program in the standard input of another. We use the symbol | (pipe) to realize it.
![WX5NN](https://user-images.githubusercontent.com/81758850/227573480-db345907-f66d-4482-a743-99dd734c671f.png)

## Allowed functions :

#### I will only describe functions that I have never seen before.
* perror(), strerror() are systems error messages.
* access() is used to check the accesibility of a file by giving in parameters both the path corresponding to the file and the mode which describes the access permission to be checked. <br>
`int access(const char *path, int mode);`
* dup() duplicates an existing file descriptor and returns its value (newfd = dup(oldfd). <br>
`int dup(int oldfd);`
* dup2() works like dup. The difference between them is that dup automoticcaly chose the smallest number of fd currently available while with dup2 we can specify the number we want. <br>
`int dup2(int oldfd, int newfd);`
* execve() executes a file by transforming the calling process into a new process. The path of the file is referenced in the first parameter, the argument argv contains the argument list available to the new process and finally the envp is the last parameter and is linked to the global variable environ. <br>
`int execve(const char *path, char *const argv[], char *const envp[]);`
* fork() creates a new process which is a copy of the calling process (parent process) and will be executed at the same time. If successful, the function returns a value of 0 to the child process. <br>
`pid_t fork(void);`
* pipe() creates a pipe, unidirectionnal channel between processes. pipefd is used to return two files descriptor refering to the pipe extremity. The pipe function returns a null value if we are in the child process, positive value if we are in the parent process and a negative value if an error occurs. <br>
`int pipe(int pipefd[2]);`
* unlink() delete a file descriptor. The function returns 0 if successful. <br>
`int unlink(const char *pathname);`
* wait() stops the calling process until a child process change its state. Therefore, obtaining new child informations is possible. <br>
`pid_t wait(int *status);`
* waitpid() works like wait() but for a specific child differenciates by its pid. <br>
`pid_t waitpid(pid_t pid, int *status, int options);`
## Logic to reproduce the shell pipe '|' operator
##### First we have to extract arguments send by the shell command. arg[0] is the executive file, arg[1] is the file we used to execute the cmd1, arg[2] is the cmd1, arg[3] is the cmd2 and arg[4] is the file used to execute the cmd2, therefore it is the output of cmd1. To execute commands, we need the path of the infile and outfile.
1. Launch a pipe before getting a child.
* pipefd[0] : end of reading
* pipefd[1] : end of writing
2. Use a fork to allow child process have a pair of fd which are corresponding to the same pipe without forget to use waitpid otherwise the parent ends and don't wait for the child's change of state. Therefore, child process will become zombie (orphan childs) process which wait for their parents to take them into account.
3. Play with fd's thanks to dup and redirecting the standard output of child one in the standard input of child two.
