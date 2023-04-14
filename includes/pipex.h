/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 15:56:54 by gt-serst          #+#    #+#             */
/*   Updated: 2023/04/14 17:11:50 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "../libft/libft.h"

typedef struct s_data
{
	char	**mypaths;
	char	*mycmd1;
	char	*mycmd2;
	char	**mycmd1args;
	char	**mycmd2args;
}	t_data;

void	ft_get_paths_and_cmds(t_data *pipex, char **av, char **envp);
void	ft_pipex(int infile, int outfile, t_data *pipex, char **envp);
void	ft_exit(char *message, t_data *pipex);
void	ft_child_process(int infile, t_data *pipex, char **envp, int *pipefd);
void	ft_parent_process(int outfile, t_data *pipex, char **envp, int *pipefd);

#endif
