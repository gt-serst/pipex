/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 18:27:47 by gt-serst          #+#    #+#             */
/*   Updated: 2023/04/18 16:57:04 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static void	ft_close_pipe(t_data *pipex)
{
	close(pipex->pipefd[0]);
	close(pipex->pipefd[1]);
}

static char	*ft_get_cmd(char **mypaths, char *mycmd)
{
	int		i;
	char	*tmp;
	char	*command;

	i = 0;
	while (mypaths[i])
	{
		tmp = ft_strjoin(mypaths[i], "/");
		command = ft_strjoin(tmp, mycmd);
		free(tmp);
		if (access(command, 0) == 0)
			return (command);
		free(command);
		i++;
	}
	return (NULL);
}

static void	ft_first_child(t_data *pipex, char **envp)
{
	close(pipex->pipefd[0]);
	dup2(pipex->infile, 0);
	close(pipex->infile);
	dup2(pipex->pipefd[1], 1);
	pipex->cmd = ft_get_cmd(pipex->mypaths, pipex->mycmd1);
	if (!pipex->cmd)
		ft_cmd_error(pipex, pipex->mycmd1);
	execve(pipex->cmd, pipex->mycmd1args, envp);
}

static void	ft_last_child(t_data *pipex, char **envp)
{
	close(pipex->pipefd[1]);
	dup2(pipex->outfile, 1);
	close(pipex->outfile);
	dup2(pipex->pipefd[0], 0);
	pipex->cmd = ft_get_cmd(pipex->mypaths, pipex->mycmd2);
	if (!pipex->cmd)
		ft_cmd_error(pipex, pipex->mycmd2);
	execve(pipex->cmd, pipex->mycmd2args, envp);
}

int	ft_parent_process(t_data *pipex, char **envp)
{
	int	status;

	if (pipe(pipex->pipefd) == -1)
		ft_pipe_error(pipex);
	pipex->pid1 = fork();
	if (pipex->pid1 == -1)
		ft_fork_error(pipex);
	else if (pipex->pid1 == 0)
		ft_first_child(pipex, envp);
	pipex->pid2 = fork();
	if (pipex->pid2 == -1)
		ft_fork_error(pipex);
	else if (pipex->pid2 == 0)
		ft_last_child(pipex, envp);
	ft_close_pipe(pipex);
	waitpid(pipex->pid1, &status, 0);
	waitpid(pipex->pid2, &status, 0);
	return (status);
}
