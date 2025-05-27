/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 19:49:58 by flima             #+#    #+#             */
/*   Updated: 2025/05/27 17:13:49 by flima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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
	free(texture->NO);
	free(texture->SO);
	free(texture->WE);
	free(texture->EA);
	free(texture);
}

void	free_all_data(t_cub_data *data)
{
	free_double(data->wholemap);
	free_map(data->map_info);
	free_colors(data->colours);
	free_textures(data->texture);
	free(data);
}