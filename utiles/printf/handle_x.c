/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmahdi <bmahdi@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 17:37:29 by bmahdi            #+#    #+#             */
/*   Updated: 2023/09/27 17:37:29 by bmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_x(unsigned int n, int uppercase, size_t *co)
{
	char	buffer[9];
	int		i;
	int		remainder;

	i = 0;
	if (n == 0)
	{
		handle_c('0', co);
	}
	while (n > 0)
	{
		remainder = n % 16;
		if (remainder < 10)
			buffer[i++] = '0' + remainder;
		else if (uppercase)
			buffer[i++] = 'A' + (remainder - 10);
		else
			buffer[i++] = 'a' + (remainder - 10);
		n /= 16;
	}
	while (--i >= 0)
		handle_c(buffer[i], co);
	return (*co);
}
