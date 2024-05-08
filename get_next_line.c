/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamauss <mamauss@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 10:19:27 by mamauss           #+#    #+#             */
/*   Updated: 2024/05/08 16:09:48 by mamauss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_join_and_free(char *buffer, char *buf)
{
	char	*temp;

	temp = ft_strjoin(buffer, buf);
	if (!temp)
		return (NULL);
	free(buffer);
	return (temp);
}

char	*ft_read_file(int fd, char *stash)
{
	char	*buffer;
	int		byte_read;

	if (!stash)
		stash = ft_calloc(1, 1);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	byte_read = 1;
	while (byte_read > 0)
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[byte_read] = '\0';
		stash = ft_join_and_free(stash, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (stash);
}

char	*ft_create_line(char *stash)
{
	char	*line;
	int		i;

	i = 0;
	if (!stash[i])
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] && stash[i] == '\n')
		line[i++] = '\n';
	return (line);
}

char	*ft_new_stash(char *stash)
{
	int		i;
	int		j;
	char	*new_stash;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	new_stash = ft_calloc((ft_strlen(stash) - i + 1), sizeof(char));
	if (!new_stash)
		return (NULL);
	i++;
	j = 0;
	while (stash[i])
		new_stash[j++] = stash[i++];
	free(stash);
	return (new_stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free (stash);
		stash = NULL;
		return (NULL);
	}
	stash = ft_read_file(fd, stash);
	if (!stash)
		return (NULL);
	line = ft_create_line(stash);
	stash = ft_new_stash(stash);
	return (line);
}
