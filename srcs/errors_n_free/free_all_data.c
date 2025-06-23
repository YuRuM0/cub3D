/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yulpark <yulpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 19:49:58 by flima             #+#    #+#             */
/*   Updated: 2025/06/23 16:29:30 by yulpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void free_double(char **s)
{
	int	i;

	i = 0;
	if (s == NULL)
		return ;
	while (s[i])
		free(s[i++]);
	free(s);
}

static void	free_map(t_map *map)
{
	free_double(map->map_grid);
	free(map);
}

static void	free_colors(t_colours *color)
{
	free(color->f_colour_str);
	free(color->c_colour_str);
	free(color);
}

static void	free_textures(t_texture *texture)
{
	//delete texture and image!
	free(texture);
}

void	free_all_data(t_cub_data *data)
{
	free_double(data->wholemap);
	free_map(data->map_info);
	free_colors(data->colours);
	free_textures(data->texture);
	free(data->engine->dda);
	free(data->engine);
	free(data);
}
