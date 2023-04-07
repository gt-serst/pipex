/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geraudtserstevens <geraudtserstevens@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 12:20:37 by gt-serst          #+#    #+#             */
/*   Updated: 2022/12/01 10:30:37 by geraudtsers      ###   ########.fr       */
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
