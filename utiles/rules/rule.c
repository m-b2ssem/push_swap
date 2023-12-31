/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmahdi <bmahdi@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 19:02:21 by bmahdi            #+#    #+#             */
/*   Updated: 2023/11/29 00:31:20 by bmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rule.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (*s1 && *s2 && *(unsigned char *)s1 == *(unsigned char *)s2 && n > 0)
	{
		s1++;
		s2++;
		n--;
	}
	if (n == 0)
		return (0);
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

void	ft_rule(t_stack *a, t_stack *b, char *str)
{
	if (!ft_strncmp(str, "ra\n", ft_strlen(str)))
		ra(a);
	else if (!ft_strncmp(str, "rb\n", ft_strlen(str)))
		rb(b);
	else if (!ft_strncmp(str, "rr\n", ft_strlen(str)))
		rr(a, b);
	else if (!ft_strncmp(str, "rrr\n", ft_strlen(str)))
		rrr(a, b);
	else if (!ft_strncmp(str, "rra\n", ft_strlen(str)))
		rra(a);
	else if (!ft_strncmp(str, "rrb\n", ft_strlen(str)))
		rrb(b);
	else if (!ft_strncmp(str, "pa\n", ft_strlen(str)))
		pa(a, b);
	else if (!ft_strncmp(str, "pb\n", ft_strlen(str)))
		pb(a, b);
	else if (!ft_strncmp(str, "ss\n", ft_strlen(str)))
		ss(a, b);
	else if (!ft_strncmp(str, "sa\n", ft_strlen(str)))
		sa(a);
	else if (!ft_strncmp(str, "sb\n", ft_strlen(str)))
		sb(b);
	ft_putstr_fd(str, 1);
}
