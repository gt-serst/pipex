/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 21:47:11 by gt-serst          #+#    #+#             */
/*   Updated: 2023/04/14 20:40:23 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_pipex(int infile, int outfile, t_data *pipex, char **envp)
{
  	int		pipefd[2];
	pid_t	pid;

	if (pipe(pipefd) == -1)
	{
		ft_free_malloc(pipex);
		ft_exit("pipe");
	}
	pid = fork();
	//pid = -1;
	//perror("Error");
	if (pid == -1)
	{
		ft_free_malloc(pipex);
		ft_exit("fork");
	}
	else if (pid == 0)
		ft_child_process(infile, pipex, envp, pipefd);
	else
		ft_parent_process(outfile, pipex,  envp, pipefd);
}
