#include "include.h"

int main(int ac, char **av)
{
	int		fd;
	char	*line_fd;
	char	**split_line;

	fd = open(av[1], O_RDONLY);
	line_fd = file_line(fd);
	split_line = ft_split(line_fd, '\n');
}
