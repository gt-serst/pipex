/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 21:46:26 by gt-serst          #+#    #+#             */
/*   Updated: 2023/04/18 18:15:55 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	*ft_search_path_variable(char **envp, char *str)
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

void	ft_get_paths_and_cmds(t_data *pipex, char **av, char **envp)
{
	char	*path_variable;
	char	*tmp;

	path_variable = ft_search_path_variable(envp, "PATH=");
	pipex->mypaths = ft_split(path_variable, ':');
	free(path_variable);
	pipex->mycmd1args = ft_split(av[2], ' ');
	tmp = ft_strdup("");
	pipex->mycmd1 = ft_strjoin(tmp, pipex->mycmd1args[0]);
	free(tmp);
	pipex->mycmd2args = ft_split(av[3], ' ');
	tmp = ft_strdup("");
	pipex->mycmd2 = ft_strjoin(tmp, pipex->mycmd2args[0]);
	free(tmp);
}
