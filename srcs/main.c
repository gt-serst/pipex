/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 16:52:30 by gt-serst          #+#    #+#             */
/*   Updated: 2023/05/04 17:21:24 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr && arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	ft_free(t_data *cmd1, t_data *cmd2)
{
	ft_free_struct(cmd1);
	ft_free_struct(cmd2);
}

void	ft_free_struct(t_data *c)
{
	if (c->cmd)
		free(c->cmd);
	if (c->cmdargs)
		ft_free_arr(c->cmdargs);
	if (c->paths)
		ft_free_arr(c->paths);
}

int	main(int ac, char **av, char **envp)
{
	int		status;
	t_data	cmd1;
	t_data	cmd2;

	if (ac != 5)
		return (1);
	if (!ft_parsing(&cmd1, &cmd2, av, envp))
		return (1);
	status = ft_parent_process(&cmd1, &cmd2, envp);
	ft_free(&cmd1, &cmd2);
	if (WIFEXITED(status))
	{
		if (WEXITSTATUS(status) != 0)
			exit(WEXITSTATUS(status));
	}
	if (WIFSIGNALED(status))
	{
		if (WTERMSIG(status) == SIGTERM)
			ft_exit_msg();
		else if (WTERMSIG(status) == SIGKILL)
			ft_exit_msg();
	}
	return (EXIT_SUCCESS);
}
