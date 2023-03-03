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

char	*get_start(char *line, int *is_cachito)
{
	char	*ret;

	if (strchr(line, '\n'))
	{
		ret = ft_substr(line, 0, (ft_strchr(line, '\n') + 1) - line);
		if (!(int)(((ft_strchr(line, '\n') + 1) - line) == (int)ft_strlen(line)))
			*is_cachito = 1;
	}
	else
	{
		ret = ft_strdup(line);
	}
	line = ft_substr(line, (ft_strchr(line, '\n') + 1) - line, ft_strlen(ret));
	// if (ret)
	// 	free(ret);
	return (ret);
}

char	*get_next_line(int fd)
{
	char		*ret;
	char		*buff;
	char		*temp;
	static char	*cachito;
	int			*is_cachito;
	size_t		blen;

	if (fd < 0)
		return (NULL);
	is_cachito = malloc(sizeof(int) * 1);
	if (!is_cachito)
		return (NULL);
	*is_cachito = 0;
	blen = 1;
	ret = NULL;
	buff = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buff)
	{
		free(is_cachito);
		return (NULL);
	}
	if (*cachito)
	{
		printf("hay cachito\n");
		buff = cachito;
	}
		write(1, "test\n", 5);
	while (!*is_cachito/*  && blen */)
	{
		// write(1, "hola\n", 5);
		if (buff && *buff)
		{
			if (!ret)
			{
				ret = ft_strdup(get_start(buff, is_cachito));
			}
			else
			{
				temp = ft_strdup(ret);
				free(ret);
				// printf("ret :%s||\n", ret);
				ret = ft_strjoin(temp, get_start(buff, is_cachito));
				free(temp);
			}
			ft_bzero(buff, BUFFER_SIZE);
			if (*is_cachito)
			{
				cachito = ft_strchr(buff, '\n') + 1;
				ft_bzero(buff, BUFFER_SIZE);
			}
		}
		else
			blen = read(fd, buff, BUFFER_SIZE);
		// printf("ret :%s\n", ret);
	}
	free(is_cachito);
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
	printf("%s\n", str);
	free(str);
	
	str = get_next_line(fd);
	printf("%s\n", str);
	free(str);

	// str = get_next_line(fd);
	// printf("%s", str);
	// free(str);

	// system("leaks a.out");
	return (0);
}
