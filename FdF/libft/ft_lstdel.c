/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghilbert <ghilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 07:38:56 by ghilbert          #+#    #+#             */
/*   Updated: 2014/11/14 11:24:06 by ghilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;
	t_list	*tmp2;

	if (!alst || !*alst || !del)
		return ;
	tmp = *alst;
	while (tmp->next)
	{
		del(tmp->content, tmp->content_size);
		tmp2 = tmp;
		free(tmp2);
		tmp = tmp->next;
	}
	free(tmp);
	*alst = NULL;
}
