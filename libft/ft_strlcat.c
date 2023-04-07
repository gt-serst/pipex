/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 14:08:28 by geraudtsers       #+#    #+#             */
/*   Updated: 2022/12/06 20:05:42 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len_dst;
	size_t	len_src;
	size_t	len;
	size_t	tmp;

	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	len = 0;
	tmp = 0;
	if (dstsize == 0)
		len = len_src;
	else if (dstsize < len_dst)
		len = len_src + dstsize;
	else
		len = len_src + len_dst;
	if (dstsize)
	{
		while ((len_dst + tmp) < (dstsize - 1) && src[tmp] != 0)
		{
			dst[len_dst + tmp] = src[tmp];
			tmp++;
		}
		dst[len_dst + tmp] = 0;
	}
	return (len);
}

/*
int main()
{
	char	dst[] = "Plopinette";
	char	src[] = "Kikou";

	ft_strlcat(dst, src, 10);
	printf("%s\n", dst);
	strlcat(dst, src, 10);
	printf("%s", dst);
	return (0);
}
*/
