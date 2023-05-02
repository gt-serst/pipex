/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 18:27:47 by gt-serst          #+#    #+#             */
/*   Updated: 2023/05/02 16:14:18 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static void	ft_close_pipe(int *pipefd)
{
	close(pipefd[0]);
	close(pipefd[1]);
}

static char	*ft_get_cmd(char **paths, char *cmd)
{
	int		i;
	char	*tmp;
	char	*command;

	i = 0;
	while (paths && paths[i])
	{
		tmp = ft_strjoin(paths[i], "/");
		command = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(command, 0) == 0)
			return (command);
		free(command);
		i++;
	}
	return (NULL);
}

static void	ft_first_child(t_data *cmd1, t_data *cmd2, int *pipefd, char **envp)
{
	char	*command;

	close(pipefd[0]);
	dup2(cmd1->f, 0);
	close(cmd1->f);
	dup2(pipefd[1], 1);
	command = ft_check_if_path_exists(cmd1->cmd);
	if (!command)
	{
		command = ft_get_cmd(cmd1->paths, cmd1->cmd);
		if (!command)
			ft_cmd_error(cmd1, cmd2);
	}
	execve(command, cmd1->cmdargs, envp);
}

static void	ft_last_child(t_data *cmd1, t_data *cmd2, int *pipefd, char **envp)
{
	char	*command;

	close(pipefd[1]);
	dup2(cmd2->f, 1);
	close(cmd2->f);
	dup2(pipefd[0], 0);
	command = ft_check_if_path_exists(cmd2->cmd);
	if (!command)
	{
		command = ft_get_cmd(cmd2->paths, cmd2->cmd);
		if (!command)
			ft_cmd_error(cmd2, cmd1);
	}
	execve(command, cmd2->cmdargs, envp);
}

int	ft_parent_process(t_data *cmd1, t_data *cmd2, char **envp)
{
	int	status;
	int	pipefd[2];

	if (pipe(pipefd) == -1)
		ft_pipe_error();
	cmd1->pid = fork();
	if (cmd1->pid == -1)
		ft_fork_error();
	else if (cmd1->pid == 0)
		ft_first_child(cmd1, cmd2, pipefd, envp);
	cmd2->pid = fork();
	if (cmd2->pid == -1)
		ft_fork_error();
	else if (cmd2->pid == 0)
		ft_last_child(cmd1, cmd2, pipefd, envp);
	ft_close_pipe(pipefd);
	waitpid(cmd1->pid, &status, 0);
	waitpid(cmd2->pid, &status, 0);
	return (status);
}
