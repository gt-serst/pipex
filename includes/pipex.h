/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 15:56:54 by gt-serst          #+#    #+#             */
/*   Updated: 2023/06/07 10:59:37 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
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

/*		DATA EXTRACTION		*/
int		parsing(t_data *cmd1, t_data *cmd2, char **av, char **envp);

/*		PROCESS			*/
int		parent_process(t_data *cmd1, t_data *cmd2, char **envp);
char	*check_if_path_exists(char *command);

/*		DATA CLEANING	*/
void	free_struct(t_data *c);
void	free_cmds(t_data *cmd1, t_data *cmd2);
void	free_arr(char **arr);

/*		ERROR MSG		*/
void	exit_msg(void);
void	exit_file(char *filename, int cmd_nb);
void	exit_wrgcmd(t_data *c, int error_code);

#endif
