/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geraudtserstevens <geraudtserstevens@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 16:52:30 by gt-serst          #+#    #+#             */
/*   Updated: 2023/04/26 16:10:51 by geraudtsers      ###   ########.fr       */
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

void	ft_free_child_process(char *cmd, char **cmdargs)
{
	int	i;

	i = 0;
	while (cmdargs && cmdargs[i])
	{
		free(cmdargs[i]);
		i++;
	}
	free(cmdargs);
	free(cmd);
}

void	ft_free_cmds(t_pipex *pipex)
{
	if (!pipex->cmd1->mycmdargs)
		ft_free_array(pipex->cmd1->mycmdargs);
	if (!pipex->cmd1->mycmd)
		free(pipex->cmd1->mycmd);
	if (!pipex->cmd2->mycmdargs)
		ft_free_array(pipex->cmd2->mycmdargs);
	if (!pipex->cmd2->mycmd)
		free(pipex->cmd2->mycmd);
	free(pipex->cmd1);
	free(pipex->cmd2);
}

void	ft_free_paths(t_pipex *pipex)
{
	ft_free_array(pipex->mypaths);
	free(pipex);
}

int	main(int ac, char **av, char **envp)
{
	int		status;
	t_pipex	*pipex;

	if (ac != 5)
		return (1);
	pipex = malloc(sizeof(t_pipex));
	if (!pipex)
		return (1);
	pipex->infile = open(av[1], O_RDONLY);
	if (pipex->infile < 0)
		ft_file_error(pipex, av[1]);
	pipex->outfile = open(av[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (pipex->outfile < 0)
		ft_file_error(pipex, av[4]);
	if (!ft_parsing(pipex, av, envp))
	{
		free(pipex);
		return (1);
	}
	status = ft_parent_process(pipex, envp);
	ft_free_paths(pipex);
	if (WEXITSTATUS(status) != 0)
		exit(WEXITSTATUS(status));
	return (status);
}
