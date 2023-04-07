/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 13:09:19 by geraudtsers       #+#    #+#             */
/*   Updated: 2022/12/06 20:06:27 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	len_src;
	size_t	tmp;

	len_src = ft_strlen(src);
	tmp = 0;
	if (dstsize)
	{
		while ((src[tmp] != '\0') && (tmp < (dstsize - 1)))
		{
			dst[tmp] = src[tmp];
			tmp++;
		}
		dst[tmp] = 0;
	}
	return (len_src);
}

/*
int main()
{
	char	dst[] = "Plopinette";
	char	src[] = "";

	ft_strlcpy(dst, src, 10);
	printf("%s\n", dst);
	strlcpy(dst, src, 10);
	printf("%s", dst);
	return (0);
}
*/
