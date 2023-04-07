/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:11:25 by gt-serst          #+#    #+#             */
/*   Updated: 2022/12/07 12:46:46 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
static void	ft_del(void	*content)
{
	free(content);
}
*/

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
	lst = NULL;
}

/*
int main()
{
	t_list	*lst;
	t_list	*new;

	lst = NULL;
	new = NULL;
	lst = ft_lstnew("Hello");
	new = ft_lstnew("toto");
	ft_lstadd_front(&lst, new);
	printf("%d\n", ft_lstsize(new));
	ft_lstdelone(new, &ft_delete);
	while (lst)
	{
		printf("%s\n", lst->content);
		lst = lst->next;
	}
	return (0);
}
*/
