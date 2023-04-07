/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 14:45:07 by geraudtsers       #+#    #+#             */
/*   Updated: 2022/11/30 18:38:30 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		tmp;
	char	chr;

	tmp = ft_strlen(s);
	chr = (char)c;
	while (tmp >= 0)
	{
		if (s[tmp] == chr)
			return ((char *) s + tmp);
		tmp--;
	}
	return (NULL);
}

/*
int	main()
{
	char *d1 = strrchr("teste", 'e' + 1024);
	char *d2 = ft_strrchr("teste", 'e' + 1024);

	printf("%s\n", d1);
	printf("%s", d2);
	if (d1 == d2)
		printf("SUCCESS");

	return (0);
}
*/
