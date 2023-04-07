/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 17:09:47 by geraudtsers       #+#    #+#             */
/*   Updated: 2022/11/30 18:03:29 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	tmp;

	tmp = 0;
	while (s[tmp] != 0)
		tmp++;
	return (tmp);
}

/*
int main()
{
	char s[] = "Cobra";

	printf("%d", ft_strlen(s));
	return (0);
}
*/
