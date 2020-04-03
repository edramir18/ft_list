/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edramire <edramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/03 12:33:36 by edramire          #+#    #+#             */
/*   Updated: 2020/04/03 13:01:41 by edramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdio.h>

typedef	struct	s_user
{
	char	*first_name;
	char	*last_name;
}				t_user;

void	ft_delete_user(void *data)
{
	t_user	*user;

	user = (t_user *)data; 
	free(user->first_name);
	free(user->last_name);
	free(user);
}

int		main(void)
{
	t_list	*list;
	t_list	*node;
	t_user	*user;

	list = NULL;
	user = malloc(sizeof(t_user));
	if (user == NULL)
		return (EXIT_FAILURE);
	user->first_name = ft_strdup("Eduardo");
	user->last_name = ft_strdup("Ramirez");
	node = ft_lstnew(user);
	if (node == NULL)
	{
		ft_delete_user(user);
		free(user);
		return (EXIT_FAILURE);
	}
	ft_lstadd_front(&list, node);
	printf("%s %s\n", ((t_user *)list->content)->first_name,
		((t_user *)list->content)->last_name);
	ft_lstclear(&list, ft_delete_user);
	return (0);
}