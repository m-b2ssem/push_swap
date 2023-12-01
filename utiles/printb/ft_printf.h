/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmahdi <bmahdi@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 12:12:47 by bmahdi            #+#    #+#             */
/*   Updated: 2023/09/28 12:12:47 by bmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>

int			ft_printf(const char *format, ...);
void		ft_after_precent(va_list args, char *format, size_t *co);
void		handle_c(char s, size_t *co);
void		handle_s(char *s, size_t *co);
void		handle_p(void *ptr, size_t *co);
void		handle_d(int d, size_t *co);
int			handle_u(unsigned int n, size_t *co);
int			handle_x(unsigned int n, int uppercase, size_t *co);

#endif
