/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghilbert <ghilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 22:48:53 by ghilbert          #+#    #+#             */
/*   Updated: 2014/11/11 04:35:56 by ghilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int len;

	if (!s1 || !s2)
		len = 0;
	else
		len = (ft_strlen(s1) < ft_strlen(s2) ? ft_strlen(s2) : ft_strlen(s1));
	return (ft_strncmp(s1, s2, len));
}
