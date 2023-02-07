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

char	*ft_readtemp(char *buffer, int i)
{
	int	j;

	j = 0;
	while (buffer[j] && buffer[j] != ' ' && j < i)
	{
		j++;
	}
		// write(1, "\non te trouvera ta mere\n", 24);
	if (j == i)
		return NULL;
	else
		return (buffer + j);
}

char	*get_next_line(int fd)
{
	static char	*temp;
	char		*ret;
	int			i;
	// int			j;
	int			mem;

	temp = malloc(sizeof(char) * BUFFER_SIZE);
	ret = NULL;
	i = 1;
	mem = 0;
	// j = 0;
	while (i)
	{
		if (!temp)
		{
			i = read(fd, temp, BUFFER_SIZE);
			temp = ft_readtemp(temp, i);
			ret = ft_strjoin(ret, temp);
		}
		else if (temp && !ret)
		{
			ret = ft_strjoin(ret, temp);
			temp = NULL;
		}
		else
		{
			ret = ft_strjoin(ret, temp);
			temp = NULL;
			i = 0;
		}
	}
	printf("mem :%i\n", mem);
	printf("ret :%s\n", ret);
	return (temp);
}

int	main()
{
	// char	*str;
	int		fd = open("test", O_RDONLY);
	int		i = 0;

	if (fd > 0)
		while (i++ < 1)
			printf("ret :%s\n", get_next_line(fd));
	return 0;
}