/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghilbert <ghilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/20 23:08:41 by ghilbert          #+#    #+#             */
/*   Updated: 2015/04/20 23:53:32 by ghilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct	s_image
{
	void		*img;

	int			w;
	int			h;

	char		*data;
	int			bpp;
	int			sl;
	int			end;
}				t_image;

typedef struct	s_coord
{
	int			x;
	int			y;
}				t_coord;

typedef struct	s_circle
{
	t_coord		center;
	int			radius;
}				t_circle;

typedef struct	s_line
{
	t_coord		p1;
	t_coord		p2;
}				t_line;

typedef struct	s_box
{
	int			x;
	int			y;
	int			w;
	int			h;
}				t_box;

typedef struct	s_env
{
	char		*exec_path;
	char		*img_path;

	void		*mlx;
	void		*win;

	void		*img;

	char		*data;
	int			bpp;
	int			sl;
	int			endian;

	void		*img_font;
}				t_env;

#endif
