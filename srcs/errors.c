/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 16:04:07 by gt-serst          #+#    #+#             */
/*   Updated: 2023/04/18 18:14:48 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_file_error(t_data *pipex, char *filename)
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

void	ft_cmd_error(t_data *pipex, char *cmdname)
{
	write(2, "zsh: command not found: ", 24);
	write(2, cmdname, ft_strlen(cmdname));
	write(2, "\n", 1);
	ft_free_childs(pipex);
	exit(EXIT_FAILURE);
}
