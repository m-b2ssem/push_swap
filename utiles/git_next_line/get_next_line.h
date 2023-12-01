/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmahdi <bmahdi@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 09:40:25 by bmahdi            #+#    #+#             */
/*   Updated: 2023/11/29 00:17:26 by bmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

char	*ft_join(char *dest, char *current_line, char *buffer);
size_t	ft_strlen(const char *str);
size_t	ft_strlen(const char *str);
char	*ft_strjoin1(char *buffer, char *current_line);
char	*ft_strchr1(char *s, int c);
char	*ft_read_line(char *buffer);
char	*new_start(char *buffer);
char	*get_next_line(int fd);
char	*handle_read_error(char **current_line, char **buffer);
char	*ft_error(char **current_line);

#endif