/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 13:27:31 by gt-serst          #+#    #+#             */
/*   Updated: 2022/12/05 18:26:58 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_chars(long nb)
{
	int	c;

	c = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		nb = nb * (-1);
		c++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		c++;
	}
	return (c);
}

static char	*ft_numbers(long nb, int m)
{
	char	*str;

	str = malloc(sizeof(char) * (m + 1));
	if (!str)
		return (NULL);
	str[m--] = '\0';
	if (nb == 0)
	{
		str[0] = 0 + 48;
		return (str);
	}
	if (nb < 0)
	{
		str[0] = '-';
		nb = nb * (-1);
	}
	while (nb > 0)
	{
		str[m] = 48 + (nb % 10);
		nb = nb / 10;
		m--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	int		m;
	long	nb;

	nb = n;
	m = ft_count_chars(nb);
	return (ft_numbers(nb, m));
}

/*
int main()
{
	char	*str;

	str = ft_itoa(0);
	printf("%s\n", str);
	free(str);
	return (0);
}
*/
