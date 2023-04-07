/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 12:34:54 by geraudtsers       #+#    #+#             */
/*   Updated: 2022/12/06 20:03:43 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			tmp;
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	if (dst > src)
	{
		tmp = len;
		while (tmp > 0)
		{
			d[tmp - 1] = s[tmp - 1];
			tmp--;
		}
	}
	else if (dst < src)
	{
		tmp = 0;
		while (tmp != len)
		{
			d[tmp] = s[tmp];
			tmp++;
		}
	}
	return (dst);
}

/*
int main()
{
	char    src[] = "lorem ipsum dolor sit amet";
	char    *dst;

	dst = src + 1;
	ft_memmove(dst, src, 8);
	printf("%s\n", dst);
	//memmove(dst, src, 8);
	//printf("%s", dst);
	return (0);
}
*/
