/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghilbert <ghilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/12 10:49:16 by ghilbert          #+#    #+#             */
/*   Updated: 2014/12/12 10:49:29 by ghilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H
# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include "get_next_line.h"
# include "libft.h"
# include <stdio.h>

# define WIDTH 1280
# define HEIGHT 600
# define TEX_WIDTH 64
# define TEX_HEIGHT 64
# define ABS(x) ((x >= 0) ? x : -(x))
# define MAP_FILE "map/char.wolf"
# define MS 0.4
# define RS 0.1

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*data;

	int			bpp;
	int			sl;
	int			endian;

	char		**map;

	int			mapx;
	int			mapy;
	int			mapw;
	int			maph;
	int			x;

	double		posx;
	double		posy;
	double		dirx;
	double		diry;
	double		planx;
	double		plany;

	double		rayposx;
	double		rayposy;
	double		rdirx;
	double		rdiry;
	double		camerax;

	double		sidedistx;
	double		sidedisty;
	double		deltadistx;
	double		deltadisty;
	double		wallh;

	int			stepx;
	int			stepy;
	int			hit;
	int			side;

	int			lineheight;

	int			color;

	int			welcome;

	int			*k_code;
	int			k_input;

	int			showmap;

	int			textured;
	double		t_wallx;
	int			t_x;
	int			w;
	int			h;
	char		*t_file;
	void		*t_img;
	char		*t_data;
	int			t_bpp;
	int			t_sl;
	int			t_edn;
	int			tile_nb;
	int			t_set;
	int			t_posx;
	int			t_posy;
	int			t_select;
	void		*hud_img;
	void		*w_screen;
	int			w_select;
	char		*wp_file;
	void		*weapon;

	void		*sky;
	char		*s_file;
	int			s_w;
	int			s_w_fact;
	int			s_h;
	int			s_bpp;
	int			s_sl;
	int			s_edn;
	char		*s_data;
	int			t_nos;

}				t_env;

typedef struct	s_img
{
	void		*img;
	int			w;
	int			h;
	char		*data;
	int			bpp;
	int			sl;
	int			end;
}				t_img;

typedef struct	s_coord
{
	int			x;
	int			y;
}				t_coord;

void			raycasting(t_env *e);
void			draw_bg(t_env *e);

void			left(t_env *e);
void			right(t_env *e);
void			down(t_env *e);
void			up(t_env *e);

void			draw_map(t_env *e);
void			drawline(void *img_ptr, t_coord a, t_coord b, int color);
void			draw_sqr(void *img_ptr, t_coord a, t_coord b, int color);
void			mlx_pixel_put_img(void *img_ptr, int x, int y, int color);
void			flushscreen(t_env *e);

t_coord			init_coord(int x, int y);

void			get_map(t_env *e);

int				key_hook(int keycode, t_env *e);
int				expose_hook(t_env *e);

void			init_tex(t_env *e);
void			init_world(t_env *e);
void			init_player(t_env *e);
void			init_sprites(t_env *e);

void			hit_wall(t_env *e);
void			color_walls(t_env *e);
void			draw(t_env *e, int start, int end);
void			drawcf(t_env *e, int start, int end);

void			draw_floor(t_env *e);

void			skybox(t_env *e);

void			welcome_dialog(t_env *e);
void			tex_dialog(t_env *e);

void			tex_swap(t_env *e);
void			tex_select(t_env *e);

void			play(t_env *e);

#endif
