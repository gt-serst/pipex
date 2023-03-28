# pipex

## Theory

##### Each UNIX process is associated to 3 distincts flows :
##### 1) standard input (STDIN), by default it is associated to the keyboard.
##### 2) standard output (STDOUT), by default it is associated to the terminal.
##### 3) standard error output (STDERR), by default it is associated to the same terminal as before.
![LBRdx](https://user-images.githubusercontent.com/81758850/227573016-34338578-1fc4-4dc1-a7af-5d1c708a8227.png)
##### Shell allows to combinate commands by redirected standard inputs and standard outputs. By putting \< follows by the name of the file, you are able to read the standard input in this file. Then, it is also possible to redirected the standard output in a file with \> and \>>.
##### But there is an easier way to combinate multiples commands. It is about the redirection of the standard output of a program in the standard input of another. We use the symbol | (pipe) to realize it.
![WX5NN](https://user-images.githubusercontent.com/81758850/227573480-db345907-f66d-4482-a743-99dd734c671f.png)

## Allowed functions:

#### I will only describe functions that I have never seen before.
* perror(), strerror() are systems error messages.
* access() is used to check the accesibility of a file by giving in parameters both the path corresponding to the file and the mode which describes the access permission to be checked.
* dup() duplicates an existing file descriptor and returns its value (file2 = dup(file1)).
* dup2() allows to access the new descriptor, file2, and returns its value.
* execve() executes a file by transforming the calling process into a new process. The path of the file is referenced in the first parameter, the argument argv contains the argument list available to the new process and finally the envp is the last parameter and is linked to the global variable environ.
* fork() creates a new process which is a copy of the calling process (parent process) and will be executed at the same time. If successful, the function returns a value of 0 to the child process.
####Proto : pid\_t fork(void);
* pipe() creates a pipe, unidirectionnal channel between processes. pipefd is used to return two files descriptor refering to the pipe extremity. The pipe function returns a null value if we are in the child process, positive value if we are in the parent process and a negative value if an error occurs.
* unlink() detroys a name and eventually the file associated. The function returns 0 if successful.
* wait() stops the calling process until a child process change its state. Therefore, obtaining new child informations is possible.
`Proto : pid_t wait(int *status)`
Code :-
<html>
	<body>
		<p>`Proto : pid_t wait(int *status)`</p>
	</body>
</html>
* waitpid() works like wait() but for a specific child differenciates by its pid.
    `Hello This is a code`

    `` Using `single back ticks` inside double back ticks``
