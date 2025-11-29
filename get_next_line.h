/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaoussi <vnaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 14:27:33 by vnaoussi          #+#    #+#             */
/*   Updated: 2025/11/29 18:44:19 by vnaoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>
# define BUFFER_SIZE 42

char    *get_next_line(int fd);
size_t  get_len_line(char *content_buffer);
int		read_and_save(int fd, char **content_buffer, size_t *size_content);
size_t	ft_strncat_l(char *dest, char *buffer, size_t len);

#endif
