/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghilbert <ghilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 00:13:21 by ghilbert          #+#    #+#             */
/*   Updated: 2014/11/12 07:34:24 by ghilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_wordnb(char const *str, char c)
{
	int	i;
	int	result;

	if (!str || str[0] == '\0')
		return (0);
	i = 0;
	result = 0;
	if (str[i] != c)
		result++;
	while (str[i])
	{
		if (str[i] == c && str[i + 1] != c && str[i + 1] != '\0')
			result++;
		i++;
	}
	return (result);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**splits;
	int		i;
	int		j;
	int		k;

	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	k = 0;
	splits = (char **)malloc(sizeof(char *) * ft_wordnb(s, c) + 1);
	while (k < ft_wordnb(s, c))
	{
		while (s[i] == c && s[i])
			i++;
		j = i;
		while (s[j] != c && s[j])
			j++;
		splits[k] = ft_strsub(s, i, (j - i));
		i = j;
		k++;
	}
	splits[k] = 0;
	return (splits);
}
