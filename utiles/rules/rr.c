/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmahdi <bmahdi@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 22:32:09 by bmahdi            #+#    #+#             */
/*   Updated: 2023/11/29 00:32:25 by bmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rule.h"

void	ra(t_stack *a)
{
	int	tmp;
	int	*top;

	tmp = *a->top;
	top = a->top;
	while (top <= a->end)
	{
		if (top == a->end)
			*a->end = tmp;
		else
			*top = *(top + 1);
		top++;
	}
}

void	rb(t_stack *b)
{
	int	tmp;
	int	*top;

	tmp = *b->top;
	top = b->top;
	while (top <= b->end)
	{
		if (top == b->end)
			*b->end = tmp;
		else
			*top = *(top + 1);
		top++;
	}
}

void	rr(t_stack *a, t_stack *b)
{
	rb(b);
	ra(a);
}
