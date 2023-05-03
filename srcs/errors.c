/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geraudtserstevens <geraudtserstevens@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 16:04:07 by gt-serst          #+#    #+#             */
/*   Updated: 2023/05/03 10:13:36 by geraudtsers      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_exit_msg(void)
{
	perror("pipex");
	exit(errno);
}

void	ft_exit_file(char *filename)
{
	write(2, "zsh: no such file or directory: ", 32);
	write(2, filename, ft_strlen(filename));
	write(2, "\n", 1);
	exit(0);
}

void	ft_exit_wrgcmd(t_data *c, int error_code)
{
	write(2, "zsh: command not found: ", 24);
	write(2, c->cmd, ft_strlen(c->cmd));
	write(2, "\n", 1);
	ft_free_struct(c);
	printf("error_code: %d\n", error_code);
	exit(error_code);
}
