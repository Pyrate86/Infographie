/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghilbert <ghilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 02:29:26 by ghilbert          #+#    #+#             */
/*   Updated: 2015/01/13 02:29:52 by ghilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	gnl_save(char **line, char *buff, char *save)
{
	int	i;
	int	j;

	i = 0;
	j = ft_strlen(*line);
	line[0] = ft_realloc(*line, (ft_strlen(*line) + ft_strlen(buff) + 1));
	while (buff[i])
	{
		if (buff[i] == '\n')
		{
			line[0][j] = '\0';
			i++;
			save = ft_strcpy(save, &buff[i]);
			return (1);
		}
		line[0][j] = buff[i];
		i++;
		j++;
	}
	ft_bzero(save, ft_strlen(save));
	line[0][j] = '\0';
	return (0);
}

static void	free_mem(char *tmp, char *buff)
{
	free(tmp);
	free(buff);
}

static int	endline(char **line, char *tmp, char *buff)
{
	*line = ft_strdup(tmp);
	free_mem(tmp, buff);
	return (1);
}

static int	endfile(char **line, char *tmp, char *buff)
{
	*line = ft_strdup(tmp);
	free_mem(tmp, buff);
	if (*line[0] == '\0')
		return (0);
	return (1);
}

int			get_next_line(int const fd, char **line)
{
	static char	save[500][BUFF_SIZE];
	char		*buff;
	char		*tmp;
	int			ret;

	if (fd < 0)
		return (-1);
	buff = ft_strnew(BUFF_SIZE);
	tmp = ft_strnew(BUFF_SIZE);
	if (!buff || !tmp)
		return (-1);
	if (gnl_save(&tmp, save[fd], save[fd]) == 1)
		return (endline(line, tmp, buff));
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if (gnl_save(&tmp, buff, save[fd]) == 1)
			return (endline(line, tmp, buff));
	}
	if (ret == -1)
		return (-1);
	if (ret == 0 && tmp[0] != '\0')
		return (endfile(line, tmp, buff));
	free_mem(tmp, buff);
	return (0);
}
