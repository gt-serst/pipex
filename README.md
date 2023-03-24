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

