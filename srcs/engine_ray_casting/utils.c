/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 21:26:09 by flima             #+#    #+#             */
/*   Updated: 2025/06/21 21:28:44 by flima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	set_direction(t_rayEngine *engine, t_map *mmap)
{
	char		dir;
	
	dir = mmap->map_grid[mmap->player_row][mmap->player_col];
	if (dir == 'S')
	{
		rotateVetor(&engine->dir, PI);
		rotateVetor(&engine->planeCamera, PI);
	}
	else if (dir == 'E')
	{
		rotateVetor(&engine->dir, PI/2);
		rotateVetor(&engine->planeCamera, PI/2);
	}
	else if (dir == 'W')
	{
		rotateVetor(&engine->dir, -PI/2);
		rotateVetor(&engine->planeCamera, -PI/2);
	}
}

void	game_settings(t_cub_data *data)
{
	init_vetors(data->engine, data->map_info);
	set_direction(data->engine, data->map_info);
}
