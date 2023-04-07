/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 19:06:37 by geraudtsers       #+#    #+#             */
/*   Updated: 2022/12/07 12:46:46 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*elem;

	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	elem = lst;
	return (elem);
}

/*
int main()
{
	int			i;
	t_list		*elem;
	t_list		*elem2;
	t_list		*elem3;
	t_list		*elem4;
	t_list		*val;
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

	val = ft_lstlast(elem);
	content = val->content;
	i = 0;
	while(content[i])
		write(1, &(content[i++]), 1);
	write(1, "\n", 1);
	elem->next = NULL;
	val = ft_lstlast(elem);
	content = val->content;
	i = 0;
	while (content[i])
		write(1, &(content[i++]), 1);
	write(1, "\n", 1);
	elem = NULL;
	val = ft_lstlast(elem);
	if (val == NULL)
		write(1, "NULL", 4);
	write(1, "\n", 1);
	return (0);
}
*/
