/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghilbert <ghilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/14 00:52:02 by ghilbert          #+#    #+#             */
/*   Updated: 2014/12/14 00:52:04 by ghilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <sys/wait.h>
# include <signal.h>

# include "mlx.h"
# include "libft.h"

# include <stdio.h>

# define WIDTH 640
# define HEIGHT 640

# define MAX(a, b) (((a) > (b)) ? (a) : (b))
# define ABS(x) (((x) < 0) ? -(x) : (x))

# define SQRT_3  1.732

typedef struct	s_coord
{
	int			x;
	int			y;
}				t_coord;

typedef struct	s_complexe
{
	double		reel;
	double		imag;
}				t_complexe;

typedef struct	s_color
{
	int			r;
	int			g;
	int			b;
	size_t		hexa;
}				t_color;

typedef struct	s_fractale
{
	double		zoom;
	double		x1;
	double		y1;
	double		x2;
	double		y2;
	double		c_r;
	double		c_i;
	double		z_r;
	double		z_i;
	double		m_iter;
	double		iter_factor;
}				t_frac;

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	void		*img;
	t_frac		*frac;
	char		*file;
	int			motion;
	int			info;
	int			help;
	int			init;
	void		*load_img;
}				t_env;

void			draw(t_env *e);

void			mlx_pixel_put_img(void *img, size_t x, size_t y, int color);
void			drawline(void *img_ptr, t_coord a, t_coord b, int color);
void			draw_sqr(void *img_ptr, t_coord a, t_coord b, int color);
void			draw_sqr_to_win(t_env *e, t_coord a, t_coord b, int color);

double			torad(int a);
double			modulus(double a, double b);

void			assign(t_color *c, size_t c1, size_t c2, size_t c3);
void			hsvtorgb(t_color *c, size_t h, size_t s, size_t v);

void			zoom(t_frac *frac, int x, int y);
void			unzoom(t_frac *frac, int x, int y);

void			show_percent(t_env *e, int x);

void			mandelbrot(t_env *e);
void			julia(t_env *e);
void			third(t_env *e);
void			show_help(t_env *e);
void			show_infos(t_env *e);

int				key_hook(int keycode, t_env *e);
int				mouse_hook(int button, int x, int y, t_env *e);
int				mouse_motion(int x, int y, t_env *e);
int				expose_hook(t_env *e);

#endif
