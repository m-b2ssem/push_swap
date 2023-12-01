/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmahdi <bmahdi@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 00:10:56 by bmahdi            #+#    #+#             */
/*   Updated: 2023/11/29 00:33:50 by bmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rule.h"

void	pa(t_stack *a, t_stack *b)
{
	*(--a->top) = *(b->top++);
	*(b->top - 1) = 0;
}