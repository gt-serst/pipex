/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geraudtserstevens <geraudtserstevens@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 21:46:26 by gt-serst          #+#    #+#             */
/*   Updated: 2023/04/28 19:04:30 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static void	ft_init_struct(t_data *c)
{
	c->cmd = NULL;
	c->cmdargs = NULL;
	c->paths = NULL;
}

static char	*ft_get_env_path(char **envp)
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

static int	ft_get_env_paths(t_data *c, char **envp)
{
	char	*path;

	path = ft_get_env_path(envp);
	if (!path)
		return (0);
	c->paths = ft_split(path, ':');
	free(path);
	if (!c->paths)
		return (0);
	return (1);
}

static int	ft_get_cmd(t_data *c, char *command)
{
	c->cmdargs = ft_split(command, ' ');
	if (!c->cmdargs)
		return (0);
	c->cmd = ft_strdup(c->cmdargs[0]);
	if (!c->cmd)
		return (0);
	return (1);
}

int	ft_parsing(t_data *cmd1, t_data *cmd2, char **av, char **envp)
{
	ft_init_struct(cmd1);
	ft_init_struct(cmd2);
	if (!ft_get_env_paths(cmd1, envp) || !ft_get_env_paths(cmd2, envp)
		|| !ft_get_cmd(cmd1, av[2]) || !ft_get_cmd(cmd2, av[3]))
	{
		ft_free(cmd1, cmd2);
		return (0);
	}
	return (1);
}
