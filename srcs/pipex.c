/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 21:47:11 by gt-serst          #+#    #+#             */
/*   Updated: 2023/04/17 18:25:32 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_pipex(t_data *pipex, char **envp)
{
	if (pipe(pipex->pipefd) == -1)
	{
		ft_free_malloc(pipex);
		ft_exit("pipe");
	}
	pipex->pid = fork();
	if (pipex->pid == -1)
	{
		ft_free_malloc(pipex);
		ft_exit("fork");
	}
	else if (pipex->pid == 0)
		ft_child_process(pipex, envp);
	else
		ft_parent_process(pipex,  envp);
}
