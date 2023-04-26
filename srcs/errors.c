/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geraudtserstevens <geraudtserstevens@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 16:04:07 by gt-serst          #+#    #+#             */
/*   Updated: 2023/04/26 17:16:23 by geraudtsers      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_file_error(t_pipex *pipex, char *filename)
{
	free(pipex);
	write(2, "zsh: no such file or directory: ", 32);
	write(2, filename, ft_strlen(filename));
	write(2, "\n", 1);
	exit(EXIT_FAILURE);
}

void	ft_pipe_error(void)
{
	perror("pipe");
	exit(EXIT_FAILURE);
}

void	ft_fork_error(void)
{
	perror("fork");
	exit(EXIT_FAILURE);
}

void	ft_cmd_error(t_pipex *pipex, char *cmdname, char **cmdargs)
{
	write(2, "zsh: command not found: ", 24);
	write(2, cmdname, ft_strlen(cmdname));
	write(2, "\n", 1);
	ft_free_child_process(cmdname, cmdargs);
	ft_free_paths(pipex);
	system("leaks pipex");
	exit(EXIT_FAILURE);
}
