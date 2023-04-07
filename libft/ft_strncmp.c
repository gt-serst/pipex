/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 14:46:50 by geraudtsers       #+#    #+#             */
/*   Updated: 2022/12/05 17:29:18 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	tmp;

	tmp = 0;
	if (n == 0)
		return (0);
	while (s1[tmp] != '\0' && tmp < n - 1 && s1[tmp] == s2[tmp])
		tmp++;
	return ((unsigned char)s1[tmp] - (unsigned char)s2[tmp]);
}
*/

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			tmp;
	unsigned char	*str1;
	unsigned char	*str2;

	tmp = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while ((str1[tmp] != '\0' || str2[tmp] != '\0') && tmp < n)
	{
		if (str1[tmp] != str2[tmp])
			return (str1[tmp] - str2[tmp]);
		tmp++;
	}
	return (0);
}

/*
int main()
{
	const char s1[] = "test";
	const char s2[] = "tests";

	printf("%d\n", ft_strncmp(s1, s2, 7));
	printf("%d", strncmp(s1, s2, 7));

	return (0);
}
*/
