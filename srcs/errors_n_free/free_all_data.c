/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yulpark <yulpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 19:49:58 by flima             #+#    #+#             */
/*   Updated: 2025/06/28 19:19:19 by yulpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	free_double(char **s)
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
	free(map->calc);
	free(map->player_info);
	free(map);
}

static void	free_colors(t_colours *color)
{
	free(color->f_colour_str);
	free(color->c_colour_str);
	free(color);
}

void	free_all_data(t_cub_data *data)
{
	clean_game_window(data);
	free_double(data->wholemap);
	free_map(data->map_info);
	free_colors(data->colours);
	free(data->engine->dda);
	free(data->img);
	free(data->engine);
}
