/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterar.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edramire <edramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/03 20:52:23 by edramire          #+#    #+#             */
/*   Updated: 2020/04/04 00:11:06 by edramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdio.h>

void	*ft_pow_number(void *data)
{
	int		nb;
	void	*pw;

	nb = *((int *) data);
	pw = malloc(sizeof(long));
	if (pw == NULL)
		return (NULL);
	*((long int *)pw) = nb * nb;
	return (pw);
}

void	ft_print_int(void *data)
{
	int		nb;

	nb = *(int *)data;
	printf("%2d ", nb);
}

void	ft_print_long(void *data)
{
	long int		nb;

	nb = *(long int *)data;
	printf("%2ld ", nb);
}

t_list	*ft_generate_list(int max)
{
	t_list	*list;
	t_list	*node;
	int		*number;
	
	list = NULL;
	while (max > 0)
	{
		number = malloc(sizeof(int));
		node = number == NULL ? NULL : ft_lstnew(number); 
		if (number == NULL || node == NULL)
		{
			ft_lstclear(&list, free);
			return (NULL);
		}
		*number = rand() % 10;
		ft_lstadd_front(&list, node);
		--max;
	}
	return list;
}

int		main(void)
{
	t_list		*list;
	t_list		*listnew;

	list = ft_generate_list(10);
	if (list == NULL)
		return (EXIT_FAILURE);
	listnew = ft_lstmap(list, ft_pow_number, free);
	if (listnew != NULL)
	{
		printf("La lista original contiene %d elementos.\n", ft_lstsize(list));
		ft_lstiter(list, ft_print_int);
		printf("\nLa nueva lista contiene %d elementos.\n", ft_lstsize(listnew));
		ft_lstiter(listnew, ft_print_long);
		printf("\n");
	}
	ft_lstclear(&list, free);
	ft_lstclear(&listnew, free);
	return (0);
}