/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaoussi <vnaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 23:01:06 by vnaoussi          #+#    #+#             */
/*   Updated: 2025/11/29 20:59:33 by vnaoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

static char	*ft_strdup_trim(char *content_buffer, char *rest)
{
	char	*line;
	size_t	len;
	int		i;

	i = 0;
	len = get_len_line(content_buffer) + get_len_line(rest);
	i = 0;
	line = (char *)malloc(sizeof(char) * (len + 1));
	if (!line || !content_buffer)
		return (NULL);
	len = ft_strncat_l(line, rest, len + 1);
	while (content_buffer[i] != '\n' && content_buffer[i++])
		line[len + i - 1] = content_buffer[i - 1];
	if (content_buffer[i] == '\n')
		line[len + i++] = '\n';
	rest[0] = '\0';
	ft_strncat_l(rest, content_buffer + i, BUFFER_SIZE);
	free(content_buffer);
	return (line);
}

char    *get_next_line(int fd)
{
	char	*content_buffer;
	static char	rest[BUFFER_SIZE];
	size_t	size;

	content_buffer = (char *)malloc(sizeof(char));
	if (!content_buffer || fd < 0)
		return (NULL);
	size = 0;
	content_buffer[0] = '\0';
	if (!read_and_save(fd, &content_buffer, &size))
		return (NULL);
	content_buffer = ft_strdup_trim(content_buffer, rest);
	return (content_buffer);
}
