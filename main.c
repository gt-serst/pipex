/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 16:52:30 by gt-serst          #+#    #+#             */
/*   Updated: 2023/04/07 19:11:39 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdio.h>

char	*ft_search_path_variable(char **envp, char *str)
{
	int	i;
	int	j;
	char	*PATH;

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
					PATH = ft_substr(envp[i], j + 1, ft_strlen(envp[i]));
					return (PATH);
				}
			}
		}
		i++;
	}
	return (NULL);
}

void	ft_get_paths_and_cmds(char **av, char **envp)
{
	char	*path_variable;
	char	**mypaths;
	char	**mycmds;

	path_variable = ft_search_path_variable(envp, "PATH=");
	printf("%s\n", path_variable);
	mypaths = ft_split(path_variable, ':');
	printf("%s\n", mypaths[0]);
	mycmds = ft_split(av[2], ' ');
	printf("%s\n", mycmds[0]);
}

int	main(int ac, char **av, char **envp)
{
	(void)ac;
	printf("%s\n", envp[11]);
	ft_get_paths_and_cmds(av, envp);
	return (0);
}
