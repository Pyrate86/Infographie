/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghilbert <ghilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/30 04:14:08 by ghilbert          #+#    #+#             */
/*   Updated: 2014/12/30 04:14:18 by ghilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **av)
{
	t_env	e;

	if (ac == 2)
	{
		e.mlx = mlx_init();
		if (e.mlx == NULL)
			return (-1);
		e.win = mlx_new_window(e.mlx, WIDTH, HEIGHT, "FdF");
		e.img = mlx_new_image(e.mlx, WIDTH, HEIGHT);
		e.data = mlx_get_data_addr(e.img, &(e.bpp), &(e.sl), &(e.endian));
		e.file = av[1];
		init(&e);
		mlx_hook(e.win, 2, 3, key_hook, &e);
		mlx_expose_hook(e.win, expose_hook, &e);
		mlx_loop(e.mlx);
	}
	return (0);
}
