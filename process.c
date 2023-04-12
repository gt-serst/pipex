/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 21:45:48 by gt-serst          #+#    #+#             */
/*   Updated: 2023/04/12 22:00:20 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_child_process(int infile, int outfile, t_data *pipex, char **envp, int *pipefd)
{
	int		i;
	char	*cmd;

	printf("Je suis dans le processus enfant");
	dup2(infile, STDIN_FILENO);
	dup2(pipefd[1], STDOUT_FILENO);
	if (dup2 < 0)
	{
		perror("dup");
		exit(0);
	}
	close(pipefd[0]);
	close(outfile);
	i = 0;
	while (pipex->mypaths[i])
	{
		cmd = ft_strjoin(pipex->mypaths[i], pipex->mycmd1);
		execve(cmd, pipex->mycmd1args, envp);
		free(cmd);
		i++;
	}
	exit(1);
}

void	ft_parent_process(int infile, int outfile, t_data *pipex, char **envp, int *pipefd)
{
	int		i;
	char	*cmd;
	int 	status;

	printf("Je suis dans le processus parent");
	waitpid(-1, &status, 0);
	dup2(outfile, STDOUT_FILENO);
	dup2(pipefd[0], STDIN_FILENO);
	if (dup2 < 0)
	{
		perror("dup");
		exit(0);
	}
	close(pipefd[1]);
	close(infile);
	i = 0;
	while (pipex->mypaths[i])
	{
		cmd = ft_strjoin(pipex->mypaths[i], pipex->mycmd2);
		execve(cmd, pipex->mycmd2args, envp);
		free(cmd);
		i++;
	}
	exit(1);
}

