/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 02:14:04 by dclark            #+#    #+#             */
/*   Updated: 2020/11/28 16:36:40 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*d;
	const char	*s;

	if (!dest && !src)
		return (NULL);
	s = src;
	d = dest;
	if (d < s)
		while (0 < n--)
			*d++ = *s++;
	else
	{
		s = s + (n - 1);
		d = d + (n - 1);
		while (0 < n--)
			*d-- = *s--;
	}
	return (dest);
}
