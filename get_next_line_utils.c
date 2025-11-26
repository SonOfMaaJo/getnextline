/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaoussi <vnaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 14:37:59 by vnaoussi          #+#    #+#             */
/*   Updated: 2025/11/25 15:12:11 by vnaoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

size_t  is_completel(char *buffer)
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

    len = 0;
    if (fd < 1)
        return (0);
    len

}

