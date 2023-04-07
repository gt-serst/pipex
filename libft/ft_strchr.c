/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 14:08:45 by geraudtsers       #+#    #+#             */
/*   Updated: 2022/12/05 16:56:40 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		tmp;
	char	chr;

	tmp = 0;
	chr = (char)c;
	while (s[tmp] != '\0' && s[tmp] != chr)
		tmp++;
	if (s[tmp] == chr)
		return ((char *) s + tmp);
	else
		return (NULL);
}

/*
int	main()
{
	char s[] = {0, 1, 2 ,3 ,4 ,5};
	char		*d1 = strchr(s, 4);
	char		*d2 = ft_strchr(s, 4);
	// char		*d1 = strchr("bonjourno", 'n');
	// char		*d2 = ft_strchr("bonjourno", 'n');

	printf("%s\n", d1);
	printf("%s", d2);
	if (d1 == d2)
		printf("SUCCESS");
	return (0);
}
*/
