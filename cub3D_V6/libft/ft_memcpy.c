/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 02:14:59 by dclark            #+#    #+#             */
/*   Updated: 2020/11/28 16:41:21 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char *s;
	unsigned char *d;

	if (!dest && !src)
		return (NULL);
	s = (unsigned char *)src;
	d = dest;
	while (0 < n--)
	{
		*d++ = *s++;
	}
	return (dest);
}
