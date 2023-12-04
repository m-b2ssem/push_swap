/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_Erour.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmahdi <bmahdi@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 22:30:52 by bmahdi            #+#    #+#             */
/*   Updated: 2023/11/29 00:29:44 by bmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utile.h"

void	ft_erour(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void	free_memory(t_stack *a, t_stack *b, int *arry)
{
	if (a->arry)
		free(a->arry);
	if (b->arry)
		free(b->arry);
	if (arry)
		free(arry);
}
