/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghilbert <ghilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/15 11:52:32 by ghilbert          #+#    #+#             */
/*   Updated: 2015/04/22 14:56:42 by ghilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_tools.h"

void	draw(t_env *e)
{	
// square.c
	draw_square(e->img, coord(10, 10), coord((WIDTH / 2) - 10, HEIGHT - 10), BLUE);
	draw_fsquare(e->img, coord(30, 30), coord((WIDTH / 2) - 30, HEIGHT - 30), GREEN);

// circle.c
	t_circle	circle;

	circle.center = coord((WIDTH / 2) / 2, HEIGHT / 2);
	circle.radius = 100;
	draw_circle(e->img, circle, WHITE);
	circle.radius = 50;
	draw_fcircle(e->img, circle, RED);

// lines.c
	draw_line(e->img, coord((WIDTH / 2) / 2, HEIGHT / 2), coord((WIDTH / 2) - 30, HEIGHT - 30), DARKBLUE);
	draw_line(e->img, coord((WIDTH / 2) / 2, HEIGHT / 2), coord(30, HEIGHT - 30), DARKBLUE);
	draw_hline(e->img, coord((WIDTH / 2) / 2, HEIGHT / 2), (WIDTH / 2) - 30, YELLOW);
	draw_vline(e->img, coord((WIDTH / 2) / 2, HEIGHT / 2), HEIGHT -30, PURPLE);

// img_pixel.c
	draw_pixel(e->img, (WIDTH / 2) / 2 - 1, HEIGHT / 2 - 1, BLACK);
	draw_pixel(e->img, (WIDTH / 2) / 2, HEIGHT / 2 - 1, BLACK);
	draw_pixel(e->img, (WIDTH / 2) / 2 + 1, HEIGHT / 2 - 1, BLACK);

	draw_pixel(e->img, (WIDTH / 2) / 2 - 1, HEIGHT / 2, BLACK);
	draw_pixel(e->img, (WIDTH / 2) / 2, HEIGHT / 2, BLACK);
	draw_pixel(e->img, (WIDTH / 2) / 2 + 1, HEIGHT / 2, BLACK);

	draw_pixel(e->img, (WIDTH / 2) / 2 - 1, HEIGHT / 2 + 1, BLACK);
	draw_pixel(e->img, (WIDTH / 2) / 2, HEIGHT / 2 + 1, BLACK);
	draw_pixel(e->img, (WIDTH / 2) / 2 + 1, HEIGHT / 2 + 1, BLACK);

// img_str.c
	draw_str(e, coord(30, HEIGHT - 20 - 30), BLACK, "Black");
	draw_str(e, coord(90, HEIGHT - 20 - 30), DARKGREY, "DkGr");
	draw_str(e, coord(140, HEIGHT - 20 - 30), GREY, "Grey");
	draw_str(e, coord(190, HEIGHT - 20 - 30), LIGHTGREY, "LgGr");
	draw_str(e, coord(240, HEIGHT - 20 - 30), WHITE, "White");

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

// img_polygone.c
	t_coord	*pts;

	pts = (t_coord *)malloc(sizeof(t_coord) * 5);
	pts[0] = coord(70, 40);
	pts[1] = coord(90, 100);
	pts[2] = coord(40, 60);
	pts[3] = coord(100, 60);
	pts[4] = coord(50, 100);
	draw_poly_from_pts(e->img, pts, 5, RED);
	pts[0] = coord(130, 40);
	pts[1] = coord(100, 60);
	pts[2] = coord(110, 100);
	pts[3] = coord(150, 100);
	pts[4] = coord(160, 60);
	draw_fpoly_from_pts(e->img, pts, 5, DARKBLUE);
	
	circle.center = coord(190, 70);
	circle.radius = 30;
	draw_circle(e->img, circle, YELLOW);
	draw_polygone(e->img, circle, 3, PURPLE);
	circle.center = coord(250, 70);
	draw_circle(e->img, circle, RED);
	draw_fpolygone(e->img, circle, 4, BLUE);

// img_rotation
	t_image *rot;

	rot = rotation(e, rei, 90, PURPLE);
	draw_image(e->img, rot, coord(WIDTH / 4 - rei->w / 2, HEIGHT / 4));

}

void	draw_win(t_env *e)
{
// win_square.c
	draw_win_square(e, coord((WIDTH / 2) + 10, 10), coord(WIDTH - 10, HEIGHT - 10), BLUE);
	draw_win_fsquare(e, coord((WIDTH / 2) + 30, 30), coord(WIDTH - 30, HEIGHT - 30), GREEN);

// win_circle.c
		t_circle	circle;
	circle.center = coord(3 * (WIDTH / 4), HEIGHT / 2);
	circle.radius = 100;
	draw_win_circle(e, circle, WHITE);
	circle.radius = 50;
	draw_win_fcircle(e, circle, RED);

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

// win_polygone.c
	t_coord	*pts;

	pts = (t_coord *)malloc(sizeof(t_coord) * 5);
	pts[0] = coord(WIDTH - 70, HEIGHT - 40);
	pts[1] = coord(WIDTH - 90, HEIGHT - 100);
	pts[2] = coord(WIDTH - 40, HEIGHT - 60);
	pts[3] = coord(WIDTH - 100, HEIGHT - 60);
	pts[4] = coord(WIDTH - 50, HEIGHT - 100);
	draw_win_fpoly_from_pts(e, pts, 5, RED);
	pts[0] = coord(WIDTH - 130, HEIGHT - 40);
	pts[1] = coord(WIDTH - 100, HEIGHT - 60);
	pts[2] = coord(WIDTH - 110, HEIGHT - 100);
	pts[3] = coord(WIDTH - 150, HEIGHT - 100);
	pts[4] = coord(WIDTH - 160, HEIGHT - 60);
	draw_win_poly_from_pts(e, pts, 5, DARKBLUE);
	
	circle.center = coord(WIDTH - 190, HEIGHT - 70);
	circle.radius = 30;
	draw_win_circle(e, circle, YELLOW);
	draw_win_fpolygone(e, circle, 3, PURPLE);
	circle.center = coord(WIDTH - 250, HEIGHT - 70);
	draw_win_circle(e, circle, RED);
	draw_win_polygone(e, circle, 4, BLACK);

(void)e;
}