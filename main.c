/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 16:52:30 by gt-serst          #+#    #+#             */
/*   Updated: 2023/04/12 21:50:55 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
		free(pipex);
		return (0);
	}
	else
		return (1);
}
