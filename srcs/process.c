/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 16:38:04 by gt-serst          #+#    #+#             */
/*   Updated: 2023/04/17 18:25:34 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 21:45:48 by gt-serst          #+#    #+#             */
/*   Updated: 2023/04/17 16:37:58 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	*ft_get_cmd(char **mypaths, char *mycmd)
{
	int		i;
	char	*command;

	i = 0;
	while (mypaths[i])
	{
		command = ft_strjoin(mypaths[i], mycmd);
		if (access(command, 0) == 0)
			return (command);
		free(command);
		i++;
	}
	return (NULL);
}

void	ft_child_process(t_data *pipex, char **envp)
{
	if (dup2(pipex->infile, 0) < 0 || dup2(pipex->pipefd[1], 1) < 0)
	{
		ft_free_malloc(pipex);
		ft_exit("dup");
	}
	close(pipex->pipefd[0]);
	close(pipex->infile);
	pipex->cmd = ft_get_cmd(pipex->mypaths, pipex->mycmd1);
	if (!pipex->cmd)
	{
		ft_free_malloc(pipex);
		ft_exit("command");
	}
	execve(pipex->cmd, pipex->mycmd1args, envp);
}

void	ft_parent_process(t_data *pipex, char **envp)
{
	printf("Je suis dans le processus parent");
	waitpid(pipex->pid, NULL, 0);
	if (dup2(pipex->outfile, 1) < 0 || dup2(pipex->pipefd[0], 0) < 0)
	{
		ft_free_malloc(pipex);
		ft_exit("dup");
	}
	close(pipex->pipefd[1]);
	close(pipex->outfile);
	pipex->cmd = ft_get_cmd(pipex->mypaths, pipex->mycmd2);
	if (!pipex->cmd)
	{
		ft_free_malloc(pipex);
		ft_exit("command");
	}
	execve(pipex->cmd, pipex->mycmd2args, envp);
}
