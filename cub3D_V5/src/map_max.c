#include "include.h"

void	map_max(t_map_err *s_map, char **map)
{
	int	y;

	y = 0;
	s_map->x_max = 0;
	s_map->y_max = 0;
	while (map[y])
	{
		if (ft_strlen(map[y]) > s_map->x_max)
			s_map->x_max = ft_strlen(map[y]);
		y++;
	}
	s_map->y_max = y;
}
