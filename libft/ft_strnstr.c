/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 16:53:24 by geraudtsers       #+#    #+#             */
/*   Updated: 2022/12/06 20:06:44 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haycast, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*needle == 0)
		return ((char *)haycast);
	while (haycast[i] != 0 && i < len)
	{
		j = 0;
		while (haycast[i + j] == needle[j] && \
				haycast[i + j] != 0 && (i + j) != len)
		{
			if (!needle[j + 1])
			{
				return ((char *)haycast + i);
			}
			j++;
		}
		i++;
	}
	return (NULL);
}

/*
int	main()
{
	char	s1[] = "lorem ipsum dolor sit amet";
	char	s2[] = "dolor";

	printf("%s\n", ft_strnstr(s1, s2, 0));
	printf("%s", strnstr(s1, s2, 0));
	return (0);
}
*/
