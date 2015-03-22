/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghilbert <ghilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 09:14:10 by ghilbert          #+#    #+#             */
/*   Updated: 2014/11/14 10:57:22 by ghilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*begin;
	t_list	*tmp;

	begin = NULL;
	if (!lst || !f)
		return (NULL);
	while (lst)
	{
		tmp = ft_lstnew(lst->content, lst->content_size);
		tmp = f(tmp);
		if (!begin)
			begin = tmp;
		else
			ft_lstend(begin)->next = tmp;
		lst = lst->next;
	}
	return (begin);
}
