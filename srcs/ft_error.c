/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 11:13:26 by dclark            #+#    #+#             */
/*   Updated: 2021/04/16 12:12:38 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	ft_error(char *message, int error, t_data *data)
{
	if (error == 0)
	{
		printf("%s\n", message);
		printf("Avant print\n");
		if (data->raw_cub == NULL)
			printf("raw_cub existe pas\n");
		else
			ft_print_split(data->raw_cub);
		printf("Après print\n");
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
