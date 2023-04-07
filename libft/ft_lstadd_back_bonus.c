/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:46:07 by gt-serst          #+#    #+#             */
/*   Updated: 2022/12/07 12:46:46 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*elem;

	if (!lst || !new)
		return ;
	if (*lst)
	{
		elem = ft_lstlast(*lst);
		elem->next = &*new;
	}
	else
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
	char		*str = strdup("");
	char		*str2 = strdup("");
	char		*str3 = strdup("");
	char		*str4 = strdup("");
	char		*content;

	elem = ft_lstnew(str);
	elem2 = ft_lstnew(str2);
	elem3 = ft_lstnew(str3);
	elem4 = ft_lstnew(str4);

	begin = NULL;
	ft_lstadd_back(&begin, elem);
	ft_lstadd_back(&begin, elem2);
	ft_lstadd_back(&begin, elem3);
	ft_lstadd_back(&begin, elem4);
	while (begin)
	{
		content = begin->content;
		printf("%s\n", content);
		begin = begin->next;
	}
	return (0);
}
*/
