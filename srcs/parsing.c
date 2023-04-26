/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geraudtserstevens <geraudtserstevens@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 21:46:26 by gt-serst          #+#    #+#             */
/*   Updated: 2023/04/26 15:35:38 by geraudtsers      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

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

static char	**ft_get_env_paths(char **envp)
{
	char	*path;
	char	**paths;

	path = ft_get_env_path(envp);
	if (!path)
		return (NULL);
	paths = ft_split(path, ':');
	free(path);
	if (!paths)
		return (NULL);
	return (paths);
}

static int	ft_get_cmd(t_data *c, char *cmd)
{
	c->mycmdargs = NULL;
	c->mycmdargs = ft_split(cmd, ' ');
	if (!c->mycmdargs)
		return (0);
	c->mycmd = NULL;
	c->mycmd = ft_strdup(c->mycmdargs[0]);
	if (!c->mycmd)
		return (0);
	return (1);
}

int	ft_parsing(t_pipex *pipex, char **av, char **envp)
{
	pipex->cmd1 = malloc(sizeof(t_data));
	if (!pipex->cmd1)
		return (0);
	pipex->cmd2 = malloc(sizeof(t_data));
	if (!pipex->cmd2)
	{
		free(pipex->cmd1);
		return (0);
	}
	pipex->mypaths = ft_get_env_paths(envp);
	if (!pipex->mypaths)
	{
		ft_free_cmds(pipex);
		return (0);
	}
	if (!ft_get_cmd(pipex->cmd1, av[2])
		|| !ft_get_cmd(pipex->cmd2, av[3]))
	{
		ft_free_array(pipex->mypaths);
		ft_free_cmds(pipex);
		return (0);
	}
	return (1);
}
