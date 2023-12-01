/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmahdi <bmahdi@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 21:50:34 by bmahdi            #+#    #+#             */
/*   Updated: 2023/11/29 00:29:14 by bmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utile.h"

void	fill_stack(int *arry, int size, t_stack *a, t_stack *b)
{
	if (!arry)
		return ;
	a->arry = ft_calloc(sizeof(int), size);
	b->arry = ft_calloc(sizeof(int), size);
	if (!a->arry || !b->arry)
		return ;
	a->top = a->arry;
	a->end = a->arry + (size - 1);
	b->end = b->arry + (size - 1);
	b->top = b->end + 1;
	a->size = size;
	b->size = size;
	ft_memmove(a->arry, arry, size * sizeof(int));
}
