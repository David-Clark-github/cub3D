#include "include.h"

void	create_map(t_map_err *s_map, char **map)
{
	int	x;
	int	y;
	int reste;

	y = 0;
	x = 0;
	if(!(s_map->map = (char **)malloc(sizeof(char *) * (s_map->y_max + 1))))
		return;
	while (y < s_map->y_max)
	{
		s_map->map[y] = (char *)malloc(sizeof(char) * (s_map->x_max + 1));
		y++;
	}
	y = 0;
	while (y < s_map->y_max)
	{
		reste = s_map->x_max - ft_strlen(s_map->map[y]);
		//printf("reste = %d\n", reste);
		while (x < ft_strlen(map[y]))
		{
			s_map->map[y][x] = map[y][x];
			x++;
		}
		while (reste-- > 0)
		{
			s_map->map[y][x] = ' ';
			x++;
		}
		s_map->map[y][x] = '\0';
		//printf("y = %d len = %d line = %s\n", y, ft_strlen(s_map->map[y]), s_map->map[y]);
		x = 0;
		y++;
	}
	s_map->map[y] = 0;
}
