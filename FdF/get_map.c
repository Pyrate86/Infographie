/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghilbert <ghilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/01 02:45:35 by ghilbert          #+#    #+#             */
/*   Updated: 2015/01/01 02:45:49 by ghilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	show_lnbr(t_env *e, int x)
{
	char	*nb;
	char	*txt;
	int		txt_sz;
	int		nb_sz;

	txt = "Lecture de la map";
	nb = ft_itoa(x);
	txt_sz = ft_strlen(txt);
	txt_sz = (WIDTH / 2) - ((txt_sz * 10) / 2);
	nb_sz = ft_strlen(nb);
	nb_sz = (WIDTH / 2) - ((nb_sz * 10) / 2);
	mlx_clear_window(e->mlx, e->win);
	mlx_string_put(e->mlx, e->win, nb_sz, 15, 0x007FFF, nb);
	mlx_string_put(e->mlx, e->win, txt_sz, 00, 0x007FFF, txt);
	mlx_do_sync(e->mlx);
}

static void	show_percent(t_env *e, int x, int total)
{
	char	*txt;
	char	*nb;
	int		txt_sz;
	int		nb_sz;

	txt = "Chargement de la map";
	txt_sz = ft_strlen(txt);
	nb = ft_strjoin(ft_itoa(x), " / ");
	nb = ft_strjoin(nb, ft_itoa(total));
	nb = ft_strjoin(nb, " ( ");
	nb = ft_strjoin(nb, ft_itoa((x * 100) / total));
	nb = ft_strjoin(nb, " %)");
	nb_sz = ft_strlen(nb);
	mlx_clear_window(e->mlx, e->win);
	mlx_string_put(e->mlx, e->win, 0, 0, 0X7FFF00, txt);
	mlx_string_put(e->mlx, e->win, 0, 15, 0x7FFF00, nb);
	mlx_do_sync(e->mlx);
}

static int	get_nbline(t_env *e)
{
	int		fd;
	int		nbl;
	char	*line;

	nbl = 0;
	fd = open(e->file, O_RDONLY);
	if (fd < 0)
		return (0);
	while (get_next_line(fd, &line) > 0)
	{
		nbl++;
		if ((nbl % 100 == 0) && (e->loading == 1))
			show_lnbr(e, nbl);
		free(line);
	}
	close(fd);
	return (nbl + 1);
}

int			*get_int(t_env *e, char *line)
{
	char	**tab;
	int		*intline;
	int		length;
	int		i;

	i = 1;
	length = 0;
	tab = ft_strsplit(line, ' ');
	while (tab[length])
		length++;
	intline = (int *)malloc(sizeof(int *) * (length + 1));
	intline[0] = length;
	while (i <= length)
	{
		intline[i] = ft_atoi(tab[i - 1]);
		e->min = intline[i] < e->min ? intline[i] : e->min;
		e->max = intline[i] > e->max ? intline[i] : e->max;
		free(tab[i - 1]);
		i++;
	}
	e->mapw = e->mapw > i ? e->mapw : i;
	free(tab);
	return (intline);
}

void		get_map(t_env *e)
{
	int		fd;
	int		nbl;
	int		**map;
	char	*line;
	int		i;

	e->mapw = 0;
	nbl = get_nbline(e);
	map = (int **)malloc(sizeof(int *) * (nbl + 1));
	i = 1;
	fd = open(e->file, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		map[i] = get_int(e, line);
		if ((i % (nbl > 10000 ? 1000 : 10) == 0) && (e->loading == 1))
			show_percent(e, i, nbl);
		i++;
		free(line);
	}
	close(fd);
	e->maph = nbl;
	e->map = map;
}
