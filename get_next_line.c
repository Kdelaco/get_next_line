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

// divides the provided string (buff or cachito) after the '\n' character and returns the first part, second part is stored on cachito
char	*cut_line(char *buff, char *cachito)
{
	char	*ret;
	char	*str;

	if (!*buff && !*cachito)
		return (NULL);
	// printf("buff :%s cachito :%s\n", buff, cachito);
	/* fills str with the string to be cut */
	if (!*cachito)
	{
		ft_memmove(cachito, buff, ft_strlen(buff));
		ft_bzero(buff, BUFFER_SIZE);
	}
	str = ft_calloc(ft_strlen(cachito) + 1, sizeof(char));
	ft_memmove(str, cachito, ft_strlen(cachito));

	/* fills ret with the string to be returned */
	ret = ft_calloc((ft_strchr(str, '\n') - str) + 1, sizeof(char));
	ft_memmove(ret, str, (ft_strchr(str, '\n') - str) + 1);

	/* fills cachito with the string to be left for later */
	ft_bzero(cachito, BUFFER_SIZE);
	ft_memmove(cachito, ft_strchr(str, '\n') + 1, ft_strlen(ft_strchr(str, '\n') + 1));

	free(str);
	return (ret);
}

/* int main()
{
	char		*buff;
	static char	*cachito;
	char		*ret;

	buff = ft_strdup("hola\nahahahaha\nhey\n");
	if (!cachito)
		cachito = calloc(BUFFER_SIZE, sizeof(char));
	// cachito = ft_strdup("\n");
	// cachito = calloc(BUFFER_SIZE, sizeof(char));
	if (!cachito)
		return 0;

	printf("buff :%s\n", buff);
	if (*cachito)
		printf("cachito :%s\n", cachito);

	ret = cut_line(buff, cachito);
	printf("--execution--\n");
	printf("buff :%s\nret :%s\ncachito :%s\n", buff, ret, cachito);
	free(ret);

	ret = cut_line(buff, cachito);
	printf("--execution--\n");
	printf("buff :%s\nret :%s\ncachito :%s\n", buff, ret, cachito);
	free(ret);

	ret = cut_line(buff, cachito);
	printf("--execution--\n");
	printf("buff :%s\nret :%s\ncachito :%s\n", buff, ret, cachito);
	free(ret);

	free(cachito);
	// system("leaks a.out");
	return 0;
} */

/* char	*get_next_line(int fd)
{
	char		*ret;
	char		*buff;
	static char	*cachito;
	int			*b;
	size_t		bsize;

	buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!cachito)
		cachito = ft_calloc(BUFFER_SIZE, sizeof(char));
	if (!cachito)
		return (NULL);

	if (*cachito)
		if (!ret)
			ret = cut_line(buff, cachito, b);
		else
			ft_strlcat(ret, cut_line(buff, cachito, b), BUFFER_SIZE);

	if (!*cachito)
	{
		bsize = read(fd, buff, BUFFER_SIZE);
		if (!bsize)
			return (NULL);
		if (!ret)
			ret = cut_line(buff, cachito, b);
		else
			ft_strlcat(ret, cut_line(buff, cachito, b), BUFFER_SIZE);
	}
	return (ret);
} */

/* int	main()
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
} */
