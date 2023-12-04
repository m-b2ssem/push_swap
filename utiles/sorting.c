/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmahdi <bmahdi@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 16:22:42 by bmahdi            #+#    #+#             */
/*   Updated: 2023/12/04 23:29:01 by bmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utile.h"

int	sorting_arry(t_stack a, int **arr, int size)
{
	int	i;
	int	j;
	int	*arry;

	i = 0;
	arry = *arr;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (arry[i] > arry[j])
				ft_swap(&arry[i], &arry[j]);
			j++;
		}
		i++;
	}
	if (!ft_memcmp(a.arry, arry, size * sizeof(int)))
		return (1);
	return (0);
}
