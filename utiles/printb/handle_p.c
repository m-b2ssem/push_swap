/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmahdi <bmahdi@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 22:56:17 by bmahdi            #+#    #+#             */
/*   Updated: 2023/09/27 23:44:52 by bmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_adress(size_t ptr, size_t *co)
{
	if (ptr > 15)
	{
		print_adress(ptr / 16, co);
	}
	ptr = ptr % 16;
	if (ptr <= 9)
	{
		ptr = ptr + '0';
		handle_c(ptr, co);
	}
	else
	{
		ptr = ptr + 'a' - 10;
		handle_c(ptr, co);
	}
}

void	handle_p(void *ptr, size_t *co)
{
	size_t	ptr_ptr;

	if (ptr == 0)
	{
		handle_s("0x0", co);
		return ;
	}
	ptr_ptr = (size_t)ptr;
	handle_s("0x", co);
	print_adress(ptr_ptr, co);
}
