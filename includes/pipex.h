/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 15:56:54 by gt-serst          #+#    #+#             */
/*   Updated: 2023/04/18 18:14:37 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include "../libft/libft.h"

typedef struct s_data
{
	int		infile;
	int		outfile;
	char	**mypaths;
	char	*mycmd1;
	char	*mycmd2;
	char	**mycmd1args;
	char	**mycmd2args;
	int		pipefd[2];
	pid_t	pid1;
	pid_t	pid2;
	char	*cmd;
}	t_data;

void	ft_fork_error(void);
void	ft_pipe_error(void);
void	ft_cmd_error(t_data *pipex, char *cmdname);
void	ft_file_error(t_data *pipex, char *filename);
void	ft_get_paths_and_cmds(t_data *pipex, char **av, char **envp);
int		ft_parent_process(t_data *pipex, char **envp);
void	ft_free_childs(t_data *pipex);
void	ft_free_parent(t_data *pipex);

#endif
