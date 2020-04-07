/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operadores.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edramire <edramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 10:56:40 by edramire          #+#    #+#             */
/*   Updated: 2020/04/07 11:19:36 by edramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_sum_int(int a, int b)
{
	return (a + b);
}

int		ft_sub_int(int a, int b)
{
	return (a - b);
}

int		ft_mult_int(int a, int b)
{
	return (a * b);
}

void	ft_print_result(int a, int b, int (*op)(int, int))
{
	printf("Operadores: %d %d, Resultado: %d\n", a, b, op(a, b));
}

int		main(void)
{
	ft_print_result(5, 4, ft_sum_int);
	ft_print_result(5, 4, ft_sub_int);
	ft_print_result(5, 4, ft_mult_int);
}