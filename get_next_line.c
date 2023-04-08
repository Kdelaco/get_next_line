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
	int		nlen;

	if (!ft_strchr(buff, '\n'))
		return (buff);
	nlen = ft_strchr(buff, '\n') - (buff - 1);
	if (nlen == (int)ft_strlen(buff))
	{
		*n = 2;
		return (buff);
	}
	ret = ft_substr(buff, 0, nlen);
	*n = 1;
	return (ret);
}

char	*get_next_line(int fd)
{
	char		*ret;
	char		*tmp;
	char		buff[BUFFER_SIZE + 1];
	static char	cachito[BUFFER_SIZE];
	size_t		bsize;
	int			n;

	if (BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	ft_bzero(buff, BUFFER_SIZE + 1);
	ret = NULL;
	bsize = 1;
	n = 0;
	if (cachito[0])
	{
		ft_memmove(buff, cachito, ft_strlen(cachito));
		ft_bzero(cachito, ft_strlen(cachito));
	}
	while (!n && bsize > 0)
	{
		if (!*buff)
			bsize = read(fd, buff, BUFFER_SIZE);
		if (bsize > 0)
		{
			tmp = get_start(buff, &n);
			if (!ret)
				ret = ft_strdup(tmp);
			else
				ret = ft_strjoin(ret, tmp);
			if (!n)
				ft_bzero(buff, BUFFER_SIZE + 1);
		}
	}
	if (n == 1)
	{
		free(tmp);
		ft_memmove(cachito, ft_strchr(buff, '\n') + 1, BUFFER_SIZE);
	}
	return (ret);
}

/* int	main()
{
	int		fd;
	int		i;
	char	*str;

	fd = open("tests/variable_nls.txt", O_RDONLY);
	i = 0;
	if (!(fd > -1))
	{
		printf("no >:(");
		return (0);
	}

	str = get_next_line(fd);
	printf("%s", str);
	free(str);

	while (str)
	{
		str = get_next_line(fd);
		printf("%s", str);
		free(str);
	}

	// system("leaks a.out");
	return (0);
} */
