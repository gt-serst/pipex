/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 17:09:47 by gt-serst          #+#    #+#             */
/*   Updated: 2023/06/14 16:55:16 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	tmp;

	if (!s)
		return (0);
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
