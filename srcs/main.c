/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 16:52:30 by gt-serst          #+#    #+#             */
/*   Updated: 2023/04/18 16:57:08 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static void	ft_free_array(char **array)
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

void	ft_free_struct(t_data *pipex)
{
	ft_free_array(pipex->mypaths);
	ft_free_array(pipex->mycmd1args);
	free(pipex->mycmd1);
	ft_free_array(pipex->mycmd2args);
	free(pipex->mycmd2);
	free(pipex);
}

int	main(int ac, char **av, char **envp)
{
	int		status;
	t_data	*pipex;

	if (ac != 5)
		return (1);
	pipex = malloc(sizeof(t_data));
	if (!pipex)
		return (0);
	pipex->infile = open(av[1], O_RDONLY);
	if (pipex->infile < 0)
		ft_file_error(av[1]);
	pipex->outfile = open(av[4], O_CREAT | O_RDWR | O_TRUNC, 644);
	if (pipex->outfile < 0)
		ft_file_error(av[4]);
	ft_get_paths_and_cmds(pipex, av, envp);
	status = ft_parent_process(pipex, envp);
	ft_free_struct(pipex);
	if (WEXITSTATUS(status) != 0)
		exit(WEXITSTATUS(status));
	return (status);
}
