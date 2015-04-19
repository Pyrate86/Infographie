/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_tools.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghilbert <ghilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/15 11:28:30 by ghilbert          #+#    #+#             */
/*   Updated: 2015/04/19 21:39:04 by ghilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_TOOLS_H
# define MLX_TOOLS_H

# include <unistd.h>
# include <stdlib.h>

# include <math.h>
# include <limits.h>

# include "keys.h"
# include "colors.h"
# include "mlx.h"

# include "libft.h"

# define WIDTH	640
# define HEIGHT	480

#define max(a,b) \
   ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a > _b ? _a : _b; })

#define min(a,b) \
   ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a < _b ? _a : _b; })

typedef struct	s_image
{
	void		*img;

	int			w;
	int			h;

	char		*data;
	int			bpp;
	int			sl;
	int			end;
}				t_image;

typedef struct	s_coord
{
	int			x;
	int			y;
}				t_coord;

typedef struct	s_circle
{
	t_coord		center;
	int			radius;
}				t_circle;

typedef struct	s_line
{
	t_coord		p1;
	t_coord		p2;
}				t_line;
typedef struct	s_env
{
	char		*exec_path;
	char		*img_path;

	void		*mlx;
	void		*win;

	void		*img;

	char		*data;
	int			bpp;
	int			sl;
	int			endian;

	void		*img_font;
}				t_env;

/*
** hooks.c
*/
int				key_hook(int k, t_env *e);
int				expose_hook(t_env *e);

/*
** draw.c
*/
void			draw(t_env *e);
void			draw_win(t_env *e);

/*
** utils.c
*/
void			swap_coord(t_coord *a, t_coord *b);
t_coord			coord(int x, int y);
int				get_pxl_color(int c);
t_coord				*intersect(t_line l1, t_line l2);

/*
** init_path.c
*/
void			init_path(t_env *e, char **env);

/*
** img_pixel.c
*/
void			mlx_pixel_put_img(void *img, size_t x, size_t y, int color);

/*
** img_str.c
*/
void			init_str(t_env *e);
void			mlx_string_put_img(t_env *e, t_coord a, int color, char *str);

/*
** img_circle.c
*/
void			draw_circle(void *img_ptr, t_circle c, int color);
void			draw_fcircle(void *img_ptr, t_circle c, int color);

/*
** img_lines.c
*/
void			draw_line(void *img_ptr, t_coord a, t_coord b, int color);
void			draw_hline(void *img_ptr, t_coord a, int w, int color);
void			draw_vline(void *img_ptr, t_coord a, int w, int color);

/*
** img_square.c
*/
void			draw_square(void *img_ptr, t_coord a, t_coord b, int color);
void			draw_fsquare(void *img_ptr, t_coord a, t_coord b, int color);

/*
** img_polygone.c
*/
void			draw_poly_from_pts(void *img_ptr, t_coord *pts, int h, int c);
void			draw_fpoly_from_pts(void *img_ptr, t_coord *pts, int h, int c);
void			draw_polygone(void *img_ptr, t_circle c, int h, int color);
void			draw_fpolygone(void *img_ptr, t_circle c, int h, int color);
/*
** win_circle.c
*/
void			draw_win_circle(t_env *e, t_circle c, int color);
void			draw_win_fcircle(t_env *e, t_circle c, int color);

/*
** win_line.c
*/
void			draw_win_line(t_env *e, t_coord a, t_coord b, int color);
void			draw_win_hline(t_env *e, t_coord a, int w, int color);
void			draw_win_vline(t_env *e, t_coord a, int w, int color);

/*
** win_square.c
*/
void			draw_win_square(t_env *e, t_coord a, t_coord b, int color);
void			draw_win_fsquare(t_env *e, t_coord a, t_coord b, int color);

/*
** alpha_mask.c
*/
void			draw_aplha_mask(void *img_bg, t_image *fg, t_coord tl, int c);

/*
** opacity.c
*/
void			draw_opacity(void *img_bg, t_image *fg, t_coord tl, float op);

/*
** luminosity.c
*/
void			draw_luminosity(void *img_bg, t_image *fg, t_coord t, float l);
void			set_luminosity(t_image *img, float lum);
#endif
