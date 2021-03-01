#include "include.h"


void	printf_split_line(char **split_line)
{
	int	i;

	i = 0;
	while (split_line[i] != 0)
	{
		printf("%s\n", split_line[i]);
		i++;
	}
}

void	print_check_cub(t_check_cub cc)
{
	printf("res	= %d\n", cc.resolution);
	printf("north	= %d\n", cc.north);
	printf("south	= %d\n", cc.south);
	printf("west	= %d\n", cc.west);
	printf("east	= %d\n", cc.east);
	printf("sprit	= %d\n", cc.sprit);
	printf("floor	= %d\n", cc.floor);
	printf("ceiling	= %d\n", cc.ceiling);
	printf("map	= %d\n", cc.map);
}

int main(int ac, char **av)
{
	t_check_cub	check_cub;
	t_map		map;
	t_pars_l	pars_l;
	char		*line_fd;
	char		**split_line;
	char		*buffer = malloc(sizeof(char) * 20);
	int			fd;
	int			i = 0;

	map.map_st = 8;
	fd = open(av[1],  O_RDONLY);
	line_fd = file_line(fd);
	split_line = ft_split(line_fd, '\n');
	init_check_cub(&check_cub);
	pars_line_cub(split_line, &pars_l);
	check_cub.resolution = check_resolution(split_line[pars_l.res_l]);
	check_cub.north = check_path(split_line[1])
	check_cub.floor = check_floor_ceiling(split_line[6]);
	check_cub.ceiling = check_floor_ceiling(split_line[7]);
	//print_check_cub(check_cub);
	map_max(&map, split_line);
	create_map(&map, split_line);
	printf_split_line(map.map);
}
