/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 21:46:26 by gt-serst          #+#    #+#             */
/*   Updated: 2023/06/07 10:58:04 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static void	init_struct(t_data *c, char **arg_list)
{
	c->cmd = NULL;
	c->cmdargs = NULL;
	c->paths = NULL;
	c->arg_list = arg_list;
}

static char	*get_env_path(char **envp)
{
	int		i;
	char	*path;

	i = 0;
	path = NULL;
	while (envp && envp[i])
	{
		path = ft_strnstr(envp[i], "PATH=", 5);
		if (path)
		{
			path = ft_substr(path, 5, ft_strlen(path));
			break ;
		}
		i++;
	}
	return (path);
}

static int	get_env_paths(t_data *c, char **envp)
{
	char	*path;

	path = get_env_path(envp);
	if (!path)
		return (0);
	c->paths = ft_split(path, ':');
	free(path);
	if (!c->paths)
		return (0);
	return (1);
}

static int	get_cmd(t_data *c, char *command)
{
	c->cmdargs = ft_split(command, ' ');
	if (!c->cmdargs)
		return (0);
	c->cmd = ft_strdup(c->cmdargs[0]);
	if (!c->cmd)
		return (0);
	return (1);
}

int	parsing(t_data *cmd1, t_data *cmd2, char **av, char **envp)
{
	init_struct(cmd1, av);
	init_struct(cmd2, av);
	if (!get_env_paths(cmd1, envp) || !get_env_paths(cmd2, envp)
		|| !get_cmd(cmd1, av[2]) || !get_cmd(cmd2, av[3]))
	{
		free_cmds(cmd1, cmd2);
		return (0);
	}
	return (1);
}
