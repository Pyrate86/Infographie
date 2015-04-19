/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghilbert <ghilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 23:45:19 by ghilbert          #+#    #+#             */
/*   Updated: 2014/11/12 07:36:10 by ghilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_iswspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	return (0);
}

char			*ft_strtrim(char const *s)
{
	char	*trimed;
	int		i;
	int		j;
	int		k;

	if (!s)
		return (NULL);
	i = 0;
	j = ft_strlen(s) - 1;
	k = 0;
	while (ft_iswspace(s[i]))
		i++;
	while (ft_iswspace(s[j]))
		j--;
	if (j < 0)
		j = i;
	trimed = ft_memalloc(j - i);
	while (i <= j)
	{
		trimed[k] = s[i];
		k++;
		i++;
	}
	trimed[k] = '\0';
	return (trimed);
}
