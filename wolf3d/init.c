/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghilbert <ghilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/29 02:04:45 by ghilbert          #+#    #+#             */
/*   Updated: 2014/12/29 02:04:55 by ghilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	init_tex(t_env *e)
{
	e->t_img = mlx_xpm_file_to_image(e->mlx, e->t_file, &e->w, &e->h);
	e->t_data = mlx_get_data_addr(e->t_img, &e->t_bpp, &e->t_sl, &e->t_edn);
	e->sky = mlx_xpm_file_to_image (e->mlx, e->s_file, &e->s_w, &e->s_h);
	e->s_data = mlx_get_data_addr (e->sky, &e->s_bpp, &e->s_sl, &e->s_edn);
 	e->s_w_fact = e->s_w / 200;
}

void	init_player(t_env *e)
{
	e->posx = 1.5;
	e->posy = 1.5;
	e->dirx = 1;
	e->diry = 0;
	e->planx = 0;
	e->plany = -0.66;
}

void	init_world(t_env *e)
{
	e->textured = 0;
	e->t_set = 2;
	e->t_nos = 2;
	e->t_file = "./img/tilemaps/2.xpm";
	e->s_file = "./img/skybox/2.xpm";
	e->t_posx = 9;
	e->t_posy = 6;
	e->k_code = (int *)malloc(sizeof(int) * 11);
	e->k_code[0] = 65362;
	e->k_code[1] = 65362;
	e->k_code[2] = 65364;
	e->k_code[3] = 65364;
	e->k_code[4] = 65361;
	e->k_code[5] = 65363;
	e->k_code[6] = 65361;
	e->k_code[7] = 65363;
	e->k_code[8] = 98;
	e->k_code[9] = 97;
	e->k_code[10] = 65293;
	e->k_input = 0;
}