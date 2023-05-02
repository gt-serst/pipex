/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 15:56:54 by gt-serst          #+#    #+#             */
/*   Updated: 2023/05/02 16:07:29 by gt-serst         ###   ########.fr       */
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
	int		f;
	char	*cmd;
	char	**cmdargs;
	char	**paths;
	pid_t	pid;
}	t_data;

void	ft_fork_error(void);
void	ft_pipe_error(void);
void	ft_cmd_error(t_data *cmd1, t_data *cmd2);
void	ft_file_error(char *filename);
int		ft_parsing(t_data *cmd1, t_data *cmd2, char **av, char **envp);
int		ft_parent_process(t_data *cmd1, t_data *cmd2, char **envp);
char	*ft_check_if_path_exists(char *command);
void	ft_free_struct(t_data *c);
void	ft_free(t_data *cmd1, t_data *cmd2);
void	ft_free_arr(char **arr);

#endif
