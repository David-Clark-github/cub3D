#include "include.h"

void	n_number(char *line)
{
	int	i;
	int	num;

	i = 0;
	num = 0;
	while (line[i])
	{
		while (!ft_isdigit(line[i]) && line[i])
			++i;
		if (ft_isdigit(line[i]))
			++num;
		while (ft_isdigit(line[i]))
			++i;
	}
	if (num != 2)
		ft_error("L'element R est incorrect", 1, 0);
}

void	min_max(char *line)
{
	int	i;

	i = 0;
	while (line[i] && !ft_isdigit(line[i]))
		++i;
	if (ft_atoi(&line[i]) < 1)
		ft_error("La largeur de la fenetre est trop petite", 1, 0);
}

void	check_res(char *line)
{
	int	i;

	i = 0;
	while (line[i] && !ft_isdigit(line[i]))
		++i;
	if (ft_atoi(&line[i]) < 1)
		ft_error("La largeur de la fenetre est trop petite", 1, 0);
	while (ft_isdigit(line[i]))
		++i;
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		++i;
	if (ft_atoi(&line[i]) < 1)
		ft_error("La hauteur de la fenetre est trop petite", 1, 0);
}
