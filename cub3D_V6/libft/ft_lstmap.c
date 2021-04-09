/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 13:25:20 by dclark            #+#    #+#             */
/*   Updated: 2020/11/26 14:21:53 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Tmp est le mirroire de lst
** Head est l'adresse du premier element,
** p est le pointeur qui parcour la list a retourner cree par lstnew
*/

/*
** Tant que tmp n'est pas nul AKA lst, on cree la nouvelle list
** Si pas possible, clear la chaine a partir de head
** et on utlise del dans clear
** On va au maillon suivant sur tmp et p (cree avec lstnew())
** On retourne Head a la fin :)
*/

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*p;
	t_list	*tmp;

	if (lst == NULL || (head = ft_lstnew(f(lst->content))) == NULL)
		return (NULL);
	p = head;
	tmp = lst->next;
	while (tmp)
	{
		if (!(p->next = ft_lstnew(f(tmp->content))))
		{
			ft_lstclear(&head, del);
			return (NULL);
		}
		tmp = tmp->next;
		p = p->next;
	}
	return (head);
}
