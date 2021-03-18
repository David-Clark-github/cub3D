#include "include.h"

int	check_ac_av(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac < 2 || ac > 3)
		return (-1);
	while (av[1][i] != '.')
		i++;
	if ()
	if (ft_strlen(&av[1][i]) != 3)
		return (-1);
	if (av[1][i] != 'c' || av[1][i + 1] != 'u' || av[1][i + 2] != 'b')
		return (-1);
	return (1);
}
