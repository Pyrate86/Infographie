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

void	move_player(t_env *e, int k)
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

void	move(t_env *e, int k)
{
	if (e->welcome == 1)
	{
		if (k == 65362 || k == 65364)
			e->w_select = e->w_select == 0 ? 1 : 0;
	}
	else if (e->t_select == 1)
	{
		if (k == 65364)
		{
			e->t_set++;
			if (e->t_set > e->t_nos)
				e->t_set = 0;
		}
		else if (k == 65362)
		{
			e->t_set--;
			if (e->t_set < 0)
				e->t_set = e->t_nos;
		}
	}
	else
		move_player(e, k);
}

void	enter(t_env *e)
{
	e->welcome = 0;
	if (e->w_select == 1)
		exit (0);
	if (e->t_select == 1)
	{
		tex_swap(e);
		e->t_select = 0;
	}
}

int		key_hook(int k, t_env *e)
{
	if (k == 65307)
		exit(0);
	else if (k == 65361 || k == 65363 || k == 65362 || k == 65364)
		move(e, k);
	else if (k == 109)
		e->showmap = e->showmap == 0 ? 1 : 0;
	else if (k == 65293)
		enter(e);
	if (k == e->k_code[e->k_input])
	{
		e->k_input++;
		if (e->k_input > 10)
		{
			tex_select(e);
			e->k_input = 0;
		}
	}
	else
		e->k_input = 0;
	play(e);
	return (k);
}

int		expose_hook(t_env *e)
{
	e->x = 0;
	play(e);
	return (0);
}
