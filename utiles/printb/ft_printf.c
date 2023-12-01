/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmahdi <bmahdi@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 11:27:00 by bmahdi            #+#    #+#             */
/*   Updated: 2023/09/26 23:28:32 by bmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_after_precent(va_list args, char *format, size_t *co)
{
	if (*format == 'c')
		handle_c(va_arg(args, int), co);
	else if (*format == 's')
		handle_s(va_arg(args, char *), co);
	else if (*format == 'p')
		handle_p(va_arg(args, void *), co);
	else if (*format == 'd')
		handle_d(va_arg(args, int), co);
	else if (*format == 'i')
		handle_d(va_arg(args, int), co);
	else if (*format == 'u')
		handle_u(va_arg(args, unsigned int), co);
	else if (*format == 'x')
		handle_x(va_arg(args, unsigned int), 0, co);
	else if (*format == 'X')
		handle_x(va_arg(args, unsigned int), 1, co);
	else if (*format == '%')
		handle_c(*format, co);
}

int	ft_printf(const char *format, ...)
{
	va_list		args;
	size_t		co;

	if (!*format)
		return (0);
	co = 0;
	va_start (args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			ft_after_precent(args, (char *)format, &co);
		}
		else
		{
			handle_c(*format, &co);
		}
		format++;
	}
	va_end (args);
	return (co);
}
