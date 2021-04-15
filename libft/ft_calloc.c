/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 21:40:08 by dclark            #+#    #+#             */
/*   Updated: 2020/11/26 18:20:00 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*mem;
	size_t	n_octets;

	n_octets = nmemb * size;
	if (!(mem = malloc(n_octets)))
		return (NULL);
	if (n_octets != 0)
		ft_bzero(mem, n_octets);
	return (mem);
}
