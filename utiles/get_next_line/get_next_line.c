/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmahdi <bmahdi@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:21:09 by bmahdi            #+#    #+#             */
/*   Updated: 2023/10/30 15:21:09 by bmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_line(char *buffer)
{
	size_t	i;
	char	*line;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	i += (buffer[i] == '\n');
	line = (char *)malloc(i + 1 * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_error(char **current_line)
{
	free(*current_line);
	return (NULL);
}

char	*new_start(char *buffer)
{
	size_t	i;
	size_t	n;
	char	*new_buffer;

	if (!buffer)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	i += (buffer[i] == '\n');
	new_buffer = (char *)malloc(1 + ft_strlen(buffer) - i);
	if (!new_buffer)
		return (NULL);
	n = 0;
	while (buffer[i + n])
	{
		new_buffer[n] = buffer[i + n];
		n++;
	}
	free(buffer);
	new_buffer[n] = '\0';
	if (!ft_strlen(new_buffer))
		return (ft_error(&new_buffer));
	return (new_buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*current_line;
	int			read_num;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	current_line = (char *)malloc(1 + BUFFER_SIZE * sizeof(char));
	if (!current_line)
		return (NULL);
	read_num = 1;
	while (!(ft_strchr1(buffer, '\n')) && read_num != 0)
	{
		read_num = read(fd, current_line, BUFFER_SIZE);
		if (read_num == -1)
			return (handle_read_error(&current_line, &buffer));
		current_line[read_num] = '\0';
		buffer = ft_strjoin1(buffer, current_line);
	}
	free(current_line);
	current_line = ft_read_line(buffer);
	buffer = new_start(buffer);
	return (current_line);
}

/* int	main(void)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open("test.txt", O_RDONLY);
	while (i < 3)
	{
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
		i++;
	}

	return (0);
} */
