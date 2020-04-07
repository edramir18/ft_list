/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edramire <edramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 11:56:34 by edramire          #+#    #+#             */
/*   Updated: 2020/04/07 13:06:17 by edramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <unistd.h>
#include <time.h>

int		ft_cmp_int(void *a, void *b)
{
	int xa;
	int xb;

	xa = *(int *)a;
	xb = *(int *)b;
	if (xa > xb)
		return (1);
	else if (xa < xb)
		return (-1);
	return (0);
}

int		ft_cmp_long(void *a, void *b)
{
	long int xa;
	long int xb;

	xa = *(int *)a;
	xb = *(int *)b;
	if (xa > xb)
		return (1);
	else if (xa < xb)
		return (-1);
	return (0);
}

void	ft_swap(void *a, void *b, size_t bytes)
{
	void	*tmp;

	tmp = malloc(bytes);
	if (tmp == NULL)
		return ;
	memcpy(tmp, a, bytes);
	memcpy(a, b, bytes);
	memcpy(b, tmp, bytes);
	free(tmp);
}

void	ft_sort(int n, void *arr, int cmp(void *, void *), size_t bytes)
{
	int change;
	int i;
	int j;

	i = 0;
	change = 1;
	while (i < (n - 1) && change == 1)
	{
		j = i + 1;
		change = 0;
		while (j < n)
		{
			if (cmp(arr + i * bytes, arr + j * bytes) > 0)
			{
				ft_swap(arr + i * bytes, arr + j * bytes, bytes);
				change = 1;
			}
			++j;
		}
		++i;
	}
}

void	ft_print_int(int n, int *arr)
{
	int i;

	i = 0;
	while (i < n)
		printf("%2d ", arr[i++]);
	printf("\n");
}

void	ft_print_long(int n, long int *arr)
{
	int i;

	i = 0;
	while (i < n)
		printf("%2ld ", arr[i++]);
	printf("\n");
}

void	*ft_create_arr(int n, size_t size)
{
	void		*arr;
	int			i;
	long int	r;

	arr = malloc(n * size);
	if (arr == NULL)
		return (NULL);
	bzero(arr, n * size);
	i = 0;
	while (i < n)
	{
		r = rand() % 100;
		memcpy(arr + i * size, &r, size);
		++i;
	}
	return (arr);
}

int		main(void)
{
	int			n;
	int			*arr_int;
	long int	*arr_long;

	srand(time(NULL));
	n = 20;
	arr_int = ft_create_arr(n, sizeof(int));
	arr_long = ft_create_arr(n, sizeof(long int));
	if (arr_int == NULL || arr_long == NULL)
	{
		free(arr_long);
		free(arr_int);
		return (EXIT_FAILURE);
	}
	printf("Arreglos originales: \n");
	ft_print_int(n, arr_int);
	ft_print_long(n, arr_long);
	ft_sort(n, arr_int, ft_cmp_int, sizeof(int));
	ft_sort(n, arr_long, ft_cmp_long, sizeof(long int));
	printf("Arreglos ordenados: \n");
	ft_print_int(n, arr_int);
	ft_print_long(n, arr_long);
	return (0);
}