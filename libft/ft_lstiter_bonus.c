/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 12:32:36 by geraudtsers       #+#    #+#             */
/*   Updated: 2022/12/07 12:46:46 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
void	ft_modify_list_with_d(void *elem)
{
	int		len;
	char		*content;

	len = 0;
	content = (char *)elem;
	while (content[len])
	{
		content[len++] = 'd';
	}
}
*/

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		(*f)(lst->content);
		lst = lst->next;
	}
}

/*
int main()
{
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

	elem->next = elem2;
	elem2->next = elem3;
	elem3->next = elem4;

	ft_lstiter(elem, &ft_modify_list_with_d);
	while (elem)
	{
		content = elem->content;
		printf("%s\n", content);
		elem = elem->next;
	}
	return (0);
}
*/
