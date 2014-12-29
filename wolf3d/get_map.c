/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghilbert <ghilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/15 03:30:53 by ghilbert          #+#    #+#             */
/*   Updated: 2014/12/15 03:31:08 by ghilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static int	get_nbline(void)
{
	int		fd;
	int		nbl;
	char	*line;

	nbl = 0;
	fd = open(MAP_FILE, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		nbl++;
		free(line);
	}
	close(fd);
	return (nbl);
}

void		get_map(t_env *e)
{
	int		fd;
	int		nbl;
	char	**map;
	char	*line;
	int		i;

	nbl = get_nbline();
	map = (char **)malloc(sizeof(char *) * (nbl + 1));
	i = 0;
	fd = open(MAP_FILE, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		map[i] = ft_strdup(line);
		i++;
		free(line);
	}
	map[i] = NULL;
	close(fd);
	e->maph = nbl;
	e->mapw = ft_strlen(map[0]);
	e->map = map;
}
