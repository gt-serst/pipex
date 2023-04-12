/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 21:47:11 by gt-serst          #+#    #+#             */
/*   Updated: 2023/04/12 21:48:48 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_pipex(int infile, int outfile, t_data *pipex, char **envp)
{
  	int		pipefd[2];
	pid_t	pid;

	if (pipe(pipefd) == -1)
	{
		perror("pipe");
		exit(0);
	}
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(0);
	}
	else if (pid == 0)
		ft_child_process(infile, outfile, pipex, envp, pipefd);
	else
		ft_parent_process(infile, outfile, pipex,  envp, pipefd);
}
