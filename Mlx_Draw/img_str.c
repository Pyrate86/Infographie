/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghilbert <ghilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/15 15:24:42 by ghilbert          #+#    #+#             */
/*   Updated: 2015/04/15 16:24:57 by ghilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_tools.h"

void	init_str(t_env *e)
{
	int width, height;

	e->char_sheet = mlx_xpm_file_to_image (e->mlx,"./includes/font.xpm", &width, &height );
}

static void	draw_char(t_env *e, t_coord a, int color, char c)
{
	(void)e;
	(void)a;
	(void)color;
	(void)c;

	int		i;
	int		j;
	int		k;
	int		l;

	char	*data;
	int		bbp;
	int		sizeline;
	int		endian;

	data = mlx_get_data_addr(e->char_sheet, &bbp, &sizeline, &endian);
	bbp /= 8;

	i = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 20)
		{
			k = (i * (c - 32)) * bbp + j * sizeline;

			l = a.x * e->bpp + a.y * e->sl;

			e->data[l] = data[k];
			e->data[l + 1] = data[k + 1];
			e->data[l + 2] = data[k + 2];

			j++;
		}
		i++;
	}

}

void	mlx_string_put_img(t_env *e, t_coord a, int color, char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 32)
			draw_char(e, coord(a.x + (i * 10), a.y), color, str[i]);
		i++;
	}
}
