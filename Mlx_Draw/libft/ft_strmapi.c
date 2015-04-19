/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghilbert <ghilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 09:01:07 by ghilbert          #+#    #+#             */
/*   Updated: 2014/11/12 09:36:10 by ghilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	int		i;

	i = 0;
	str = NULL;
	if (s && f)
	{
		str = ft_strnew(ft_strlen(s));
		if (str)
		{
			while (*s)
			{
				str[i] = (*f)(i, *s);
				i++;
				s++;
			}
		}
	}
	return (str);
}
