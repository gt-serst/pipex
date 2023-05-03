/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geraudtserstevens <geraudtserstevens@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 15:56:54 by gt-serst          #+#    #+#             */
/*   Updated: 2023/05/03 11:04:30 by geraudtsers      ###   ########.fr       */
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
# include <sys/errno.h>
# include "../libft/libft.h"

typedef struct s_data
{
	int		f;
	char	*cmd;
	char	**cmdargs;
	char	**paths;
	char	**arg_list;
	pid_t	pid;
}	t_data;

/*	DATA EXTRACTION		*/
int		ft_parsing(t_data *cmd1, t_data *cmd2, char **av, char **envp);

/*		PROCESS			*/
int		ft_parent_process(t_data *cmd1, t_data *cmd2, char **envp);
char	*ft_check_if_path_exists(char *command);

/*		DATA CLEANING	*/
void	ft_free_struct(t_data *c);
void	ft_free(t_data *cmd1, t_data *cmd2);
void	ft_free_arr(char **arr);

/*		ERROR MSG		*/
void	ft_exit_msg(void);
void	ft_exit_file(char *filename);
void	ft_exit_wrgcmd(t_data *c, int error_code);

#endif
