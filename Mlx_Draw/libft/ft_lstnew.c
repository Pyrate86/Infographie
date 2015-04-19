/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghilbert <ghilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 06:52:13 by ghilbert          #+#    #+#             */
/*   Updated: 2014/11/14 11:24:36 by ghilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*t;
	void	*content_cpy;

	t = (t_list *)malloc(sizeof(t_list));
	content_cpy = (void *)malloc(content_size);
	if (!t || !content_cpy)
		return (NULL);
	if (!content || !content_size)
	{
		t->content = NULL;
		t->content_size = 0;
	}
	else
	{
		t->content = ft_memcpy(content_cpy, content, content_size);
		t->content_size = content_size;
	}
	t->next = NULL;
	return (t);
}
