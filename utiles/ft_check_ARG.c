/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_ARG.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmahdi <bmahdi@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 23:24:10 by bmahdi            #+#    #+#             */
/*   Updated: 2023/12/03 01:00:32 by bmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utile.h"

void free_strings(char **ptr)
{
    char **temp = ptr;
    while (*temp)
    {
        free(*temp);
        temp++;
    }
    free(ptr);
}

int	ft_is_valid(char *arg)
{
	if (!arg)
		return (0);
	if (ft_strlen(arg) >= 12)
		return (0);
	if (((*arg == '-' || *arg == '+') && ft_isdigit(*(arg + 1))) || \
			ft_isdigit(*arg))
		arg++;
	else
		return (0);
	while (*arg)
	{
		if (!ft_isdigit(*arg))
			return (0);
		arg++;
	}
	return (1);
}

static int	check_arg(char **av)
{
	int		i;
	char	**ptr;

	i = 0;
	ptr = av;
	if (!av)
		return (0);
	while (*av)
	{
		if (!ft_is_valid(*av++))
		{
			free_strings(ptr);
			ft_erour();
		}
		i++;
	}
	free_strings(ptr);
	return (i);
}

int	ft_check_arg(char **av, int ac, int **arry)
{
	int	size;
	int	i;

	i = 0;
	size = 0;
	while (ac-- > 1)
	{
		i = check_arg(ft_split(av[ac], ' '));
		if (i)
			size += i;
		else
			ft_erour();
	}
	if (size > 1)
		fill_arry(++av, size, arry);
	else
		return (0);
	return (size);
}
