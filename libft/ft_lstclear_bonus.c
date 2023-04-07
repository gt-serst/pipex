/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 14:55:10 by geraudtsers       #+#    #+#             */
/*   Updated: 2022/12/07 12:46:46 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
static int	nb_free_done;

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
	lst = NULL;
}

static void	ft_del(void	*content)
{
	printf("deleted content :%s\n", content);
	free(content);
	nb_free_done++;
}
*/

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*next;

	if (!lst || !del)
		return ;
	current = *lst;
	while (current != NULL)
	{
		next = current->next;
		ft_lstdelone(current, del);
		current = next;
	}
	*lst = NULL;
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

	nb_free_done = 0;
	ft_lstclear(&elem3, &ft_del);
	if (elem)
	{
		content = elem->content;
		printf("%s", content);
	}
	else
		write(1, "NULL", 4);
	write(1, "\n", 1);
	if (elem2)
	{
		content = elem2->content;
		printf("%s", content);
	}
	else
		write(1, "NULL", 4);
	write(1, "\n", 1);
	if (elem3)
	{
		content = elem3->content;
		printf("%s", content);
	}
	else
		write(1, "NULL", 4);
	write(1, "\n", 1);
	if (elem4)
	{
		write(1, "nb_free_done = ", 15);
		nb_free_done += '0';
		write(1, &nb_free_done, 1);
	}
	else
		write(1, "NULL", 4);
	return (0);
}
*/
