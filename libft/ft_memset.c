/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 11:10:14 by geraudtsers       #+#    #+#             */
/*   Updated: 2022/12/05 17:00:05 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			tmp;
	unsigned char	*str;
	unsigned char	chr;

	tmp = 0;
	str = (unsigned char *)b;
	chr = (unsigned char)c;
	while (tmp < len)
	{
		str[tmp] = chr;
		tmp++;
	}
	return (b);
}

/*
int	main()
{
	char	str[50] = "GeeksForGeeks is for programming geeks.";

	ft_memset(str + 12, '.', 8*sizeof(char));
	printf("%s\n", str);
	memset(str + 12, '.', 8*sizeof(char));
	printf("%s", str);
	return (0);
}
*/
