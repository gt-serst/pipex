/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 16:04:07 by gt-serst          #+#    #+#             */
/*   Updated: 2023/05/02 16:24:12 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_file_error(char *filename)
{
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

void	ft_cmd_error(t_data *c)
{
	write(2, "zsh: command not found: ", 24);
	write(2, c->cmd, ft_strlen(c->cmd));
	write(2, "\n", 1);
	ft_free_struct(c);
	exit(EXIT_FAILURE);
}
