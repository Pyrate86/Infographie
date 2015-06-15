/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghilbert <ghilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/15 11:31:22 by ghilbert          #+#    #+#             */
/*   Updated: 2015/06/06 19:28:29 by ghilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_tools.h"

int	main(void)
{
	t_env	e;

	init_path(&e);
	e.mlx = mlx_init();
	if (e.mlx == NULL)
		return (-1);
	e.win = mlx_new_window(e.mlx, WIDTH, HEIGHT, "Test MLX");
	e.img = mlx_new_image(e.mlx, WIDTH, HEIGHT);
	e.data = mlx_get_data_addr(e.img, &(e.bpp), &(e.sl), &(e.endian));
	init_str(&e);
	mlx_hook(e.win, KEYPRESS, KEYRELEASE, key_hook, &e);
	mlx_mouse_hook(e.win, mouse_hook, &e);
	mlx_hook(e.win, 6, (1L << 6), mouse_motion, &e);
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}
