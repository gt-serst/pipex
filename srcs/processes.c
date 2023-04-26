/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geraudtserstevens <geraudtserstevens@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 18:27:47 by gt-serst          #+#    #+#             */
/*   Updated: 2023/04/26 17:15:29 by geraudtsers      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static void	ft_close_pipe(t_pipex *pipex)
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
	while (mypaths && mypaths[i])
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

static void	ft_first_child(t_pipex *pipex, char **envp)
{
	char	*cmd;

	close(pipex->pipefd[0]);
	dup2(pipex->infile, 0);
	close(pipex->infile);
	dup2(pipex->pipefd[1], 1);
	cmd = ft_get_cmd(pipex->mypaths, pipex->cmd1->mycmd);
	if (!cmd)
	{
		free(cmd);
		ft_cmd_error(pipex, pipex->cmd1->mycmd, pipex->cmd1->mycmdargs);
	}
	execve(cmd, pipex->cmd1->mycmdargs, envp);
}

static void	ft_last_child(t_pipex *pipex, char **envp)
{
	char	*cmd;

	close(pipex->pipefd[1]);
	dup2(pipex->outfile, 1);
	close(pipex->outfile);
	dup2(pipex->pipefd[0], 0);
	cmd = ft_get_cmd(pipex->mypaths, pipex->cmd2->mycmd);
	if (!cmd)
	{
		free(cmd);
		ft_cmd_error(pipex, pipex->cmd2->mycmd, pipex->cmd2->mycmdargs);
	}
	execve(cmd, pipex->cmd2->mycmdargs, envp);
}

int	ft_parent_process(t_pipex *pipex, char **envp)
{
	int	status;

	if (pipe(pipex->pipefd) == -1)
		ft_pipe_error();
	pipex->cmd1->pid = fork();
	pipex->cmd1->pid = -1;
	if (pipex->cmd1->pid == -1)
		ft_fork_error();
	else if (pipex->cmd1->pid == 0)
		ft_first_child(pipex, envp);
	pipex->cmd2->pid = fork();
	if (pipex->cmd2->pid == -1)
		ft_fork_error();
	else if (pipex->cmd2->pid == 0)
		ft_last_child(pipex, envp);
	ft_close_pipe(pipex);
	waitpid(pipex->cmd1->pid, &status, 0);
	waitpid(pipex->cmd2->pid, &status, 0);
	return (status);
}
