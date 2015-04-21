/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghilbert <ghilbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/16 15:12:09 by ghilbert          #+#    #+#             */
/*   Updated: 2015/04/21 14:49:23 by ghilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_tools.h"

void	init_path(t_env *e, char **env)
{
	int		i;
	char	**tmp;
	char	*path;
	char	*exec;
	char	*img;

	i = 0;
	while (!(env[i][0] == '_' && env[i][1] == '='))
		i++;
	tmp = ft_strsplit(env[i], '=');
	tmp = ft_strsplit(tmp[1], '/');
	i = 0;
	path = tmp[0][0] == '.' ? tmp[i++] : "";
	while (tmp[i + 1])
	{
		path = ft_strjoin(path, "/");
		path = ft_strjoin(path, tmp[i]);
		i++;
	}
	exec = ft_strjoin(path, FONT_PATH);
	img = ft_strjoin(path, IMG_PATH);
	e->exec_path = exec;
	e->img_path = img;
}
