/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture_from_map.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yulpark <yulpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 16:24:25 by yulpark           #+#    #+#             */
/*   Updated: 2025/06/23 15:51:40 by yulpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static t_errno grep_texture(t_cub_data *data, t_texture *texture, char *position)
{
	int	i;
	char **texture_line;

	i = -1;
	while (data->wholemap[++i])
	{
		if (ft_strncmp(data->wholemap[i], position, 3) == 0)
		{
			if (texture->path == NULL)
			{
				texture_line = ft_split(data->wholemap[i], ' ');
				if (!texture_line)
					return (ERR_MEM_ALLOC);
				texture->path = texture_line[1];
				texture->path[ft_strlen(texture->path) - 1] = '\0';
			}
			else
				return (ERR_DUPLICATE);
		}
	}
	return (SUCCESS);
}

t_errno grep_texture_all(t_cub_data *data)
{
	int	errno;

	errno = grep_texture(data, &data->texture[EA], "EA ");
	if (errno != SUCCESS)
		return (errno);
	errno = grep_texture(data, &data->texture[NO], "NO ");
	if (errno != SUCCESS)
		return (errno);
	errno = grep_texture(data, &data->texture[SO], "SO ");
	if (errno != SUCCESS)
		return (errno);
	errno = grep_texture(data, &data->texture[WE], "WE ");
	if (errno != SUCCESS)
		return (errno);
	if (data->texture[NO].path == NULL || data->texture[SO].path == NULL
		|| data->texture[WE].path == NULL || data->texture[EA].path == NULL)
			return (ERR_MISSING_MAP_ELEMENT);
	return (SUCCESS);
}
