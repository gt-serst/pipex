/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 11:19:45 by gt-serst          #+#    #+#             */
/*   Updated: 2022/12/08 15:36:46 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	int	*ptr;

	ptr = malloc(size * count);
	if (!ptr)
		return (NULL);
	ptr = ft_memset(ptr, 0, size * count);
	return (ptr);
}

/*
int main()
{
    int n;
    int *ptr;

    n = 10;
    ptr = ft_calloc(n, sizeof(int));
    ptr = calloc(n, sizeof(int));
    free(ptr);
    return (0);
}
*/
