/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geraudtserstevens <geraudtserstevens@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 18:27:47 by gt-serst          #+#    #+#             */
/*   Updated: 2023/05/03 10:34:50 by geraudtsers      ###   ########.fr       */
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

static void	ft_first_child(t_data *cmd1, int *pipefd, char **envp)
{
	char	*command;
	int		error_code;

	cmd1->f = open(cmd1->arg_list[1], O_RDONLY);
	if (cmd1->f < 0)
		ft_exit_file(cmd1->arg_list[1]);
	close(pipefd[0]);
	dup2(cmd1->f, 0);
	close(cmd1->f);
	dup2(pipefd[1], 1);
	command = ft_check_if_path_exists(cmd1->cmd);
	if (!command)
	{
		command = ft_get_cmd(cmd1->paths, cmd1->cmd);
		if (!command)
			ft_exit_wrgcmd(cmd1, 0);
	}
	error_code = execve(command, cmd1->cmdargs, envp);
	if (error_code == -1)
		ft_exit_msg();
}

static void	ft_last_child(t_data *cmd2, int *pipefd, char **envp)
{
	char	*command;
	int		error_code;

	cmd2->f = open(cmd2->arg_list[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (cmd2->f < 0)
		ft_exit_file(cmd2->arg_list[1]);
	close(pipefd[1]);
	dup2(cmd2->f, 1);
	close(cmd2->f);
	dup2(pipefd[0], 0);
	command = ft_check_if_path_exists(cmd2->cmd);
	if (!command)
	{
		command = ft_get_cmd(cmd2->paths, cmd2->cmd);
		if (!command)
			ft_exit_wrgcmd(cmd2, 127);
	}
	error_code = execve(command, cmd2->cmdargs, envp);
	if (error_code == -1)
		ft_exit_msg();
}

int	ft_parent_process(t_data *cmd1, t_data *cmd2, char **envp)
{
	int	status;
	int	pipefd[2];

	if (pipe(pipefd) == -1)
		ft_exit_msg();
	cmd1->pid = fork();
	if (cmd1->pid == -1)
		ft_exit_msg();
	else if (cmd1->pid == 0)
		ft_first_child(cmd1, pipefd, envp);
	cmd2->pid = fork();
	if (cmd2->pid == -1)
		ft_exit_msg();
	else if (cmd2->pid == 0)
		ft_last_child(cmd2, pipefd, envp);
	ft_close_pipe(pipefd);
	waitpid(cmd1->pid, &status, 0);
	waitpid(cmd2->pid, &status, 0);
	return (status);
}
