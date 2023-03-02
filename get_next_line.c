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
		ret = ft_substr(line, 0, (ft_strchr(line, '\n')) - line);
		if (!(int)(((ft_strchr(line, '\n')) - line) == (int)ft_strlen(line)))
			*is_cachito = 1;
	}
	else
	{
		ret = ft_strdup(line);
	}
	line = ft_substr(line, (ft_strchr(line, '\n')) - line, ft_strlen(ret));
	return (ret);
}

char	*get_next_line(int fd)
{
	char		*ret;
	char		*buff;
	static char	*cachito;
	int			*is_cachito;
	size_t		blen;

	if (fd < 0)
		return (NULL);
	is_cachito = malloc(sizeof(int) * 1);
	blen = 1;
	ret = NULL;
	buff = calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buff)
		return (NULL);
	if (cachito)
		buff = cachito;
	while (!*is_cachito && blen)
	{
		if (*buff)
		{
			if (!ret)
			{
				ret = ft_strdup(get_start(buff, is_cachito));
			}
			else
			{
				ret = ft_strjoin(ret, get_start(buff, is_cachito));
			}
			if (is_cachito)
			{
				cachito = ft_strchr(buff, '\n') + 1;
				ft_bzero(buff, BUFFER_SIZE);
			}
		}
		else
			blen = read(fd, buff, BUFFER_SIZE);
	}

	return (ret);
}

int	main()
{
	int	fd;
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
	
	// str = get_next_line(fd);
	// printf("%s", str);
	// free(str);

	// str = get_next_line(fd);
	// printf("%s", str);
	// free(str);

	// system("leaks a.out");
	return (0);
}
