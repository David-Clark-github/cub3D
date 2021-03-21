#include "include.h"

static int	ac_two(char **av)
{
	if (ft_strlen(av[1]) < 4)
		return (-1);
	if (ft_strncmp(&av[1][ft_strlen(av[1]) - 4], ".cub", 4) != 0)
		return (-1);
	return (1);
}

static int	ac_three(char **av)
{
	if (ac_two(av) == -1)
		return (-1);
	if (ft_strlen(av[2]) != 6)
		return (-1);
	if (ft_strncmp("--save", av[2], 6) != 0)
		return (-1);
	return (1);
}

int	check_ac_av(int ac, char **av)
{
	int	res;
	int	fd;

	if (ac < 2 || ac > 3)
		return (-1);
	if (ac == 2)
		res = ac_two(av);
	if (ac == 3)
		res = ac_three(av);
	if ((fd = open(av[1], O_DIRECTORY)) != -1)
	{
		close(fd);
		return (-1);
	}
	if ((fd = open(av[1], O_RDONLY)) == -1)
	{
		close(fd);
		return (-1);
	}
	return (res);
}
