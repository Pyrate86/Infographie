/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghilbert <ghilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 04:48:45 by ghilbert          #+#    #+#             */
/*   Updated: 2014/11/12 09:18:34 by ghilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(int n)
{
	int	i;

	i = 0;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i == 0 ? 1 : i);
}

char		*ft_itoa(int n)
{
	int				i;
	int				neg;
	int				len;
	char			*result;
	unsigned int	un;

	i = 0;
	neg = 0;
	len = n < 0 ? ft_intlen(n) + 1 : ft_intlen(n);
	result = ft_strnew(len);
	if (!result)
		return (NULL);
	if (n < 0)
	{
		result[i] = '-';
		neg = 1;
	}
	un = (n <= 0) ? -n : n;
	while (i < len - neg)
	{
		result[i + neg] = ((un / ft_pow(10, len - i - 1 - neg)) % 10) + '0';
		i++;
	}
	return (result);
}
