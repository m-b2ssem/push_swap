/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmahdi <bmahdi@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:20:59 by bmahdi            #+#    #+#             */
/*   Updated: 2023/11/29 00:16:39 by bmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin1(char *buffer, char *current_line)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*joining;

	if (!buffer)
	{
		buffer = (char *)malloc(1 * sizeof(char));
		buffer[0] = '\0';
	}
	if (!buffer || !current_line)
		return (NULL);
	s1_len = ft_strlen(buffer);
	s2_len = ft_strlen(current_line);
	joining = (char *)malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!joining)
		return (NULL);
	joining = ft_join(joining, buffer, current_line);
	free(buffer);
	return (joining);
}

char	*ft_strchr1(char *s, int c)
{
	const char	*ptr;

	if (!s)
	{
		return (NULL);
	}
	ptr = s;
	if (c == 0)
	{
		return ((char *)ptr);
	}
	while (*ptr)
	{
		if (*ptr == (char)c)
		{
			return ((char *)ptr);
		}
		ptr++;
	}
	return (NULL);
}

size_t	ft_strlen(const char *str)
{
	const char	*i;

	i = str;
	while (*str)
		str++;
	return (str - i);
}

char	*ft_join(char *dest, char *buffer, char *current_line)
{
	size_t	i;
	size_t	n;

	i = 0;
	while (buffer && buffer[i])
	{
		dest[i] = buffer[i];
		i++;
	}
	n = 0;
	while (current_line && current_line[n])
	{
		dest[i + n] = current_line[n];
		n++;
	}
	dest[n + i] = '\0';
	return (dest);
}

char	*handle_read_error(char **current_line, char **buffer)
{
	free(*current_line);
	free(*buffer);
	*buffer = NULL;
	return (NULL);
}
