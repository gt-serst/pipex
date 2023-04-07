/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 19:17:46 by geraudtsers       #+#    #+#             */
/*   Updated: 2022/12/07 16:34:11 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	unsigned int	tmp;

	if (!s)
		return ;
	tmp = 0;
	while (s[tmp] != '\0')
	{
		write(fd, &s[tmp], 1);
		tmp++;
	}
}

/*
int main()
{
	ft_putstr_fd(Hello World!, 1);
	return (0);
}
*/
