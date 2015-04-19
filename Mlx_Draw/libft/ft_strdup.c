/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghilbert <ghilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 01:57:48 by ghilbert          #+#    #+#             */
/*   Updated: 2014/11/10 08:29:59 by ghilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dst;
	int		len;

	len = ft_strlen(s1);
	dst = ft_memalloc(len + 1);
	if (dst == NULL)
		return (NULL);
	while (len--)
	{
		dst[len] = s1[len];
	}
	return (dst);
}
