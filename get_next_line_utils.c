/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaoussi <vnaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 14:37:59 by vnaoussi          #+#    #+#             */
/*   Updated: 2025/11/29 20:36:12 by vnaoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

static int  is_completel(char *buffer)
{
    size_t  i;

    i = 0;
    while (buffer[i] && buffer[i] != '\n')
        i++;
    if (buffer[i] == '\n')
        return (1);
    return (0);
}

size_t  get_len_line(char *content_buffer)
{
    size_t	i;

	i = 0;
	if (!content_buffer)
		return (0);
	while (content_buffer[i] != '\n' && content_buffer[i])
		i++;
	if (content_buffer[i] == '\n')
		i++;
	return (i);
}

size_t	ft_strncat_l(char *dest, char *buffer, size_t len)
{
    size_t  i;
    size_t  j;

    i = 0;
    j = 0;
    if (dest == NULL)
        return (0);
    while (dest[i])
        i++;
    while (i + j < len && buffer[j])
	{
        dest[i + j] = buffer[j];
		j++;
	}
    dest[i + j] = '\0';
    return (i + j);
}

static char    *init_fread(char *buffer, char **content_buffer, size_t *size)
{
	char	*content;

	content = (char *)malloc(sizeof(char) * (*size + 1));
	if (content)
	{
		content[0] = '\0';
		ft_strncat_l(content, *content_buffer, *size + 1);
		ft_strncat_l(content, buffer, *size + 1);
	}
	free(*content_buffer);
	return (content);
}

int read_and_save(int fd, char	**content_buffer, size_t *size_content)
{
	char	buffer[BUFFER_SIZE];
	int		i;

	if (fd < 0 || *content_buffer == NULL)
		return (0);
	i = read(fd, buffer, BUFFER_SIZE);
	if (i <= 0)
		return (0);
	while (i > 0)
	{
		buffer[i] = '\0';
		*size_content += i;
		*content_buffer = init_fread(buffer, content_buffer, size_content);
		if (is_completel(buffer))
			return (1);
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == -1)
			return (0);
	}
	return (1);
}
