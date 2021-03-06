/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_tools.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghilbert <ghilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/06 15:42:43 by ghilbert          #+#    #+#             */
/*   Updated: 2015/06/06 19:58:14 by ghilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_TOOLS_H
# define MLX_TOOLS_H

# include "includes.h"

/*
** hooks.c
*/
int				key_hook(int k, t_env *e);
int				expose_hook(t_env *e);
int				mouse_hook(int button, int x, int y, t_env *e);
int				mouse_motion(int x, int y, t_env *e);

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
void			init_path(t_env *e);

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
** img_image
*/
void			draw_image(void *img_bg, t_image *fg, t_coord t);

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
** img_rotation.c
*/
t_image			*rotation(t_env *e, t_image *img, int angle, int color);

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
** win_polygone.c
*/
void			draw_win_poly_from_pts(t_env *e, t_coord *pts, int h, int c);
void			draw_win_fpoly_from_pts(t_env *e, t_coord *pts, int h, int c);
void			draw_win_polygone(t_env *e, t_circle c, int h, int color);
void			draw_win_fpolygone(t_env *e, t_circle c, int h, int color);

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
