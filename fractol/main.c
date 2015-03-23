/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghilbert <ghilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/14 00:44:07 by ghilbert          #+#    #+#             */
/*   Updated: 2014/12/14 00:44:10 by ghilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	help(void)
{
	ft_putendl("Usage :");
	ft_putendl("fractol <fractal type>");
	ft_putendl("\nTypes :");
	ft_putendl("mandelbrot\tMandelbrot set");
	ft_putendl("julia\t\tJulia set");
	ft_putendl("third\t\tThird set");
}

static int	check_arg(int ac, char **av)
{
	if (ac == 2)
	{
		if (!ft_strcmp(av[1], "mandelbrot")
		|| !ft_strcmp(av[1], "julia")
		|| !ft_strcmp(av[1], "third"))
		{
			return (1);
		}
	}
	if (ac > 2)
	{
		ft_putendl("Too many arguments");
	}
	return (0);
}

t_env		init_env(t_env e, char *name)
{
	e.mlx = mlx_init();
	if (!e.mlx)
	{
		ft_putendl("Error : mlx_init() failed");
		exit(-1);
	}
	e.win = mlx_new_window(e.mlx, WIDTH, HEIGHT, name);
	e.img = mlx_new_image(e.mlx, WIDTH, HEIGHT);
	e.load_img = mlx_new_image(e.mlx, WIDTH, 3);
	e.motion = 0;
	e.info = 0;
	e.help = 1;
	e.init = 0;
	return (e);
}

int			main(int ac, char **av)
{
	t_env	e;

	if (check_arg(ac, av))
	{
		e = init_env(e, av[1]);
		e.file = av[1];
		mlx_key_hook(e.win, key_hook, &e);
		mlx_expose_hook(e.win, expose_hook, &e);
		mlx_mouse_hook(e.win, mouse_hook, &e);
		mlx_hook(e.win, 6, (1L << 6), mouse_motion, &e);
		mlx_loop(e.mlx);
		mlx_destroy_image(e.mlx, e.img);
		mlx_destroy_window(e.mlx, e.win);
	}
	else
		help();
	return (0);
}
