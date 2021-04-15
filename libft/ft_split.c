/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 16:50:31 by dclark            #+#    #+#             */
/*   Updated: 2020/11/28 15:08:46 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*copy(char const *s, int len, int i_s)
{
	int		i;
	char	*copy;

	i = 0;
	if (!(copy = malloc(sizeof(char) * len + 1)))
		return (NULL);
	while (i < len)
	{
		copy[i] = s[i_s];
		i++;
		i_s++;
	}
	copy[len] = '\0';
	return (copy);
}

static int		size_word(char const *s, char c, int i_s)
{
	int	res;

	res = 0;
	while (s[i_s] != c && s[i_s] != '\0')
	{
		i_s++;
		res++;
	}
	return (res);
}

/*
** Return the number of element NOT including the terminating NULL
*/

static int		tab_len(char const *s, char c)
{
	int	i;
	int	res;

	i = -1;
	res = 0;
	if (s[0] == c && s[1] == '\0')
		return (1);
	while (s[++i])
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			res++;
	return (res);
}

static void		clean_split(char **split, int i_sp)
{
	while (i_sp)
	{
		free(split[i_sp]);
		i_sp--;
	}
	free(split[i_sp]);
	free(split);
}

char			**ft_split(char const *s, char c)
{
	char	**split;
	int		i_sp;
	int		i_s;

	i_sp = 0;
	i_s = 0;
	if (s == NULL)
		return (NULL);
	if (!(split = malloc(sizeof(char *) * (tab_len(s, c) + 1))))
		return (NULL);
	while (i_sp < tab_len(s, c))
	{
		while (size_word(s, c, i_s) == 0)
			i_s++;
		if (!(split[i_sp] = copy(s, size_word(s, c, i_s), i_s)))
		{
			clean_split(split, i_sp);
			return (NULL);
		}
		i_s += size_word(s, c, i_s);
		i_sp++;
	}
	split[i_sp] = NULL;
	return (split);
}
