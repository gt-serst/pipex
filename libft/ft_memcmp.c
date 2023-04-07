/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 16:41:54 by geraudtsers       #+#    #+#             */
/*   Updated: 2022/12/05 17:25:00 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			tmp;
	unsigned char	*str1;
	unsigned char	*str2;

	tmp = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (tmp < n)
	{
		if (str1[tmp] != str2[tmp])
			return (str1[tmp] - str2[tmp]);
		tmp++;
	}
	return (0);
}

/*
int	main()
{
	char	s1[] = "\xff\0\0\xaa\0\xde\xffMACOSX\xff";
	char	s2[] = "\xff\0\0\xaa\0\xde\x00MBS";

	int	d1 = memcmp(s1, s2, 9);
	int	d2 = ft_memcmp(s1, s2, 9);

	printf("%d\n", d1);
	printf("%d", d2);
	if (d1 == d2)
		printf("SUCCESS");
	return (0);
}
*/
