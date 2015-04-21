/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghilbert <ghilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/15 11:31:22 by ghilbert          #+#    #+#             */
/*   Updated: 2015/04/21 15:27:40 by ghilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_tools.h"

int	main(int ac, char **av, char **env)
{
	t_env	e;

	(void)ac;
	(void)av;
	init_path(&e, env);
	e.mlx = mlx_init();
	if (e.mlx == NULL)
		return (-1);
	e.win = mlx_new_window(e.mlx, WIDTH, HEIGHT, "Test MLX");
	e.img = mlx_new_image(e.mlx, WIDTH, HEIGHT);
	e.data = mlx_get_data_addr(e.img, &(e.bpp), &(e.sl), &(e.endian));
	init_str(&e);
	mlx_hook(e.win, 2, 3, key_hook, &e);
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}
