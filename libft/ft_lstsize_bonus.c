/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 18:53:04 by geraudtsers       #+#    #+#             */
/*   Updated: 2022/12/07 12:46:46 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	size;

	if (!lst)
		return (0);
	size = 0;
	while (lst)
	{
		lst = lst->next;
		size++;
	}
	return (size);
}

/*
int main()
{
	t_list	*lst;

	lst = NULL;
	printf("%d\n", ft_lstsize(lst));
	return (0);
}
*/
