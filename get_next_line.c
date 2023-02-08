/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kde-la-c <kde-la-c@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 23:40:01 by kde-la-c          #+#    #+#             */
/*   Updated: 2023/02/04 23:40:04 by kde-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// WIP
char	*cut_line(char *buff, char **cachito)
{
	char	*ret;

	
	return (ret);
}

char	*get_next_line(int fd)
{
	char		*ret;
	char		*buff;
	static char	*cachito;
	int			size;
	// int			b;
	(void) fd;

	// initialization of vars
	b = 1;
	size = 0;
	buff = malloc(sizeof(char) * BUFFER_SIZE);
	if (!buff)
		return (NULL);

	// operacion cachito FALTA
	if (cachito)
	{
		if (ret)
		{
			free(ret);
			ret = ft_strjoin(ret, cachito);
		}
		else
			ret = ft_strdup(cachito);
		cachito = NULL;
	}

	if (!cachito)
	{
		size = read(fd, buff, BUFFER_SIZE);
		if (ret)
		{
			free(ret);
			ret = ft_strjoin(ret, buff);
		}
		else
			ret = ft_strdup(buff);
	}

	while (b)


	return (NULL);
}

int	main()
{
	int	fd;
	// char	*str;

	fd = open("tests/test2", O_RDONLY);

	if (fd > -1)
	{
		printf("%s\n", get_next_line(fd));
		printf("%s\n", get_next_line(fd));
		printf("%s\n", get_next_line(fd));
	}
	else
		printf("no >:(");
	return (0);
}
