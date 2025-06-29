/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_controls.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 13:27:31 by flima             #+#    #+#             */
/*   Updated: 2025/06/29 14:20:57 by flima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

bool is_move_free(char **map, t_collision *collision, double x, double y)
{
	int map_x = (int)x;
	int map_y = (int)y;

	(void)collision;
	for (int offset_y = -1; offset_y <= 1; offset_y++)
	{
		for (int offset_x = -1; offset_x <= 1; offset_x++)
		{
			int neighbor_x = map_x + offset_x;
			int neighbor_y = map_y + offset_y;

			// Segurança de acesso ao mapa
			if (neighbor_y < 0 || neighbor_x < 0 || !map[neighbor_y] || !map[neighbor_y][neighbor_x])
				continue;

			if (map[neighbor_y][neighbor_x] == '1')
			{
				double min_x = neighbor_x - HITBOX_RADIUS;
				double max_x = neighbor_x + 1 + HITBOX_RADIUS;
				double min_y = neighbor_y - HITBOX_RADIUS;
				double max_y = neighbor_y + 1 + HITBOX_RADIUS;

				// Checa se o jogador entrou na caixa com folga
				if (x >= min_x && x <= max_x && y >= min_y && y <= max_y)
					return false;
			}
		}
	}
	return true;
}


void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_cub_data	*data;

	data = (t_cub_data *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		status_error_handler(data, SUCCESS);
	if (keydata.key == MLX_KEY_LEFT && (keydata.action = MLX_PRESS || keydata.action == MLX_REPEAT))
		rotate_player(data->engine, -ROTATION_SPEED);
	else if (keydata.key == MLX_KEY_RIGHT && (keydata.action = MLX_PRESS || keydata.action == MLX_REPEAT))
		rotate_player(data->engine, ROTATION_SPEED);
	else if (keydata.key == MLX_KEY_W && (keydata.action = MLX_PRESS || keydata.action == MLX_REPEAT))
		move_forward(data->engine);
	else if (keydata.key == MLX_KEY_S && (keydata.action = MLX_PRESS || keydata.action == MLX_REPEAT))
		move_backward(data->engine);
	else if (keydata.key == MLX_KEY_A && (keydata.action = MLX_PRESS || keydata.action == MLX_REPEAT))
		move_left(data->engine);
	else if (keydata.key == MLX_KEY_D && (keydata.action = MLX_PRESS || keydata.action == MLX_REPEAT))
		move_right(data->engine);
	else if (keydata.key == MLX_KEY_M && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
	{
		if (data->show_map == true)
			data->show_map = false;
		else
			data->show_map = true;
	}
	//add the cross handler
}
