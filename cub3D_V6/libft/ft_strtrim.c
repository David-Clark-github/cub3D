/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 23:38:14 by dclark            #+#    #+#             */
/*   Updated: 2020/11/29 21:00:11 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		is_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int		index_start(char const *s1, char const *set)
{
	int	s;

	s = 0;
	while (s1[s])
	{
		if (is_set(s1[s], set) == 1)
			s++;
		else
			return (s);
	}
	return (s);
}

static int		index_last(char const *s1, char const *set)
{
	int	l;

	l = ft_strlen(s1) - 1;
	while (l >= 0)
	{
		if (is_set(s1[l], set) == 1)
			l--;
		else
			return (l);
	}
	if (l < 0)
		return (0);
	return (l);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	char	*trim;
	int		i_s;
	int		i_l;
	int		i_t;

	if (!s1 || !set)
		return (NULL);
	i_t = 0;
	i_s = index_start(s1, set);
	i_l = index_last(s1, set);
	if (i_l >= i_s)
	{
		if (!(trim = malloc(sizeof(char) * ((i_l - i_s) + 2))))
			return (NULL);
	}
	while (i_s <= i_l)
		trim[i_t++] = s1[i_s++];
	if (i_t == 0)
		if (!(trim = malloc(sizeof(char))))
			return (NULL);
	trim[i_t] = '\0';
	return (trim);
}
