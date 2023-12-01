/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmahdi <bmahdi@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 14:25:05 by bmahdi            #+#    #+#             */
/*   Updated: 2023/11/29 00:31:03 by bmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rule.h"

void	sa(t_stack *a)
{
	if (a->top == a->end)
		return ;
	ft_swap(a->top, a->top + 1);
}

void	sb(t_stack *b)
{
	if (b->top == b->end)
		return ;
	ft_swap(b->top, b->top + 1);
}

void	ss(t_stack *a, t_stack *b)
{
	sa(a);
	sb(b);
}
