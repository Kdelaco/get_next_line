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


char	*create_cachito()
{
	char	*ret;
	ret = NULL;
	return (ret);
}

char	*cut_line(char *line)
{
	char	*ret;
	ret = NULL;
	return (ret);
}

char	*get_next_line(int fd)
{
	char		*ret;
	char		*buff;
	static char	*cachito;

	if ()
}

/* int	main()
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
	
	str = get_next_line(fd);
	printf("%s", str);
	free(str);

	str = get_next_line(fd);
	printf("%s", str);
	free(str);

	// system("leaks a.out");
	return (0);
} */
