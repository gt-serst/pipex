/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 15:31:36 by geraudtsers       #+#    #+#             */
/*   Updated: 2022/12/05 16:38:23 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			tmp;
	unsigned char	*str;
	unsigned char	chr;

	tmp = 0;
	str = (unsigned char *)s;
	chr = (unsigned char)c;
	while (tmp < n)
	{
		if (*str == chr)
			return (str);
		str++;
		tmp++;
	}
	return (NULL);
}

/*
int	main()
{
	char s[] = {0, 1, 2 ,3 ,4 ,5};
	char		*d1 = memchr(s, 0, 0);
	char		*d2 = ft_memchr(s, 0, 0);
	// char		*d1 = memchr("bonjourno", 'n', 2);
	// char		*d2 = ft_memchr("bonjourno", 'n', 2);

	printf("%s\n", d1);
	printf("%s", d2);
	if (d1 == d2)
		printf("SUCCESS");
	return (0);
}
*/
