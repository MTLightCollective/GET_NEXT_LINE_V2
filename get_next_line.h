/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamauss <mamauss@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 11:35:57 by mamauss           #+#    #+#             */
/*   Updated: 2024/05/06 14:58:42 by mamauss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stddef.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif

size_t	ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *haystack, int needle);
void	ft_bzero(void *str, size_t n);
void	*ft_calloc(size_t count, size_t size);
char	*ft_join_and_free(char *buffer, char *stash);
char	*ft_read_file(int fd, char *stash);
char	*ft_create_line(char *stash);
char	*ft_new_stash(char *stash);
char	*get_next_line(int fd);

#endif
