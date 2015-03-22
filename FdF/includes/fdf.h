/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghilbert <ghilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/30 04:14:27 by ghilbert          #+#    #+#             */
/*   Updated: 2014/12/30 04:17:59 by ghilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>

# include "get_next_line.h"
# include "libft.h"

# define WIDTH 1000
# define HEIGHT 1000

typedef struct	s_coord
{
	int			x;
	int			y;
}				t_coord;

typedef struct	s_color
{
	int			r;
	int			g;
	int			b;
	size_t		hexa;
}				t_color;

typedef struct	s_env
{
	void		*mlx;
	void		*win;

	void		*img;

	char		*data;
	int			bpp;
	int			sl;
	int			endian;

	int			img_w;
	int			img_h;

	char		*file;

	int			getmap;
	int			**map;
	int			mapw;
	int			maph;
	int			min;
	int			max;
	int			height;

	int			tile_size;

	t_coord		interval;
}				t_env;

void			init(t_env *e);

void			mlx_pixel_put_img(void *img_ptr, int x, int y, int color);
void			swap_coord(t_coord *a, t_coord *b);
void			draw_sqr(void *img_ptr, t_coord a, t_coord b, int color);
void			flushscreen(t_env *e);
unsigned int	color_from_height(int height);

void			drawline(void *img_ptr, t_coord a, t_coord b, int height);

int				key_hook(int k, t_env *e);
int				expose_hook(t_env *e);

void			get_map(t_env *e);

void			fdf(t_env *e);

void			hsvtorgb(t_color *c, size_t h, size_t s, size_t v);

#endif
