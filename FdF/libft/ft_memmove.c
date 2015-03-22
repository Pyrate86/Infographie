/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghilbert <ghilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 02:19:34 by ghilbert          #+#    #+#             */
/*   Updated: 2014/11/09 03:20:43 by ghilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	c;

	if (len > 0)
	{
		c = *((const char *)src);
		ft_memmove((char *)(dst) + 1, (char *)(src) + 1, len - 1);
		*((char *)dst) = c;
	}
	return (dst);
}
