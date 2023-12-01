/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmahdi <bmahdi@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 11:17:32 by bmahdi            #+#    #+#             */
/*   Updated: 2023/09/26 11:17:32 by bmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_s(char *s, size_t *co)
{
	if (s == NULL)
	{
		s = "(null)";
	}
	while (*s)
	{
		handle_c(*s, co);
		s++;
	}
}

void	handle_c(char s, size_t *co)
{
	write (1, &s, 1);
	(*co)++;
}
