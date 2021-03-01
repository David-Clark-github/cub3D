#include "include.h"

int main(int ac, char **av)
{
	t_el_l	elem_l;
	int		fd;
	char	*line_fd;
	char	**split_line;

	fd = open(av[1], O_RDONLY);
	line_fd = file_line(fd);
	split_line = ft_split(line_fd, '\n');
	print_split_l(split_line);

}
