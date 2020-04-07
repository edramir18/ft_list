/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edramire <edramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 00:37:10 by edramire          #+#    #+#             */
/*   Updated: 2020/04/08 00:58:18 by edramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

void	ft_lstdel_front(t_list **list, void del(void *))
{
	t_list	*node;

	if (list == NULL || *list == NULL)
		return ;
	node = *list;
	*list = (*list)->next;
	ft_lstdelone(node, del);
}

void	ft_lstdel_one(t_list **list, void *data, int cmp(void *, void*), 
						void del(void *))
{
	t_list	*node;
	t_list	*prev;

	prev = NULL;
	if (list == NULL || *list == NULL)
		return ;
	node = *list;
	while (node != NULL)
	{
		if (cmp(data, node->content) == 0)
		{
			if (prev == NULL)
				*list = node->next;
			else
				prev->next = node->next;
			ft_lstdelone(node, del);
			break;
		}
		prev = node;
		node = node->next;
	}
}

int		main(void)
{
	t_list	*list;

	list = NULL;

}