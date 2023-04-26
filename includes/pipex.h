/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geraudtserstevens <geraudtserstevens@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 15:56:54 by gt-serst          #+#    #+#             */
/*   Updated: 2023/04/26 17:15:44 by geraudtsers      ###   ########.fr       */
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
	char	*mycmd;
	char	**mycmdargs;
	pid_t	pid;
}	t_data;

typedef struct s_pipex
{
	int		infile;
	int		outfile;
	char	**mypaths;
	int		pipefd[2];
	t_data	*cmd1;
	t_data	*cmd2;
}	t_pipex;

void	ft_fork_error(void);
void	ft_pipe_error(void);
void	ft_cmd_error(t_pipex *pipex, char *cmdname, char **cmdargs);
void	ft_file_error(t_pipex *pipex, char *filename);
int		ft_parsing(t_pipex *pipex, char **av, char **envp);
int		ft_parent_process(t_pipex *pipex, char **envp);
void	ft_free_child_process(char *cmd, char **cmdargs);
void	ft_free_cmds(t_pipex *pipex);
void	ft_free_paths(t_pipex *pipex);
void	ft_free_array(char **array);

#endif
