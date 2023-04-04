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

char	*get_start(char *buff, int *n)
{
	char	*ret;

	if (!strchr(buff, '\n'))
		return (buff);
	else if ((int)(ft_strchr(buff, '\n') - (buff - 1)) == (int)ft_strlen(buff))
	{
		*n = 2;
		return (buff);
	}
	ret = ft_substr(buff, 0, ft_strchr(buff, '\n') - (buff - 1));
	*n = 1;
	return (ret);
}

char	*get_next_line(int fd)
{
	char		*ret;
	char		buff[BUFFER_SIZE + 1];
	static char	*cachito;
	size_t		bsize;
	int			*n;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	ft_bzero(buff, BUFFER_SIZE + 1);
	// buff = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!cachito)
		cachito = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	n = malloc(sizeof(int));
	ret = NULL;
	bsize = 1;
	*n = 0;
	if (*cachito)
	{
		ft_memmove(buff, cachito, ft_strlen(cachito));
		ft_bzero(cachito, ft_strlen(cachito));
	}
	while (!*n && bsize > 0)
	{
		if (!*buff)
			bsize = read(fd, buff, BUFFER_SIZE);
		if (bsize)
		{
			if (!ret)
				ret = ft_strdup(get_start(buff, n));
			else
			{
				ret = ft_strjoin(ret, get_start(buff, n));
			}
			if (!*n)
				ft_bzero(buff, bsize);
		}
	}
	if (*n == 1)
		ft_memmove(cachito, ft_strchr(buff, '\n') + 1, ft_strlen(ft_strchr(buff, '\n') + 1));
	return (ret);
}

int	main()
{
	int		fd;
	char	*str;

	fd = open("tests/test2", O_RDONLY);

	if (!(fd > -1))
	{
		printf("no >:(");
		return (0);
	}
	str = get_next_line(fd);
	printf("%s", str);
	free(str);
	
	str = get_next_line(fd);
	printf("%s", str);
	free(str);

	str = get_next_line(fd);
	printf("%s", str);
	free(str);

	// system("leaks a.out");
	return (0);
}
