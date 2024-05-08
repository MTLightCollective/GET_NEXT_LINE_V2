/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamauss <mamauss@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 12:43:35 by mamauss           #+#    #+#             */
/*   Updated: 2024/05/08 16:06:57 by mamauss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*str;

	str = NULL;
	fd = open("test.txt", O_RDONLY);
	str = get_next_line(fd);
	while (str != NULL)
	{
		printf("line found : %s\n", str);
		free(str);
		str = get_next_line(fd);
	}
	if (str == NULL)
	{
		printf("its NULL : %s\n", str);
		str = NULL;
		free(str);
	}
	close(fd);
}
