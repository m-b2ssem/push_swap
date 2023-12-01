/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmahdi <bmahdi@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 21:12:34 by bmahdi            #+#    #+#             */
/*   Updated: 2023/11/29 00:31:51 by bmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rule.h"

void	rra(t_stack *a)
{
	int	tmp;
	int	*end;
	
	if (a->end < a->top)
		return ;
	tmp = *a->end;
	end = a->end;
	while (end >= a->top)
	{
		if (end == a->top)
			*a->top = tmp;
		else
			*end = *(end - 1);
		end--;
	}
}

void	rrb(t_stack *b)
{
	int	tmp;
	int	*end;

	if (b->end < b->top)
		return ;
	tmp = *b->end;
	end = b->end;
	while (end >= b->top)
	{
		if (end == b->top)
			*b->top = tmp;
		else
			*end = *(end - 1);
		end--;
	}
}

void	rrr(t_stack *a, t_stack *b)
{
	rra(a);
	rrb(b);
}
