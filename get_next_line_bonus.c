/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaoussi <vnaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 23:01:06 by vnaoussi          #+#    #+#             */
/*   Updated: 2025/12/04 23:58:06 by vnaoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"

static void	ft_move(char *rest, int size)
{
	int	i;

	i = size;
	while (i < BUFFER_SIZE)
	{
		rest[i - size] = rest[i];
		i++;
	}
	while (i <= BUFFER_SIZE)
		rest[i++] = '\0';
}

static char	*ft_strdup_trim(char *content_b, char *rest)
{
	char	*line;
	size_t	len;
	int		i;

	if (!content_b || !rest)
		return (NULL);
	len = get_len_line(content_b);
	line = (char *)malloc(sizeof(char) * (len + 1));
	if (!line)
		return (NULL);
	line[0] = '\0';
	i = ft_strncat_l(line, content_b, len, '\n');
	rest[0] = '\0';
	ft_strncat_l(rest, content_b + i, BUFFER_SIZE, '\0');
	free(content_b);
	return (line);
}

static char *iscmplonrest(char *rest, size_t *size_c)
{
	int		size;
	char	*content;

	size = get_len_line(rest);
	content = NULL;
	if (size > 0 && rest[size - 1] == '\n')
	{
		content = init_fread(rest, NULL, size, '\n');
		ft_move(rest, size);
	}
	*size_c = size;
	return (content);
}

char    *get_next_line(int fd)
{
	char	*content_b;
	static char	rest[OPEN_MAX][BUFFER_SIZE + 1];
	size_t	size;

	if (fd < 0)
		return (NULL);
	content_b = iscmplonrest(rest[fd], &size);
	if (content_b)
		return (content_b);
	content_b = (char *)malloc(sizeof(char) * (size + 1));
	if (!content_b)
		return (NULL);
	content_b[0] = '\0';
	size = ft_strncat_l(content_b, rest[fd], size, '\0');
	if (!read_and_save(fd, &content_b, &size))
	{
		rest[fd][0] = '\0';
		return (ft_free(content_b), NULL);
	}
	if (!content_b[0])
		return (ft_free(content_b), NULL);
	content_b = ft_strdup_trim(content_b, rest[fd]);
	return (content_b);
}
