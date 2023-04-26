/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 21:46:26 by gt-serst          #+#    #+#             */
/*   Updated: 2023/04/26 12:26:22 by gt-serst         ###   ########.fr       */
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

static char **ft_get_env_paths(char **envp)
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

static int	ft_get_cmd(char **mycmdargs, char *mycmd, char *cmd)
{
	mycmdargs = ft_split(cmd, ' ');
	//printf("Mycmdargs: %s\n", mycmdargs[1]);
	if (!mycmdargs)
		return (0);
	mycmd = ft_strdup(mycmdargs[0]);
	//printf("Mycmd: %s\n", mycmd);
	if (!mycmd)
	{
		ft_free_array(mycmdargs);
		return (0);
	}
	return (1);
}

int	ft_parsing(t_data *pipex, char **av, char **envp)
{
	pipex->mypaths = ft_get_env_paths(envp);
	if (!pipex->mypaths)
		return (0);
	if (!ft_get_cmd(&(*pipex->mycmd1args), &(*pipex->mycmd1), av[2]) ||
			!ft_get_cmd(&(*pipex->mycmd2args), &(*pipex->mycmd2), av[3]))
	{
			ft_free_childs(pipex);
			return (0);
	}
	//printf("Mycmd1: %s\n", pipex->mycmd1);
	return (1);
}
