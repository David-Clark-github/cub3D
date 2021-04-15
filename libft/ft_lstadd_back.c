/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 19:17:42 by dclark            #+#    #+#             */
/*   Updated: 2020/11/26 00:47:34 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*p;

	p = *alst;
	if (new == NULL || alst == NULL)
		return ;
	new->next = NULL;
	if (p)
	{
		p = ft_lstlast(p);
		(p)->next = new;
	}
	else
		*alst = new;
}
