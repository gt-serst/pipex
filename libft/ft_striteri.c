/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 18:59:03 by geraudtsers       #+#    #+#             */
/*   Updated: 2022/12/08 16:19:04 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	tmp;

	if (!s || !f)
		return ;
	tmp = 0;
	while (s[tmp] != '\0')
	{
		f(tmp, &s[tmp]);
		tmp++;
	}
}
