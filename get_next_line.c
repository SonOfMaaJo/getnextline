/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaoussi <vnaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 23:01:06 by vnaoussi          #+#    #+#             */
/*   Updated: 2025/11/28 00:45:21 by vnaoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char    *get_next_line(int fd)
{
    char    *line;
    size_t  len;
    int     i;
    char    buffer[BUFFER_SIZE];

    if (fd < 0)
        return (NULL);
    len = get_len_line(fd);
    if (len == 0)
        return (NULL);
    line = (char *)malloc(sizeof(char) * (len + 1));
    i = 1;
    if (line)
    {
        line[0] = '\0';
        while (i > 0)
        {
            write(1, "q", 1);
            i = read(fd, buffer, BUFFER_SIZE);
            write(1, "q", 1);
            if (i < 0)
                return (free_l(line));
            buffer[i] = '\0';
            write(1, buffer, i);
            line = ft_strncat_l(line, buffer, len + 1);
            if (is_completel(buffer))
                i = 0;
        }
    }
    return (line);
}
