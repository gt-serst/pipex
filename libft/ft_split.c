/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 12:00:34 by gt-serst          #+#    #+#             */
/*   Updated: 2023/03/23 17:45:23 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_malloc_error(char **tab)
{
	int	k;

	k = 0;
	while (tab && tab[k])
	{
		free(tab[k]);
		k++;
	}
	free(tab);
	return (NULL);
}

static int	ft_count_strs(const char *s, char c)
{
	int	k;
	int	m;

	k = 0;
	m = 0;
	while (s[k] != '\0')
	{
		while (s[k] != '\0' && s[k] == c)
			s++;
		if (s[k] != '\0')
			m++;
		while (s[k] != '\0' && s[k] != c)
			k++;
	}
	return (m);
}

static int	ft_word_length(const char *s, char c)
{
	int	k;

	k = 0;
	while (s[k] != '\0' && s[k] != c)
		k++;
	return (k);
}

static char	*ft_word(const char *s, char c)
{
	int		k;
	int		m;
	char	*str;

	k = 0;
	m = ft_word_length(s, c);
	str = malloc(sizeof(char) * (m + 1));
	if (!str)
		return (NULL);
	while (k < m)
	{
		str[k] = s[k];
		k++;
	}
	str[k] = '\0';
	return (str);
}

char	**ft_split(char const *s, char c)
{
	int		k;
	char	**tab;

	if (!s)
		return (NULL);
	tab = malloc(sizeof(char *) * (ft_count_strs(s, c) + 1));
	if (!tab)
		return (NULL);
	k = 0;
	while (*s != '\0')
	{
		while (*s != '\0' && *s == c)
			s++;
		if (*s != '\0')
		{
			tab[k] = ft_word(s, c);
			if (!tab[k])
				return (ft_malloc_error(tab));
			k++;
		}
		while (*s != '\0' && *s != c)
			s++;
	}
	tab[k] = 0;
	return (tab);
}

/*
int main()
{
	char const s[] = "Je suis en Belgique";
	char c = ' ';
	char **ptr;
	int tmp;

	ptr = ft_split(s, c);
	tmp = 0;
	while (ptr[tmp])
	{
		printf("%s\n", ptr[tmp]);
		tmp++;
	}
	system("leaks a.out");
	free(ptr);
	return (0);
}
*/
