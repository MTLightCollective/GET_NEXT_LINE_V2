/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamauss <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:09:39 by mamauss           #+#    #+#             */
/*   Updated: 2024/05/06 13:52:00 by mamauss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		totalsize;
	char	*answer;
	int		i;
	int		j;

	i = 0;
	totalsize = ft_strlen(s1) + ft_strlen(s2);
	answer = malloc(sizeof(char) * (totalsize + 1));
	if (!answer || !s1 || !s2)
		return (NULL);
	while (s1[i] != 0)
	{
		answer[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != 0)
	{
		answer[i] = s2[j];
		i++;
		j++;
	}
	answer[totalsize] = '\0';
	return (answer);
}

char	*ft_strchr(const char *str, int theChar)
{
	char	*answer;

	answer = (char *)str;
	while (*answer != thechar && *answer != 0)
		answer++;
	if (*answer == thechar)
		return (answer);
	else
		return (NULL);
}

void	ft_bzero(void *str, size_t n)
{
	char	*answer;
	size_t	i;

	answer = (char *)str;
	i = 0;
	while (i < n)
	{
		answer[i] = '\0';
		i++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*answer;

	answer = malloc(sizeof(char) * size);
	if (!answer)
		return (NULL);
	ft_bzero(answer, count * size);
	return (answer);
}
