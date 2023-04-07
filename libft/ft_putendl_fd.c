/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 15:00:20 by gt-serst          #+#    #+#             */
/*   Updated: 2022/12/07 16:08:43 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	unsigned int	temp;

	if (!s)
		return ;
	temp = 0;
	while (s[temp] != '\0')
	{
		write(fd, &s[temp], 1);
		temp++;
	}
	write(fd, "\n", 1);
}

/*
int main()
{
	ft_putendl_fd("Hello World!", 1);
	return (0);
}
*/
