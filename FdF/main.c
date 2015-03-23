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

static void	help(void)
{
	ft_putendl("Usage :");
	ft_putendl("fdf [-l] map_path");
	ft_putendl("\n-l\tAffichage du chargement de la map");
}

static int	get_arg(t_env *e, char **av)
{
	ft_putstr(av[1]);
	if (ft_strcmp(av[1], "-l") != 0)
		return (0);
	e->loading = 1;
	return (1);
}

int	main(int ac, char **av)
{
	t_env	e;

	if (ac == 2 || ac == 3)
	{
		e.mlx = mlx_init();
		if (e.mlx == NULL)
			return (-1);
		e.win = mlx_new_window(e.mlx, WIDTH, HEIGHT, "FdF");
		e.img = mlx_new_image(e.mlx, WIDTH, HEIGHT);
		e.data = mlx_get_data_addr(e.img, &(e.bpp), &(e.sl), &(e.endian));
		e.file = av[1 + e.loading];
		init(&e);
		if (ac == 3)
			if (get_arg(&e, av) == 0)
			{
				help();
				return (0);
			}
		mlx_hook(e.win, 2, 3, key_hook, &e);
		mlx_expose_hook(e.win, expose_hook, &e);
		mlx_loop(e.mlx);
	}
	else
		help();
	return (0);
}
