/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghilbert <ghilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/15 11:52:32 by ghilbert          #+#    #+#             */
/*   Updated: 2015/04/17 20:29:49 by ghilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_tools.h"

void	draw(t_env *e)
{	
	char	*str;
	char *split;
	str = "Test__avec__rien";
	split = ft_strreplace(str, "_-_", " / ");
	ft_putendl("########");
		ft_putendl(str);
		ft_putendl(split);

	str = "Test_-_avec_-_milieu";
	split = ft_strreplace(str, "_-_", " / ");
	ft_putendl("########");
		ft_putendl(str);
		ft_putendl(split);

	str = "Test_-_avec_-_fin_-_";
	split = ft_strreplace(str, "_-_", " / ");
	ft_putendl("########");
		ft_putendl(str);
		ft_putendl(split);

	str = "_-_Test_-_avec_-_debut";
	split = ft_strreplace(str, "_-_", " / ");
	ft_putendl("########");
		ft_putendl(str);
		ft_putendl(split);
	str = "_-_Test_-_avec_-_debut_-_et_-_fin_-_";
	split = ft_strreplace(str, "_-_", " / ");
	ft_putendl("########");
		ft_putendl(str);
		ft_putendl(split);

	(void)split;
// square.c
	draw_square(e->img, coord(10, 10), coord((WIDTH / 2) - 10, HEIGHT - 10), BLUE);
	draw_fsquare(e->img, coord(30, 30), coord((WIDTH / 2) - 30, HEIGHT - 30), GREEN);

// circle.c
	draw_circle(e->img, coord((WIDTH / 2) / 2, HEIGHT / 2), 100, WHITE);
	draw_fcircle(e->img, coord((WIDTH / 2) / 2, HEIGHT / 2), 50, RED);

// lines.c
	draw_line(e->img, coord((WIDTH / 2) / 2, HEIGHT / 2), coord((WIDTH / 2) - 30, HEIGHT - 30), DARKBLUE);
	draw_line(e->img, coord((WIDTH / 2) / 2, HEIGHT / 2), coord(30, HEIGHT - 30), DARKBLUE);
	draw_hline(e->img, coord((WIDTH / 2) / 2, HEIGHT / 2), (WIDTH / 2) - 30, YELLOW);
	draw_vline(e->img, coord((WIDTH / 2) / 2, HEIGHT / 2), HEIGHT -30, PURPLE);

// img_pixel.c
	mlx_pixel_put_img(e->img, (WIDTH / 2) / 2 - 1, HEIGHT / 2 - 1, BLACK);
	mlx_pixel_put_img(e->img, (WIDTH / 2) / 2, HEIGHT / 2 - 1, BLACK);
	mlx_pixel_put_img(e->img, (WIDTH / 2) / 2 + 1, HEIGHT / 2 - 1, BLACK);

	mlx_pixel_put_img(e->img, (WIDTH / 2) / 2 - 1, HEIGHT / 2, BLACK);
	mlx_pixel_put_img(e->img, (WIDTH / 2) / 2, HEIGHT / 2, BLACK);
	mlx_pixel_put_img(e->img, (WIDTH / 2) / 2 + 1, HEIGHT / 2, BLACK);

	mlx_pixel_put_img(e->img, (WIDTH / 2) / 2 - 1, HEIGHT / 2 + 1, BLACK);
	mlx_pixel_put_img(e->img, (WIDTH / 2) / 2, HEIGHT / 2 + 1, BLACK);
	mlx_pixel_put_img(e->img, (WIDTH / 2) / 2 + 1, HEIGHT / 2 + 1, BLACK);

// img_str.c
	mlx_string_put_img(e, coord(30, HEIGHT - 20 - 30), BLACK, "Black");
	mlx_string_put_img(e, coord(90, HEIGHT - 20 - 30), DARKGREY, "DkGr");
	mlx_string_put_img(e, coord(140, HEIGHT - 20 - 30), GREY, "Grey");
	mlx_string_put_img(e, coord(190, HEIGHT - 20 - 30), LIGHTGREY, "LgGr");
	mlx_string_put_img(e, coord(240, HEIGHT - 20 - 30), WHITE, "White");

// alpha_mask.c
	t_image	*rei;
	char *rei_path;

	rei = (t_image *)malloc(sizeof(t_image));
	rei_path = ft_strjoin(e->img_path, "Rei.XPM");
	rei->img = mlx_xpm_file_to_image (e->mlx,rei_path, &(rei->w), &(rei->h) );
	draw_aplha_mask(e->img, rei, coord((WIDTH / 4 + 30) - rei->w + 15, HEIGHT - 60 - rei->h), PURPLE);

//opacity.c
	draw_opacity(e->img, rei, coord((WIDTH / 4 + 30) + 15, HEIGHT - 60 - rei->h), 0.5);

// luminosity.c
	draw_luminosity(e->img, rei, coord(30 + 15, HEIGHT - 60 - rei->h), 0.5);

	t_image *img;

	img = (t_image *)malloc(sizeof(t_image));
	img->img = e->img;
	img->w = WIDTH / 2;
	img->h = HEIGHT / 2;
	img->data = mlx_get_data_addr(img->img, &(img->bpp), &(img->sl), &(img->end));

	set_luminosity(img, 0.5);


(void)e;
}

void	draw_win(t_env *e)
{
// win_square.c
	draw_win_square(e, coord((WIDTH / 2) + 10, 10), coord(WIDTH - 10, HEIGHT - 10), BLUE);
	draw_win_fsquare(e, coord((WIDTH / 2) + 30, 30), coord(WIDTH - 30, HEIGHT - 30), GREEN);

// win_circle.c
	draw_win_circle(e, coord(3 * (WIDTH / 4), HEIGHT / 2), 100, WHITE);
	draw_win_fcircle(e, coord(3 * (WIDTH / 4), HEIGHT / 2), 50, RED);

// win_line.c
	draw_win_line(e, coord(3 * (WIDTH / 4), HEIGHT / 2), coord(WIDTH /2 + 30, 30), PURPLE);
	draw_win_hline(e, coord(3 * (WIDTH / 4), HEIGHT / 2), (WIDTH / 2) + 30, YELLOW);
	draw_win_vline(e, coord(3 * (WIDTH / 4), HEIGHT / 2), 30, DARKBLUE);

// Pixel

	mlx_pixel_put(e->mlx, e->win, 3 * (WIDTH / 4) - 1, HEIGHT / 2 - 1, BLACK);
	mlx_pixel_put(e->mlx, e->win, 3 * (WIDTH / 4), HEIGHT / 2 - 1, BLACK);
	mlx_pixel_put(e->mlx, e->win, 3 * (WIDTH / 4) + 1, HEIGHT / 2 - 1, BLACK);

	mlx_pixel_put(e->mlx, e->win, 3 * (WIDTH / 4) - 1, HEIGHT / 2, BLACK);
	mlx_pixel_put(e->mlx, e->win, 3 * (WIDTH / 4), HEIGHT / 2, BLACK);
	mlx_pixel_put(e->mlx, e->win, 3 * (WIDTH / 4) + 1, HEIGHT / 2, BLACK);

	mlx_pixel_put(e->mlx, e->win, 3 * (WIDTH / 4) - 1, HEIGHT / 2 + 1, BLACK);
	mlx_pixel_put(e->mlx, e->win, 3 * (WIDTH / 4), HEIGHT / 2 + 1, BLACK);
	mlx_pixel_put(e->mlx, e->win, 3 * (WIDTH / 4) + 1, HEIGHT / 2 + 1, BLACK);

// String
	mlx_string_put(e->mlx, e->win, (3 * (WIDTH / 4) - 17), 40, GREY, "WINDOW");

(void)e;
}