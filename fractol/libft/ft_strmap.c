/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghilbert <ghilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 09:00:04 by ghilbert          #+#    #+#             */
/*   Updated: 2014/11/12 09:34:05 by ghilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
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
				str[i] = (*f)(*s);
				i++;
				s++;
			}
			str[i] = '\0';
		}
	}
	return (str);
}
