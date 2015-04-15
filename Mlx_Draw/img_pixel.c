/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghilbert <ghilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/15 13:29:51 by ghilbert          #+#    #+#             */
/*   Updated: 2015/04/15 14:32:23 by ghilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_tools.h"

void	mlx_pixel_put_img(void *img, size_t x, size_t y, int color)
{
	char	*data;
	int		bbp;
	int		sizeline;
	int		endian;
	int		i;

	data = mlx_get_data_addr(img, &bbp, &sizeline, &endian);
	bbp /= 8;
	i = x * bbp + y * sizeline;
	if (WIDTH * bbp + HEIGHT * sizeline < i)
		return ;
	data[i] = color;
	data[i + 1] = color >> 8;
	data[i + 2] = color >> 16;
}
