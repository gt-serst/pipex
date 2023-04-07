/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:37:02 by gt-serst          #+#    #+#             */
/*   Updated: 2022/12/08 18:49:19 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_charset(char const *set, char c)
{
	int	tmp;

	tmp = 0;
	while (set && set[tmp])
	{
		if (set[tmp] == c)
			return (1);
		tmp++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		tmp;
	int		start;
	int		end;
	char	*str;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && ft_charset(set, s1[start]) == 1)
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_charset(set, s1[end - 1]) == 1)
		end--;
	str = malloc(sizeof(char) * (end - start + 1));
	if (!str)
		return (NULL);
	tmp = 0;
	while (start < end)
		str[tmp++] = s1[start++];
	str[tmp] = '\0';
	return (str);
}

/*
int main()
{
	char	s1[] = "lorem ipsum dolor sit amet";
	char	set[] = "tel";
	char	*ptr;

	ptr = ft_strtrim(s1, set);
	printf("%s\n", ptr);
	free(ptr);
	return (0);
}
*/
