/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghilbert <ghilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/31 04:06:23 by ghilbert          #+#    #+#             */
/*   Updated: 2014/12/31 04:06:34 by ghilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	tex_floor(t_env *e)
{
	if (e->t_set == 1)
	{
		e->t_posx = 0;
		e->t_posy = 0;
	}
	else if (e->t_set == 2)
	{
		e->t_posx = 9;
		e->t_posy = 0;
	}
	else if (e->t_set == 3)
	{
		e->t_posx = 9;
		e->t_posy = 6;
	}
}

void	tex_swap(t_env *e)
{
	char	*file;

	if (e->t_set == 0)
		e->textured = 0;
	else
	{
		e->textured = 1;
		file = ft_strjoin("./img/tilemaps/", ft_itoa(e->t_set));
		file = ft_strjoin(file, ".xpm");
		e->t_file = file;
		file = ft_strjoin("./img/skybox/", ft_itoa(e->t_set));
		file = ft_strjoin(file, ".xpm");
		e->s_file = file;
		file = ft_strjoin("./img/weapon/", ft_itoa(e->t_set));
		file = ft_strjoin(file, ".xpm");
		e->wp_file = file;
		tex_floor(e);
		init_tex(e);
	}
}

void	tex_select(t_env *e)
{
	e->t_select = 1;
}
