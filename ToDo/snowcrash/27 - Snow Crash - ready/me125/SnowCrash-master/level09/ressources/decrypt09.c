#include "libft/includes/libft.h"

void		decrypt(char *token) {

	int i = -1;
	int len = ft_strlen(token);
	char *result = (char *)malloc(sizeof(char) * len + 1);

	while (++i < len) {
		result[i] = token[i] - i;
	}

	result[i] = '\0';
	ft_printf("result :{%s}\n", result);
}

int main(int ac, char **av) {
	
	int fd = open(av[1], O_RDONLY);
	char	*line;

	get_next_line(fd, &line);
	decrypt(line);
	
	return 0;
}
