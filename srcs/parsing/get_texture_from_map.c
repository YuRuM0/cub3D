/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture_from_map.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 16:24:25 by yulpark           #+#    #+#             */
/*   Updated: 2025/06/23 19:20:37 by flima            ###   ########.fr       */
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
				texture->path = ft_strdup(texture_line[1]);
				texture->path[ft_strlen(texture->path) - 1] = '\0';
				free_double(texture_line);
			}
			else
				return (ERR_DUPLICATE);
		}
	}
	return (SUCCESS);
}

t_errno grep_texture_all(t_cub_data *data)
{
	int	errnoo;

	errnoo = grep_texture(data, &data->texture[EA], "EA ");
	if (errnoo != SUCCESS)
		return (errnoo);
	errnoo = grep_texture(data, &data->texture[NO], "NO ");
	if (errnoo != SUCCESS)
		return (errnoo);
	errnoo = grep_texture(data, &data->texture[SO], "SO ");
	if (errnoo != SUCCESS)
		return (errnoo);
	errnoo = grep_texture(data, &data->texture[WE], "WE ");
	if (errnoo != SUCCESS)
		return (errnoo);
	if (data->texture[NO].path == NULL || data->texture[SO].path == NULL
		|| data->texture[WE].path == NULL || data->texture[EA].path == NULL)
			return (ERR_MISSING_MAP_ELEMENT);
	return (SUCCESS);
}
