/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 16:04:07 by gt-serst          #+#    #+#             */
/*   Updated: 2023/06/07 10:55:30 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	exit_msg(void)
{
	perror("pipex");
	exit(errno);
}

void	exit_file(char *filename, int cmd_nb)
{
	if (errno == 2)
	{
		write(2, "zsh: no such file or directory: ", 32);
		write(2, filename, ft_strlen(filename));
		write(2, "\n", 1);
	}
	else if (errno == 13)
	{
		write(2, "zsh: permission denied: ", 24);
		write(2, filename, ft_strlen(filename));
		write(2, "\n", 1);
	}
	if (cmd_nb == 1)
		exit(0);
	else
		exit(1);
}

void	exit_wrgcmd(t_data *c, int error_code)
{
	write(2, "zsh: command not found: ", 24);
	write(2, c->cmd, ft_strlen(c->cmd));
	write(2, "\n", 1);
	free_struct(c);
	exit(error_code);
}
