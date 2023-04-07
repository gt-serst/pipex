/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:48:12 by geraudtsers       #+#    #+#             */
/*   Updated: 2022/12/07 12:46:46 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
static void	ft_del(void	*content)
{
	free(content);
}

static void *map_length(void *s)
{
	char *str = malloc(10);
	if (str != NULL)
		sprintf(str, "__%lX", strlen((char *)s));
	return str;
}
*/

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*current;
	t_list	*new;

	if (!lst || !f || !del)
		return (NULL);
	new = NULL;
	while (lst)
	{
		current = ft_lstnew((*f)(lst->content));
		if (!current)
		{
			ft_lstclear(&new, del);
			return (NULL);
		}
		ft_lstadd_back(&new, current);
		lst = lst->next;
	}
	return (new);
}

/*
int main()
{
	t_list		*elem;
	t_list		*elem2;
	t_list		*elem3;
	t_list		*elem4;
	t_list		*list;
	char		*str = strdup("hello !");
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

	list = ft_lstmap(elem, &map_length, &ft_del);
	while (list)
	{
		content = list->content;
		printf("%s\n", content);
		list = list->next;
	}
	return (0);
}
*/
