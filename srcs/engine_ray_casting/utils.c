/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yulpark <yulpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 21:26:09 by flima             #+#    #+#             */
/*   Updated: 2025/06/28 19:15:53 by yulpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	set_direction(t_rayEngine *engine, t_map *mmap)
{
	char		dir;

	dir = mmap->map_grid[mmap->player_row][mmap->player_col];
	if (dir == 'S')
	{
		rotatevetor(&engine->dir, PI);
		rotatevetor(&engine->planecamera, PI);
	}
	else if (dir == 'E')
	{
		rotatevetor(&engine->dir, PI / 2);
		rotatevetor(&engine->planecamera, PI / 2);
	}
	else if (dir == 'W')
	{
		rotatevetor(&engine->dir, -PI / 2);
		rotatevetor(&engine->planecamera, -PI / 2);
	}
}

void	game_settings(t_cub_data *data)
{
	init_vetors(data->engine, data->map_info);
	set_direction(data->engine, data->map_info);
}
