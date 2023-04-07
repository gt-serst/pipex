/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geraudtserstevens <geraudtserstevens@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 18:24:30 by geraudtsers       #+#    #+#             */
/*   Updated: 2022/12/01 10:33:15 by geraudtsers      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	tmp;
	char			*str;

	if (!s || !f)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!str)
		return (NULL);
	tmp = 0;
	while (s[tmp] != '\0')
	{
		str[tmp] = f(tmp, s[tmp]);
		tmp++;
	}
	str[tmp] = '\0';
	return (str);
}
