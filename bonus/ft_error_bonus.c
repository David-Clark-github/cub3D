/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 11:13:26 by dclark            #+#    #+#             */
/*   Updated: 2021/04/08 15:33:04 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	ft_error(char *message, int error, t_data *data)
{
	if (error == 0)
	{
		printf("%s\n", message);
		ft_empty_data(data);
		exit(EXIT_SUCCESS);
	}
	else
	{
		printf("%s\n", "Error");
		printf("%s\n", message);
		ft_empty_data(data);
		exit(EXIT_FAILURE);
	}
}
