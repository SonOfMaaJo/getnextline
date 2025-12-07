/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaoussi <vnaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 14:27:33 by vnaoussi          #+#    #+#             */
/*   Updated: 2025/12/07 18:14:35 by vnaoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# define OPEN_MAX 1024

char	*get_next_line(int fd);
size_t	get_len_line(char *content_buffer);
int		read_and_save(int fd, char **content_b, size_t *size_content);
size_t	ft_strncat_l(char *dest, char *buffer, size_t len, char c);
char	*init_fread(char *buffer, char *content_b, size_t size, char c);
int		ft_free(char *buffer);

#endif
