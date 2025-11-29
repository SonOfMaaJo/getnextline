/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaoussi <vnaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 14:37:59 by vnaoussi          #+#    #+#             */
/*   Updated: 2025/11/28 00:50:39 by vnaoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

int  is_completel(char *buffer)
{
    size_t  i;

    i = 0;
    while (buffer[i] && buffer[i] != '\n')
        i++;
    if (buffer[i] == '\n')
        return (i);
    return (-1);
}

size_t  get_len_line(int fd)
{
    char    buffer[BUFFER_SIZE];
    size_t  len;
    int     i;
    int     j;

    len = 0;
    i = read(fd, buffer, BUFFER_SIZE);
    if (i >= 0)
        buffer[i] = '\0';
    while (i > 0)
    {
        j = is_completel(buffer);
        if (j >= 0)
            return (len + j);
        len += i;
        i = read(fd, buffer, BUFFER_SIZE);
        if (i < 0)
            return (0);
        buffer[i] = '\0';
    }
    close(fd);
    return (len);
}

char    *ft_strncat_l(char *dest, char *buffer, size_t len)
{
    size_t  i;
    size_t  j;

    i = 0;
    j = 0;
    if (!dest)
        return (NULL);
    while (dest[i])
        i++;
    while (i + j < len && buffer[j])
        dest[i + j] = buffer[i];
    dest[i + j] = '\0';
    return (dest);
}

char    *free_l(char *line)
{
    free(line);
    return (NULL);
}
