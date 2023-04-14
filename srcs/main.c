/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 16:52:30 by gt-serst          #+#    #+#             */
/*   Updated: 2023/04/14 20:36:50 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_free_array(char **array)
{
	int	i;

	i = 0;
	while (array && array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	ft_free_malloc(t_data *pipex)
{
	ft_free_array(pipex->mypaths);
	ft_free_array(pipex->mycmd1args);
	ft_free_array(pipex->mycmd2args);
	free(pipex->mycmd1);
	free(pipex->mycmd2);
	free(pipex);
}

void	ft_exit(char *msg)
{
	perror(msg);
	system("leaks a.out");
	exit(EXIT_FAILURE);
}

int	main(int ac, char **av, char **envp)
{
	int	infile;
	int outfile;
	t_data	*pipex;

	if (ac == 5)
	{
		pipex = malloc(sizeof(t_data));
		if (!pipex)
			return (1);
		infile = open(av[1], O_RDONLY);
		outfile = open(av[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
		if (infile < 0 || outfile < 0)
			return (1);
		ft_get_paths_and_cmds(pipex, av, envp);
		ft_pipex(infile, outfile, pipex, envp);
		ft_free_malloc(pipex);
		//system("leaks a.out");
		return (0);
	}
	else
		return (1);
}
