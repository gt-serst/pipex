/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 12:20:37 by gt-serst          #+#    #+#             */
/*   Updated: 2023/06/14 16:55:16 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		tmp;
	char	*ptr;

	tmp = 0;
	while (s1[tmp] != '\0')
		tmp++;
	ptr = malloc(sizeof(char) * (tmp + 1));
	if (!ptr)
		return (NULL);
	tmp = 0;
	while (s1[tmp] != '\0')
	{
		ptr[tmp] = s1[tmp];
		tmp++;
	}
	ptr[tmp] = '\0';
	return (ptr);
}

/*
int main()
{
	const char	s1[] = "Hello";
	char		*ptr;

	ptr = ft_strdup(NULL);
	ptr = strdup(s1);
	free(ptr);
	return (0);
}
*/
