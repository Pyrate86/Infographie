/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_tools.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghilbert <ghilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/15 11:28:30 by ghilbert          #+#    #+#             */
/*   Updated: 2015/04/20 23:25:28 by ghilbert         ###   ########.fr       */
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
# include "structs.h"
# include "mlx.h"

# include "libft.h"

# define WIDTH	640
# define HEIGHT	480

# define MIN(x, y) (x < y ? x : y)
# define MAX(x, y) (x > y ? x : y)

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
** ft_maths.c
*/
t_coord			get_max(t_coord a, t_coord b);
t_coord			get_min(t_coord a, t_coord b);
/*
** utils.c
*/
void			swap_coord(t_coord *a, t_coord *b);
t_coord			coord(int x, int y);
int				get_pxl_color(int c);
t_box			boxing(t_coord a, t_coord b);
t_line			line(t_coord a, t_coord b);

/*
** intersect.c
*/
int				intersect(t_line a, t_line b);

/*
** init_path.c
*/
void			init_path(t_env *e, char **env);

/*
** img_pixel.c
*/
void			draw_pixel(void *img, size_t x, size_t y, int color);

/*
** img_str.c
*/
void			init_str(t_env *e);
void			draw_str(t_env *e, t_coord a, int color, char *str);

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
