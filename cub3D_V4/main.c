#include "include.h"

int main(int ac, char **av)
{
	char	*line_fd;
	char	**split_line;
	char	*buffer = malloc(sizeof(char) * 20);
	int		fd;
	int		i = 0;

	fd = open(av[1],  O_RDONLY);
	line_fd = file_line(fd);
	split_line = ft_split(line_fd, '\n');
	while (split_line[i] != 0) {
		printf("%s\n", split_line[i]);
		i++;
	}
}
