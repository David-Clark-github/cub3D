/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 20:11:29 by dclark            #+#    #+#             */
/*   Updated: 2020/11/28 17:35:08 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	len_m;

	if (!s)
		return (NULL);
	if (start > (unsigned int)ft_strlen(s))
	{
		if (!(sub = malloc(sizeof(char))))
			return (NULL);
		sub[0] = '\0';
		return (sub);
	}
	else if (ft_strlen(&s[start]) >= (int)len)
		len_m = len;
	else
		len_m = ft_strlen(&s[start]);
	if (!(sub = malloc(sizeof(char) * len_m + 1)))
		return (NULL);
	ft_strlcpy(sub, &s[start], len_m + 1);
	return (sub);
}
