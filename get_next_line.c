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

char	*get_next_line(int fd)
{

	return (NULL);
}

int	main()
{
	int	fd;
	// char	*str;

	fd = open("/Users/kde-la-c/Cursus/GetNextLine/tests/test2", O_RDONLY);

	if (fd > -1)
	{
		printf("%s\n", get_next_line(fd));
		printf("%s\n", get_next_line(fd));
		printf("%s\n", get_next_line(fd));
	}
	else
		printf("caca");
	return (0);
}


/* necesito :
- malloc ret
- malloc buffer
- recuperar cachito
- iterar buffer
- encontrar enter
- parar al enter
- guardar cachito
-  */