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
		i++;
		free(line);
	}
	close(fd);
	e->maph = nbl;
	e->map = map;
}
