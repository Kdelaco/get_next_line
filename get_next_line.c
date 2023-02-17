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
	int		i;
	int		j;

	i = 0;
	j = 0;
	ret = calloc(50, 1);
	str = calloc(50, 1);
	if (!cachito)
		memmove(str, buff, strlen(buff));
	else
		memmove(str, cachito, strlen(cachito));
	printf(" str :%s\n", str);
	memmove(ret, str, (strchr(str, '\n') - str) + 1);
	memmove(cachito, strchr(str, '\n') + 1, strlen(strchr(str, '\n') + 1));
	// while (((i > 0 && str[i - 1] != '\n') || !i) && str[i])
	// 	ret[i] = str[i++];
	// while (str[i])
	// 	cachito[j] = str[i + j++];
	return (ret);
}

int main()
{
	char		*buff;
	static char	*cachito;
	char		*ret;

	buff = ft_strdup("hola\nquetal");
	cachito = malloc(50);

	printf("buff :%s\ncachito :%s\n", buff, cachito);
	ret = cut_line(buff, cachito);
	printf("buff :%s\ncachito :%s\nret :%s\n", buff, cachito, ret);

	return 0;
}

char	*get_next_line(int fd)
{
	char		*ret; // gets added memory
	char		*buff; // recieves read memory // goes into cut_line
	static char	*cachito; // recieves exceeding string // can be NULL // can get a rest of itself // is linked to cut_line
	int			size; // gets amount of read bytes
	int			b; // allows to iterate

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

	// operacion read FALTA
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
