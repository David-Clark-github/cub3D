/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_pars.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 15:31:10 by user42            #+#    #+#             */
/*   Updated: 2021/03/12 15:41:04 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	space_comma(char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (line[i] == ',')
		i++;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	return (i);
}

void	floor_ceil_pars(char *line, t_pars *pars)
{
	int	i;

	i = 1;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	pars->floor->R = ft_atoi(&line[i]);
	while (ft_isdigit(line[i]))
		i++;
	i += space_comma(&line[i]);
	pars->floor->G = ft_atoi(&line[i]);
	i += space_comma(&line[i]);
	pars->floor->B = ft_atoi(&line[i]);
}
