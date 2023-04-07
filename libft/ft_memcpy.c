/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 12:12:07 by geraudtsers       #+#    #+#             */
/*   Updated: 2022/12/06 20:03:51 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			tmp;
	unsigned char	*d;
	unsigned char	*s;

	if (!dst && (!src || !n))
		return (NULL);
	tmp = 0;
	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	while (tmp < n)
	{
		d[tmp] = s[tmp];
		tmp++;
	}
	return (dst);
}

/*
int	main()
{
	//char	dst[50] = "Hello";
	//char	src[50] = "Hello";
	int		size = 4;

	//printf("%s", ft_memcpy(0, src, size));
	//printf("%s", memcpy(0, src, size));

	//printf("%s", ft_memcpy(dst, 0, size));
	//printf("%s", memcpy(dst, 0, size));

	//printf("%s", ft_memcpy(dst, src, 0));
	//printf("%s", memcpy(dst, src, 0));

	//printf("%s", ft_memcpy(0, 0, size));
	//printf("%s", memcpy(0, 0, size));

	// printf("%s", ft_memcpy(dst, 0, 0));
	// printf("%s", memcpy(dst, 0, 0));

	// printf("%s", ft_memcpy(0, 0, 0));
	// printf("%s", memcpy(0, 0, 0));
	return (0);
}
*/
