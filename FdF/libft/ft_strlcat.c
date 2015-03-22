/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghilbert <ghilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 06:34:19 by ghilbert          #+#    #+#             */
/*   Updated: 2014/11/10 09:29:07 by ghilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	d;
	size_t	dstlen;

	i = 0;
	d = 0;
	dstlen = ft_strlen(dst);
	if (dstlen > size)
		d = size;
	else
	{
		d = dstlen;
		while (src[i] != '\0' && d + i < size - 1)
		{
			dst[d + i] = src[i];
			i++;
		}
		dst[d + i] = '\0';
	}
	return (d + ft_strlen(src));
}
