/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 18:23:30 by dclark            #+#    #+#             */
/*   Updated: 2020/11/18 21:06:46 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int i_b;
	int i_l;

	i_b = 0;
	i_l = 0;
	if (little[0] == '\0')
		return ((char*)(big));
	while (big[i_b] && i_b < (int)(len))
	{
		if (big[i_b] == little[i_l])
		{
			while (big[i_b + i_l] == little[i_l] && (i_b + i_l) < (int)(len))
			{
				if (little[i_l + 1] == '\0')
					return ((char*)(&big[i_b]));
				i_l++;
			}
		}
		i_l = 0;
		i_b++;
	}
	return (NULL);
}
