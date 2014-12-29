/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghilbert <ghilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/15 03:30:32 by ghilbert          #+#    #+#             */
/*   Updated: 2014/12/15 03:30:43 by ghilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	tex_swap(t_env *e)
{
	char	*file;

	e->t_set++;
	if (e->t_set > e->t_nos)
		e->t_set = 0;
	file = ft_strjoin("./img/tilemaps/", ft_itoa(e->t_set));
	file = ft_strjoin(file, ".xpm");
	e->t_file = file;
	file = ft_strjoin("./img/skybox/", ft_itoa(e->t_set));
	file = ft_strjoin(file, ".xpm");
	e->s_file = file;
	e->t_posx = 0;
	e->t_posy = 0;
	init_tex(e);
}

void	move(t_env *e, int k)
{
	if (k == 65361)
		left(e);
	else if (k == 65363)
		right(e);
	else if (k == 65362)
		up(e);
	else if (k == 65364)
		down(e);
}

int		key_hook(int k, t_env *e)
{
	if (k == 65307)
		exit(0);
	else if (k == 65361 || k == 65363 || k == 65362 || k == 65364)
		move(e, k);
	else if (k == 96)
		e->textured = e->textured == 0 ? 1 : 0;
	if (k == e->k_code[e->k_input])
	{
		e->k_input++;
		if (e->k_input > 10)
		{
			tex_swap(e);
			e->k_input = 0;
		}
	}
	else
		e->k_input = 0;
	draw_bg(e);
	raycasting(e);
	draw_map(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	
int w, h;
void	*fling = mlx_xpm_file_to_image (e->mlx, "img/tilemaps/1.xpm", &w, &h);
mlx_put_image_to_window(e->mlx, e->win, fling, 100, 100);

	return (k);
}

int		expose_hook(t_env *e)
{
	e->x = 0;
	draw_bg(e);
	raycasting(e);
	draw_map(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);

int w, h;
void	*fling = mlx_xpm_file_to_image (e->mlx, "img/tilemaps/1.xpm", &w, &h);
mlx_put_image_to_window(e->mlx, e->win, fling, 100, 100);

	return (0);
}
