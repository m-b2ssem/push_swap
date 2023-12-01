/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_arry.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmahdi <bmahdi@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 10:10:24 by bmahdi            #+#    #+#             */
/*   Updated: 2023/11/29 00:30:19 by bmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_utile.h"

static int	ft_check_double(int *arry, int i, int num)
{
	if (!arry)
		return (0);
	while (i--)
		if (num == arry[i])
			return (0);
	return (1);
}

static int	ft_split_arg(int *arry, int *i, char **av)
{
	long int	tmp;
	char		**ptr;
	char		*str;

	ptr = av;
	while (*av)
	{
		str = *av;
		tmp = ft_atoi(*av++);
		if (tmp > INT_MAX || tmp < INT_MIN || !ft_check_double(arry, *i, tmp))
			ft_erour();
		arry[(*i)++] = (int)tmp;
		free(str);
	}
	free(ptr);
	return (*i);
}

int	*fill_arry(char **av, int size, int **arry)
{
	int		i;

	if (!av)
		return (NULL);
	*arry = ft_calloc(size, sizeof(int));
	i = 0;
	if (!arry)
		return (NULL);
	while (i < size)
	{
		ft_split_arg(*arry, &i, ft_split(*av++, ' '));
	}
	return (*arry);
}
