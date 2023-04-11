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

char	*read_line(char *buff, int fd, int *n)
{
	char		*ret;
	char		*tmp;
	ssize_t		bsize;

	ret = NULL;
	bsize = 1;
	while (!*n && bsize > 0)
		if (!*buff)
			bsize = read(fd, buff, BUFFER_SIZE);
	else
	{
		tmp = get_start(buff, n);
		if (!ret)
			ret = ft_strdup(tmp);
		else
			ret = ft_strjoin(ret, tmp);
		if (!*n)
			ft_bzero(buff, BUFFER_SIZE + 1);
	}
	if (*n == 1)
		free(tmp);
	if (bsize == -1)
		*n = bsize;
	return (ret);
}

char	*get_next_line(int fd)
{
	char		*ret;
	char		*tmp;
	char		buff[BUFFER_SIZE + 1];
	static char	cachito[BUFFER_SIZE];
	int			n;

	if (BUFFER_SIZE <= 0)
		return (NULL);
	ft_bzero(buff, BUFFER_SIZE + 1);
	ret = NULL;
	n = 0;
	if (cachito[0])
	{
		ft_memmove(buff, cachito, ft_strlen(cachito));
		ft_bzero(cachito, ft_strlen(cachito));
	}
	ret = read_line(buff, fd, &n);
	if (n == 1)
	{
		tmp = ft_strchr(buff, '\n') + 1;
		ft_memmove(cachito, tmp, ft_strlen(tmp));
	}
	if (n == -1)
		return (free(ret), NULL);
	return (ret);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned long	i;
	unsigned char	*tmp;

	i = 0;
	tmp = s;
	while (i < n)
	{
		tmp[i] = 0;
		i++;
	}
	s = tmp;
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned long		i;
	unsigned char		*ret;
	unsigned char		*tmp1;
	const unsigned char	*tmp2;

	i = 0;
	ret = dst;
	tmp1 = dst;
	tmp2 = src;
	if (tmp1 > tmp2)
		while (len-- > 0)
			tmp1[len] = tmp2[len];
	else
	{
		while (i < len && (dst || src))
		{
			tmp1[i] = tmp2[i];
			i++;
		}
	}
	dst = tmp1;
	return (ret);
}
