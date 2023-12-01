/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utile.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmahdi <bmahdi@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 20:40:19 by bmahdi            #+#    #+#             */
/*   Updated: 2023/11/29 00:28:50 by bmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILE_H

# define FT_UTILE_H

# include <stdlib.h>
# include <stdio.h>
# include "./printf/ft_printf.h"
# include "./libft/libft.h"
# include "./rules/ft_rule.h"
# include "./get_next_line/get_next_line.h"

void	ft_erour(void);
int		ft_check_arg(char **av, int ac, int **arry);
int		*fill_arry(char **av, int size, int **arry);
void	fill_stack(int *arry, int size, t_stack *a, t_stack *b);
int		sorting_arry(t_stack a, int **arry, int size);
void	sorting_stack(t_stack *a, t_stack *b, int *arry, int size);

#endif