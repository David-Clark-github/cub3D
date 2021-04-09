/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 16:38:54 by dclark            #+#    #+#             */
/*   Updated: 2020/11/17 17:01:29 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	res;

	i = 0;
	res = -1;
	while (s[i])
	{
		if (s[i] == (char)(c))
			res = i;
		i++;
	}
	if (c == 0)
		return ((char*)(s + i));
	else if (res == -1)
		return (0);
	return ((char*)(s + res));
}
