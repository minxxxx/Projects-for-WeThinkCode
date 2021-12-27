#include "npuzzle.h"

char *get_next_line(int fd)
{
	ssize_t readed;
	char *result;
	char *buff;

	if (!(buff = malloc(sizeof(*buff) * 2)))
	{
		ft_putendl_fd("npuzzle: can't malloc", 2);
		exit(EXIT_FAILURE);
	}
	ft_bzero(buff, 2);
	if (!(result = malloc(sizeof(*result))))
	{
		ft_putendl_fd("npuzzle: can't malloc", 2);
		exit(EXIT_FAILURE);
	}
	ft_bzero(result, 1);
	while ((readed = read(fd, buff, 1)) > 0)
	{
		if (buff[0] == '\n')
			return (result);
		if (!(result = ft_strjoin_free1(result, buff)))
		{
			ft_putendl_fd("npuzzle: can't malloc", 2);
			exit(EXIT_FAILURE);
		}
	}
	if (readed == -1)
	{
		ft_putendl_fd("npuzzle: error while reading puzzle file", 2);
		exit(EXIT_FAILURE);
	}
	return (result);
}
