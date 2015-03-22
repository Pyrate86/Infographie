/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghilbert <ghilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 04:18:58 by ghilbert          #+#    #+#             */
/*   Updated: 2014/11/10 04:30:21 by ghilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char	*dst;

	dst = s1;
	while (*dst)
		dst++;
	while (*s2 && n--)
	{
		*dst = *s2;
		dst++;
		s2++;
	}
	*dst = '\0';
	return (s1);
}
