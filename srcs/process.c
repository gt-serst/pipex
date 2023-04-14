/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 21:45:48 by gt-serst          #+#    #+#             */
/*   Updated: 2023/04/14 17:56:46 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_child_process(int infile, t_data *pipex, char **envp, int *pipefd)
{
	int		i;
	char	*cmd;

	printf("Je suis dans le processus enfant");
	dup2(infile, 0);
	dup2(pipefd[1], 1);
	if (dup2 < 0)
		ft_exit("dup", pipex);
	close(pipefd[0]);
	close(infile);
	i = 0;
	while (pipex->mypaths[i])
	{
		cmd = ft_strjoin(pipex->mypaths[i], pipex->mycmd1);
/*
		if (access(cmd, F_OK) == -1)
			ft_exit("access", pipex);
*/
		execve(cmd, pipex->mycmd1args, envp);
		free(cmd);
		i++;
	}
	ft_exit("execve", pipex);
}

void	ft_parent_process(int outfile, t_data *pipex, char **envp, int *pipefd)
{
	int		i;
	char	*cmd;
	//int 	status;

	printf("Je suis dans le processus parent");
	waitpid(0, NULL, 0);
	dup2(outfile, 1);
	dup2(pipefd[0], 0);
	if (dup2 < 0)
		ft_exit("dup", pipex);
	close(pipefd[1]);
	close(outfile);
	i = 0;
	while (pipex->mypaths[i])
	{
		cmd = ft_strjoin(pipex->mypaths[i], pipex->mycmd2);
/*
		if (access(cmd, F_OK) == -1)
			ft_exit("access", pipex);
*/
		execve(cmd, pipex->mycmd2args, envp);
		free(cmd);
		i++;
	}
	ft_exit("execve", pipex);
}

