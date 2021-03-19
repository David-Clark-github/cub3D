#include "include.h"

static int	ac_two(char **av)
{
	int	i;

	i = 0;
	while (av[1][i] != '.')
		++i;
	if (av[1][i] == '.')
		++i;
	if (ft_strlen(&av[1][i]) != 3)
		return (-1);
	if (av[1][i] != 'c' || av[1][i + 1] != 'u' || av[1][i + 2] != 'b')
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

	if (ac < 2 || ac > 3)
		return (-1);
	if (ac == 2)
		res = ac_two(av);
	if (ac == 3)
		res = ac_three(av);
	return (res);
}
