/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 15:42:16 by dclark            #+#    #+#             */
/*   Updated: 2021/04/07 15:48:37 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_int_tab(int **tab, int w, int h)
{
	int	x;

	while (--h)
	{
		x = -1;
		while (++x < w)
		{
			ft_putnbr_fd(tab[h][x], 1);
			ft_putchar_fd(' ', 1);
		}
		ft_putchar_fd('\n', 1);
	}
}
