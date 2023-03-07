/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kde-la-c <kde-la-c@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 23:48:35 by kde-la-c          #+#    #+#             */
/*   Updated: 2023/02/04 23:48:39 by kde-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	while (*s++)
		count++;
	return (count);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (!c || c == 1024)
		return ((char *)s);
	return (0);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	int		i;
	int		rlen;
	char	*ret;

	i = 0;
	if (ft_strlen(s) >= start + len)
		rlen = len;
	else if (start > ft_strlen(s))
		rlen = 0;
	else
		rlen = ft_strlen(s) - start;
	ret = malloc(sizeof(char) * rlen + 1);
	if (!(ret))
		return (NULL);
	while (i < rlen)
	{
		ret[i] = s[start + i];
		i++;
	}
	ret[i] = 0;
	return (ret);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*ret;
	size_t	totlen;

	i = 0;
	j = 0;
	totlen = ft_strlen(s1) + ft_strlen(s2);
	ret = malloc(sizeof(char) * totlen + 1);
	if (!ret)
		return (NULL);
	while (s1[i])
	{
		ret[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		ret[i + j] = s2[j];
		j++;
	}
	ret[i + j] = 0;
	return (ret);
}

char	*ft_straddmem(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*ret;
	char	*temp;
	size_t	totlen;

	i = 0;
	j = 0;
	temp = NULL;
	ft_memmove(temp, s1, ft_strlen(s1));
	totlen = ft_strlen(temp) + ft_strlen(s2);
	ret = malloc(sizeof(char) * totlen + 1);
	if (!ret)
		return (NULL);
	while (temp[i])
	{
		ret[i] = temp[i];
		// i++;
	}
	while (s2[j])
	{
		ret[i + j] = s2[j];
		j++;
	}
	ret[i + j] = 0;
	free((void *)s1);
	return (ret);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*ret;

	i = 0;
	ret = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!ret)
		return (NULL);
	while (s1[i])
	{
		ret[i] = s1[i];
		i++;
	}
	ret[i] = 0;
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

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dlen;
	size_t	slen;

	slen = ft_strlen(src);
	if (!dst && !size)
		return (slen);
	i = 0;
	dlen = ft_strlen(dst);
	if (size <= dlen)
		return (slen + size);
	else
	{
		while (i + dlen < size - 1 && i < dlen + slen && src[i])
		{
			dst[dlen + i] = src[i];
			i++;
		}
		dst[dlen + i] = 0;
	}
	return (dlen + slen);
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

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (count && SIZE_MAX / count < size)
		return (NULL);
	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, count * size);
	return (ptr);
}