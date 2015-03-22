/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghilbert <ghilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 14:31:54 by ghilbert          #+#    #+#             */
/*   Updated: 2014/11/10 00:35:46 by ghilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	c;

	if (s2[0] == '\0')
		return ((char *)s1);
	if (ft_strlen(s2) > n)
		return (NULL);
	i = 0;
	c = 0;
	while (s1[i] != '\0' || i < n)
	{
		while (s1[i] == s2[c] && s1[i] != '\0' && i < n)
		{
			i++;
			c++;
		}
		if (s2[c] == '\0')
			return ((char *)&s1[i - c]);
		else
			c = 0;
		i++;
	}
	return (NULL);
}
