/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 18:17:45 by dclark            #+#    #+#             */
/*   Updated: 2020/11/21 23:50:54 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	str_n_d(char *dst, size_t n)
{
	unsigned int	i;

	i = 0;
	while (dst[i] && (i < n))
		i++;
	return (i);
}

unsigned int	str_l_s(const char *src)
{
	unsigned int	i;

	i = 0;
	while (src[i])
		i++;
	return (i);
}

size_t			ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	len_d;
	unsigned int	len_d2;
	size_t			i_src;

	i = str_n_d(dst, size);
	i_src = 0;
	len_d = str_n_d(dst, size);
	len_d2 = len_d;
	if (len_d == size)
		return (size + str_l_s(src));
	while (len_d < (size - 1) && src[i_src] && size != 0)
	{
		dst[i] = src[i_src];
		i++;
		i_src++;
		len_d++;
	}
	dst[i] = '\0';
	return (len_d2 + str_l_s(src));
}
