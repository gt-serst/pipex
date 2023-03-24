# pipex

# Theory

# Each UNIX process is associated to 3 distincts flows :
# 1) standard input (stdin)
# 2) standard output (stdout)
# 3) standard error output (stderr)
# Shell allows to combinate commands by redirected standard inputs and standard outputs. By putting \< follows by the name of the file, you are able to read the standard input in this file. Then, it is also possible to redirected the standard output in a file with \> and \>>.
# But there is an easier way to combinate multiples commands. It is about the redirection of the standard output of a program in the standard input of another. We use the symbol | (pipe) to realize it.
