/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghilbert <ghilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/15 11:52:32 by ghilbert          #+#    #+#             */
/*   Updated: 2015/04/16 12:10:26 by ghilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_tools.h"

void	draw(t_env *e)
{
// square.c
	draw_square(e->img, coord(10, 10), coord((WIDTH / 2) - 10, HEIGHT - 10), BLUE);
	draw_fsquare(e->img, coord(30, 30), coord((WIDTH / 2) - 30, HEIGHT - 30), GREEN);

// circle.c
	draw_circle(e->img, coord((WIDTH / 2) / 2, HEIGHT / 2), 100, WHITE);
	draw_fcircle(e->img, coord((WIDTH / 2) / 2, HEIGHT / 2), 50, RED);

// lines.c
	draw_line(e->img, coord((WIDTH / 2) / 2, HEIGHT / 2), coord((WIDTH / 2) - 30, HEIGHT -30), PURPLE);
	draw_hline(e->img, coord((WIDTH / 2) / 2, HEIGHT / 2), (WIDTH / 2) - 30, YELLOW);
	draw_vline(e->img, coord((WIDTH / 2) / 2, HEIGHT / 2), HEIGHT -30, DARKBLUE);

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
	// mlx_string_put_img(e, coord(((WIDTH / 4) - 17), HEIGHT - 40), GREY, "IMAGES");
	mlx_string_put_img(e, coord(40, 30), BLACK, "Test");
	mlx_string_put_img(e, coord(90, 30), DARKGREY, "Test");
	mlx_string_put_img(e, coord(140, 30), GREY, "Test");
	mlx_string_put_img(e, coord(190, 30), LIGHTGREY, "Test");
	mlx_string_put_img(e, coord(240, 30), WHITE, "Test");

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