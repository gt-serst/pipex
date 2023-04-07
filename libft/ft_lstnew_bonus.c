/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 16:29:37 by geraudtsers       #+#    #+#             */
/*   Updated: 2022/12/08 15:36:14 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*elem;

	elem = malloc(sizeof(t_list));
	if (!elem)
		return (NULL);
	elem->content = content;
	elem->next = NULL;
	return (elem);
}

/*
int main()
{
	t_list	*elem;
	//char	str [] = "lorem ipsum dolor sit";
	char	*content;

	elem = ft_lstnew(NULL);
	if (!(elem->content))
		printf("NULL");
	else
	{
		content = elem->content;
		printf("%s", content);
	}
	return (0);
}
*/
