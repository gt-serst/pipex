/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geraudtserstevens <geraudtserstevens@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 21:46:26 by gt-serst          #+#    #+#             */
/*   Updated: 2023/04/25 23:29:03 by geraudtsers      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	*ft_get_path(char **envp, char *str)
{
	int		i;
	int		j;
	char	*path_variable;

	i = 0;
	while (envp[i] && str)
	{
		j = 0;
		if (envp[i][j] == str[j])
		{
			while (envp[i][j] && str[j] && envp[i][j] == str[j])
			{
				j++;
				if (str[j + 1] == '\0')
				{
					path_variable = ft_substr(envp[i], j + 1,
							ft_strlen(envp[i]));
					return (path_variable);
				}
			}
		}
		i++;
	}
	return (NULL);
}

static int ft_get_cmd(t_data *pipex, char **envp, char *cmd)
{
	char	*path_variable;

	path_variable = ft_get_path(envp, "PATH=");
	if (!path_variable)
		return (0);
	pipex->mypaths = ft_split(path_variable, ':');
	if (!pipex->mypaths)
	{
		free(path_variable);
		return (0);
	}
	
}

void	ft_get_paths_and_cmds(t_data *pipex, char **av, char **envp)
{
	char	*path_variable;
	char	*tmp;

	path_variable = ft_search_path_variable(envp, "PATH=");
	pipex->mypaths = ft_split(path_variable, ':');
	free(path_variable);
	if (!ft_get_cmd(pipex, envp, av[2]) || !ft_get_cmd(pipex, envp, av[3]))
		return (ft_free_childs(pipex));
	pipex->mycmd1args = ft_split(av[2], ' ');
/*
	tmp = ft_strdup("");
	pipex->mycmd1 = ft_strjoin(tmp, pipex->mycmd1args[0]);
	free(tmp);
*/
	pipex->mycmd2args = ft_split(av[3], ' ');
	tmp = ft_strdup("");
	pipex->mycmd2 = ft_strjoin(tmp, pipex->mycmd2args[0]);
	free(tmp);
}
