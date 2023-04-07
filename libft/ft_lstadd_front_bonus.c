/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 17:11:31 by geraudtsers       #+#    #+#             */
/*   Updated: 2022/12/07 12:46:46 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_empty(t_list **lst)
{
	if (lst == NULL)
		return (1);
	return (0);
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	if (ft_is_empty(lst))
		new->next = NULL;
	new->next = *lst;
	*lst = new;
}

/*
int main()
{
	t_list		*begin;
	t_list		*elem;
	t_list		*elem2;
	t_list		*elem3;
	t_list		*elem4;
	char		*str = strdup("lorem");
	char		*str2 = strdup("ipsum");
	char		*str3 = strdup("dolor");
	char		*str4 = strdup("sit");
	char		*content;


	elem = ft_lstnew(str);
	elem2 = ft_lstnew(str2);
	elem3 = ft_lstnew(str3);
	elem4 = ft_lstnew(str4);

	begin = NULL;
	ft_lstadd_front(&begin, elem4);
	ft_lstadd_front(&begin, elem3);
	ft_lstadd_front(&begin, elem2);
	ft_lstadd_front(&begin, elem);
	while (begin)
	{
		content = begin->content;
		printf("%s\n", content);
		begin = begin->next;
	}
	return (0);
}
*/
