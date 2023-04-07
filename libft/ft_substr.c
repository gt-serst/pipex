/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 13:35:49 by gt-serst          #+#    #+#             */
/*   Updated: 2023/04/07 16:58:28 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	tmp;
	size_t	size;
	char	*substr;

	if (s[0] == '\0' || start > (unsigned int)ft_strlen(s))
	{
		substr = malloc(sizeof(char) * 1);
		if (!substr)
			return (NULL);
		substr[0] = '\0';
		return (substr);
	}
	size = 0;
	while (size < len && s[start + size] != '\0')
		size++;
	substr = (char *)malloc(sizeof(char) * (size + 1));
	if (!substr)
		return (NULL);
	tmp = 0;
	while (tmp < len && s[start])
		substr[tmp++] = s[start++];
	substr[tmp] = '\0';
	return (substr);
}

/*
int main()
{
	char	str[] = "i just want this part #############";
	char	*substr;

	substr = ft_substr(str, 5, 10);
	printf("%s", substr);
	free(substr);
	return (0);
}
*/
