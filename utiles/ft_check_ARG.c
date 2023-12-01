/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_ARG.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmahdi <bmahdi@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 23:24:10 by bmahdi            #+#    #+#             */
/*   Updated: 2023/11/29 00:29:58 by bmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utile.h"

static int	ft_is_valid(char *arg)
{
	char	*ptr;

	ptr = arg;
	if (!arg)
		return (0);
	if (ft_strlen(arg) >= 12)
		ft_erour();
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
	free(ptr);
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
			ft_erour();
		i++;
	}
	free (ptr);
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
