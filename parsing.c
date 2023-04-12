/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 21:46:26 by gt-serst          #+#    #+#             */
/*   Updated: 2023/04/12 22:00:14 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_search_path_variable(char **envp, char *str)
{
	int	i;
	int	j;
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
					path_variable = ft_substr(envp[i], j + 1, ft_strlen(envp[i]));
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

	/* GET PATH VARIABLE*/
	path_variable = ft_search_path_variable(envp, "PATH=");
	printf("%s\n", path_variable);
	/* GET ALL PATHS */ 
	pipex->mypaths = ft_split(path_variable, ':');
	printf("%s\n", pipex->mypaths[0]);
	/* GET ALL CMD1 OPTIONS */
	pipex->mycmd1args = ft_split(av[2], ' ');
	printf("%s\n", pipex->mycmd1args[1]);
	/* GET CMD1 */
	pipex->mycmd1 = ft_strdup("/");
	pipex->mycmd1 = ft_strjoin(pipex->mycmd1, pipex->mycmd1args[0]);
	printf("%s\n", pipex->mycmd1);
	/* GET ALL CMD2 OPTIONS */
	pipex->mycmd2args = ft_split(av[3], ' ');
	printf("%s\n", pipex->mycmd2args[1]);
	/* GET CMD2 */
	pipex->mycmd2 = ft_strdup("/");
	pipex->mycmd2 = ft_strjoin(pipex->mycmd2, pipex->mycmd2args[0]);
	printf("%s\n", pipex->mycmd2);
}
